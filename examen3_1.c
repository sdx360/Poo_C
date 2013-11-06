#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <regex.h>
typedef struct 
{
	int *id;
}dato;
dato *datos;
dato *res(){
	dato *datos;
	return datos=(dato*)malloc(2*sizeof(dato));
	
}
char* tok(char* cadena, char token[])
{
	char *t1;
	char *nuevo;
	int longitud;
	longitud = strlen(cadena);
	nuevo = (char*)malloc(sizeof(char) * longitud);

	for ( t1 = strtok(cadena,token);
	      t1 != NULL;
	      t1 = strtok(NULL, token) )
		  printf("------------%s\n",t1);

	
	return nuevo;
}

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

void imprimir(){

	printf("%d%d%d\n", datos[0].id[0],datos[0].id[1],datos[0].id[2]);
	printf("%d%d%d\n", datos[1].id[0],datos[1].id[1],datos[1].id[2]);	
}

void tokenizer(char s1[]){
		char *t1;
		//char buffer[20]="";
		//printf("%s\n",  strcpy(buffer, &s1[5]));
		/*for ( t1 = strtok(s1,"\t");
	      t1 != NULL;
	      t1 = strtok(NULL, "\t") )
		  printf("------------%s\n",t1);*/
		t1 = strtok(s1,"\t");
		 printf("------------%s\n",t1);
		t1 = strtok(NULL,"\t");
		 printf("------------%s\n",t1);
		t1 = strtok(NULL,"\t");
		 printf("------------%s\n",t1);
	
}

int main(int argc, char const *argv[])
{
	//dato *datos;
			//printf("%s\n", strtok(argv[2],"."));
		//printf("%s\n", strtok(argv[3],"."));
	datos=res();
	datos[0].id=(int*)malloc(2*sizeof(int));
	datos[0].id[0]=1;
	datos[0].id[1]=2;
	datos[0].id[2]=3;
	datos[1].id=(int*)malloc(2*sizeof(int));
	datos[1].id[0]=1;
	datos[1].id[1]=2;
	datos[1].id[2]=3;

	imprimir();
	if(evaluar("^[-+]?([0-9]+)$","23")==0){
			printf("match\n" );
			}
	return 0;
}