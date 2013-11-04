//Examen 2: Matrioskas 
//Dan Williams Robledo Cruz
//Programa que se encarga de ordenar las Matrioskas en la forma lo mas rapida posible utilizando estructuras
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <regex.h>

typedef struct
{
	int *tamaño;
	char *codigo;
}doll;

int evaluar(char a[], char b[]){
	regex_t regex;
	int re;
	re=regcomp(&regex,a,REG_EXTENDED);
	return re=regexec(&regex,b,0,NULL,0);

}

void reservar_matriz(int rows){
	
	
	tamaño=(int*) malloc(rows*sizeof(int));
	if(!tamaño){
		fprintf(stderr,"Error in Memory Matrix!\n"); 
		exit(-1);
		}
	

}

void error(){
	printf("Error\n");
	exit(-1);
}

double CurrentTime(){
  struct timeval tv;
  gettimeofday(&tv, 0);
  return (tv.tv_sec + tv.tv_usec/1000000.0);
}

void guardar_archivo(char a[],char b[]){
 	FILE *pt;
 	if((pt=fopen(a,"w"))==NULL){
 		error();
 	}
 	fprintf(pt, "%s\n", b);
 	fclose(pt);
}

int main(int argc, char const *argv[])
{
	
	system("clear");
	FILE *archivo;
	int pos=0;
	double start, end,seconds;
	start=CurrentTime();
	char buffer[50],nombre[50],texto[50];

	if(argc==3&&strcmp(argv[1],"-FILE")==0)
	{
		if(((archivo=fopen(argv[2],"r"))==NULL)){
			error();
		}
		printf("%s\n",argv[2]);
		
		
		while(!feof(archivo)){
			fscanf(archivo,"%[^\n]\n",texto);
			if(evaluar("^[0-9](\t([0-9] )*)?",texto)!=0){error();}
			if(strcmp(texto,"0")==0){break;}
			strcpy(buffer, &texto[2]);
			
			
			char *t1;
			pos=0;
			for ( t1 = strtok(buffer," ");
	      	t1 != NULL;
	      	t1 = strtok(NULL, " ") );
			

		};
		fclose(archivo);

		
		sprintf( nombre, "%s.out", strtok(argv[2],"."));
		printf("%s\n", nombre);
		guardar_archivo(nombre,texto);
		

		
	}
	else{error();}
	end=CurrentTime();
	seconds=(end-start);
	printf("\n\nSegundos: %.5f\tReloj de computadora:%.10f\n",seconds,seconds/(double)CLOCKS_PER_SEC);
	



	return 0;
}