#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

typedef struct 
{
	int *id;
}dato;
dato *datos;
dato *res(){
	dato *datos;
	return datos=(dato*)malloc(2*sizeof(dato));
	
}
void imprimir(){

	printf("%d%d%d\n", datos[0].id[0],datos[0].id[1],datos[0].id[2]);
	printf("%d%d%d\n", datos[1].id[0],datos[1].id[1],datos[1].id[2]);	
}

int main(int argc, char const *argv[])
{
	//dato *datos;
	
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
	return 0;
}