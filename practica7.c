#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
	char nombre[80];
	char carrera[3];
	char categoria[4];
	float salario;
	int suta;

}maestros;


int main(int argc, char const *argv[])
{
	int flag=0;
	maestros NuevoMaestro,TC[10],HL[10];

	do{
		printf(" \n" );
		scanf("%[^\n]",NuevoMaestro.nombre);



	}while(flag==0);

	return 0;
}