#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <regex.h>

typedef struct{
	int coor_x;
	int coor_y;
	float costo_gas;
}DatosUbicacion;

typedef struct{
	char codigo[15];
	char tipo;
	float precio;
	DatosUbicacion ubicacion;
}DatosPropiedad;
	
typedef struct{
	char codigo[5];
	char nombre[80];
	DatosUbicacion ubicacion;
}DatosAgenteV;
DatosAgenteV *agente;

int evaluar(char a[],char b[]){
	regex_t regex;
	int re;

	re=regcomp(&regex,a,REG_EXTENDED);
	return re=regexec(&regex, b, 0, NULL, 0);

}
char* substr(char* cadena, int comienzo, int longitud)
{
	if (longitud == 0) longitud = strlen(cadena)-comienzo-1;
	
	char *nuevo = (char*)malloc(sizeof(char) * longitud);
	
	strncpy(nuevo, cadena + comienzo, longitud);
	
	return nuevo;
}

void tokenizer(char s1[],int pos){
		char *t1;
		//char buffer[20]="";
		//printf("%s\n",  strcpy(buffer, &s1[5]));
		/*for ( t1 = strtok(s1,"\t");
	      t1 != NULL;
	      t1 = strtok(NULL, "\t") )
		  printf("------------%s\n",t1);*/
		t1 = strtok(s1,"\t");
			agente[pos].ubicacion.coor_x=atoi(t1);
		t1 = strtok(NULL,"\t");
		 	agente[pos].ubicacion.coor_y=atoi(t1);
		t1 = strtok(NULL,"\t");
		 	agente[pos].ubicacion.costo_gas=atof(t1);
	
}
double CurrentTime(){
  struct timeval tv;
  gettimeofday(&tv, 0);
  return (tv.tv_sec + tv.tv_usec/1000000.0);
}
void error(){
	printf("Error al abrir el archivo\n");
	exit(-1);
}
 void memory(int row){
	agente=(DatosAgenteV*) malloc(row*sizeof(DatosAgenteV));
	if(!agente){
		fprintf(stderr,"Error in Memory Matrix!\n"); 
		exit(-1);
		}
 }
void guardar_archivo(char a[],char b[]){
 	FILE *pt;
 	if((pt=fopen(a,"w"))==NULL){
 		error();
 	}
 	fprintf(pt, "%s\n", b);
 	fclose(pt);
}
void llenar(FILE *archivo1,char texto[],char opc){
int pos=0,total=0;
	fscanf(archivo1,"%[^\n]\n",texto);
		if(evaluar("^[0-9]+",texto)!=0){error();}
		
		
		printf("%s\n", texto);
		total=atoi(texto);
		memory(total);

		while(!feof(archivo1)&&pos<total){

			fscanf(archivo1,"%[^\n]\n",texto);
			strcpy(agente[pos].codigo, texto);
			fscanf(archivo1,"%[^\n]\n",texto);
			strcpy(agente[pos].nombre, texto);
			fscanf(archivo1,"%[^\n]\n",texto);
			tokenizer(texto,pos);
			//printf("1.-%s\n2.-%s\n3.-%d\t%d\t%.2f\n", agente[pos].codigo,agente[pos].nombre,agente[pos].ubicacion.coor_x,agente[pos].ubicacion.coor_y,agente[pos].ubicacion.costo_gas);
			pos++;
		};
}
int main(int argc, char *argv[])
{
	system("cls");
	double start, end,seconds;
	start=CurrentTime();
	FILE *archivo1=NULL,*archivo2=NULL;
	char texto[200],nombre[200];

	if(argc==4&&strcmp(argv[1],"-FILE")==0)
	{
		if(((archivo1=fopen(argv[2],"r"))==NULL)||((archivo2=fopen(argv[3],"r"))==NULL)){
			error();
		}
		printf("%s\n",argv[2]);
		
		llenar(archivo1,texto,'p');	
		llenar(archivo2,texto,'v');	
		//printf("%s\n", texto);
		//tokenizer();
		sprintf( nombre, "%s_%s.txt", strtok(argv[2],"."), strtok(argv[3],"."));
		printf("%s\n", nombre);
		guardar_archivo(nombre,texto);
		fclose(archivo1);
		

			if(evaluar("^[-+]?([0-9]+)$","23")==0){
			printf("match\n" );
			}


	}
	else{error();}

	end=CurrentTime();
	seconds=(end-start);
	printf("\n\nSegundos: %.5f\tReloj de computadora:%.10f\n",seconds,seconds/(double)CLOCKS_PER_SEC);
   return 0;
}