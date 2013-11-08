
/*
Dan Williams Robledo Cruz
Practica #4
Asignaciones Eficientes en Main-Haus
El establecimiento Main Haus de bienes raices quiere una forma para obtener un reparto mas equitativo en la asignacion de sus agentes de ventas
con el numero de propiedades que cuenta para minimizar los costos en una determinada instancia
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
typedef struct 
{
	float min;
	float max;
	float med;
}estadistica;
estadistica salida;
float vector[31];
void error(int opc){
	switch(opc){
		case 1:printf("Error al abrir el archivo\n");
		break;
		case 2:printf("Sintaxis incorrecta\n");
		break;
		case 3:printf("tiene que ser un archivo .txt\n");
		break;
	}
	
	exit(-1);
}
void guardar_archivo(){
 	FILE *pt;
 	if((pt=fopen("StatisticsMainHaus.out","a"))==NULL){
 		error(1);
 	}
 	fprintf(pt, "%.3f\t%.3f\t%.3f\n", salida.min,salida.max,salida.med);
 	fclose(pt);
}
double CurrentTime(){
  struct timeval tv;
  gettimeofday(&tv, 0);
  return (tv.tv_sec + tv.tv_usec/1000000.0);
}
void calculo(){
	int i;
	float media;
	salida.min=vector[0];
	salida.max=vector[0];
	media=vector[0];
	for (i = 1; i < 31; ++i)
	{
		if(vector[i]>salida.max){
			salida.max=vector[i];
		}
		else if(vector[i]<salida.min){
			salida.min=vector[i];
		}
		media+=vector[i];
	}
	salida.med=media/31;
}
void anilizaerror(){
FILE *pt=NULL;
if((pt=fopen("Error.txt","r"))!=NULL){
	fclose(pt);
			exit(-1);
		}
}
int main(int argc, char const *argv[])
{
	char texto[200],nombre[200];
	double start, end,seconds;
	start=CurrentTime();
	char *t1,*t2,*t3;
	char *resp;
	int i; 
	system("clear");
	FILE *archivo1=NULL,*archivo2=NULL;
	resp=strstr( argv[2], ".txt" );
	if(resp==NULL){
   		error(3);
   	}
	if(argc==3&&strcmp(argv[1],"-FILE")==0){
		if((archivo1=fopen(argv[2],"r"))==NULL){
			error(1);
		}
		do{
		fscanf(archivo1,"%[^\n\r]\n|\r",texto);
		
			
			t1=strtok(texto,"\t");
			t2=strtok(NULL,"\t");
		sprintf(nombre, "./MainHaus -FILES %s %s",t1,t2);
		printf("%s-%s\n", t1,t2);
			for (i = 0; i < 31; ++i)
			{
				system(nombre);
				anilizaerror();
			}
			
			t3=strtok(t1,".");
			sprintf(nombre, "%s",t3);
			t3 = strtok(t2,".");
			sprintf(nombre, "%s_%s.out",nombre,t3);
			if((archivo2=fopen(nombre,"r"))==NULL){
			error(1);
			}
			for (i = 0; i <31; ++i)
			{
				fscanf(archivo2,"%[^\n]\n",texto);
				vector[i]=atof(strtok(texto,"\t"));
			}
			calculo();
			guardar_archivo();	
		 	printf("\n");
			

		}while(!feof(archivo1));		
		fclose(archivo1);

	}else{error(2);}

	end=CurrentTime();
	seconds=(end-start);
	printf("Segundos: %.5f\tReloj de computadora:%.10f\n",seconds,seconds/(double)CLOCKS_PER_SEC);
	return 0;
}