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
void error(){
	printf("Error al abrir el archivo\n");
	exit(-1);
}
void guardar_archivo(){
 	FILE *pt;
 	if((pt=fopen("StatisticsMainHaus.out","a"))==NULL){
 		error();
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
int main(int argc, char const *argv[])
{
	char texto[200],nombre[200];
	double start, end,seconds;
	start=CurrentTime();
	char *t1,*t2,*t3;
	int i; 
	system("clear");
	FILE *archivo1=NULL,*archivo2=NULL;
	if(argc==3&&strcmp(argv[1],"-FILE")==0){
		if((archivo1=fopen(argv[2],"r"))==NULL){
			error();
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
			}
			t3=strtok(t1,".");
			sprintf(nombre, "%s",t3);
			t3 = strtok(t2,".");
			sprintf(nombre, "%s_%s.out",nombre,t3);
			if((archivo2=fopen(nombre,"r"))==NULL){
			error();
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

	}else{error();}

	end=CurrentTime();
	seconds=(end-start);
	printf("Segundos: %.5f\tReloj de computadora:%.10f\n",seconds,seconds/(double)CLOCKS_PER_SEC);
	return 0;
}