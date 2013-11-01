#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

typedef struct 
{
	char nombre[80];
	char carrera[3];
	char categoria[4];
	float salario;
	int suta;

}maestros;

int evaluar(char a[], char b[]){
	regex_t regex;
	int r;
	r=regcomp(&regex,a,REG_EXTENDED);
	return r=regexec(&regex,b,0,NULL,0);

}
int main(int argc, char const *argv[])
{
	int i,pos=0,pos2=0;
	char aux [80];
	maestros NuevoMaestro,TC[10],HL[10];

	for (i = 0; i <3; ++i)
	{
		printf("Introduce el nombre del maestro\n" );
		scanf("%[^\n][\n]*",NuevoMaestro.nombre);
		
		printf("\nIntroduce la carrera del maestro------CP, LA, LI, LCE\n");
		scanf("%s", NuevoMaestro.carrera);
		if(evaluar("^(CP)|(LA)|(LI)|(LCE)$",NuevoMaestro.carrera)!=0){break;}
		printf("\nIntroduce la categoria del maestro---- TC o HL\n");
		scanf("%s", NuevoMaestro.categoria);
		if(evaluar("^(TC)|(HL)$",NuevoMaestro.categoria)!=0){break;}
		printf("\nIntroduce el salario del maestro\n");
		scanf("%s", aux);
		if(evaluar("^[-+]?([0-9]+).?[0-9]*$",aux)!=0){break;}
		NuevoMaestro.salario=atof(aux);
		//fscanf( stdin, "%f", &uevoMaestro.salario );
		getchar();

		if(strcmp(NuevoMaestro.categoria,"TC")==0){
			TC[pos]=NuevoMaestro;pos++;}
		else{
			HL[pos2]=NuevoMaestro;pos2++;
		}

	}
	for (i = 0; i < pos; ++i)
	{
		printf("%s\t%s\t%s\t%.2f\n", TC[i].nombre,TC[i].carrera,TC[i].categoria,TC[i].salario);
	}

	for (i = 0; i < pos2; ++i)
	{
		printf("%s\t%s\t%s\t%.2f\n", HL[i].nombre,HL[i].carrera,HL[i].categoria,HL[i].salario);
	}

	return 0;
}