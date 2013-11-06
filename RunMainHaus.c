#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(){
	printf("Error al abrir el archivo\n");
	exit(-1);
}
int main(int argc, char const *argv[])
{
	char texto[200],nombre[200];
	char *t1,*t2;
	int i; 
	system("clear");
	FILE *archivo1=NULL,*archivo2=NULL;
	if(argc==3&&strcmp(argv[1],"-FILE")==0){
		if((archivo1=fopen(argv[2],"r"))==NULL){
			error();
		}
		do{
		fscanf(archivo1,"%[^\n]\n",texto);
		sprintf(nombre, "./P4 -FILES %s",texto);
			for (i = 0; i < 31; ++i)
			{
				system(nombre);
			}
			t1 = strtok(texto,"\t");
			sprintf(nombre, "%s",t1);
			t1 = strtok(NULL,"\t");
			t2=strtok(nombre,".");
			sprintf(nombre, "%s",t2);
			t2 = strtok(t1,".");
			sprintf(nombre, "%s_%s.out",nombre,t2);
			if((archivo2=fopen(nombre,"r"))==NULL){
			error();
			}
			do{
				fscanf(archivo2,"%[^\n]\n",texto);
				//printf("%s\n",texto);
			}while(!feof(archivo2));
		 	printf("\n\n");
			
			
		}while(!feof(archivo1));		
		fclose(archivo1);

	}else{error();}
	return 0;
}