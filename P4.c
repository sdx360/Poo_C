#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <regex.h>
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

void tokenizer(){
	char s1[] = "Hola	muchacho grande";
		char *t1,*t2;
		char buffer[20]="";
		printf("%s\n",  strcpy(buffer, &s1[5]));
		for ( t1 = strtok(s1," ");
	      t1 != NULL;
	      t1 = strtok(NULL, " ") )
		printf("%s\n",t1);
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
 
void guardar_archivo(char a[],char b[]){
 	FILE *pt;
 	if((pt=fopen(a,"w"))==NULL){
 		error();
 	}
 	fprintf(pt, "%s\n", b);
 	fclose(pt);
}
int main(int argc, char *argv[])
{
	system("clear");
	double start, end,seconds;
	start=CurrentTime();
	FILE *archivo1,*archivo2;
	char texto[200],nombre[200];

	if(strcmp(argv[1],"-FILE")==0&&argc==4)
	{
		if(((archivo1=fopen(argv[2],"r"))==NULL)&&(archivo2=fopen(argv[2],"r"))){
			error();
		}
		printf("%s\n",argv[2]);
		fscanf(archivo1,"%[^\n]\n",texto);
		if(evaluar("^[0-9]+",texto)!=0){error();}
		atoi(texto);
			printf("%s\n", texto);

		while(!feof(archivo1)){
			fscanf(archivo1,"%[^\n]\n",texto);
			printf("%s\n", texto);

		};
		
		tokenizer();
		//printf("%s\n", strtok(argv[2],"."));
		//printf("%s\n", strtok(argv[3],"."));
		sprintf( nombre, "%s_%s.txt\n", strtok(argv[2],"."), strtok(argv[3],"."));
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