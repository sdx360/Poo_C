#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int numeros[4];
int final[4];
int s=0,menor=-1,flag=0;
void element_swap(size_t a, size_t b )
{
	int temp = numeros[ a ];
	numeros[ a ] = numeros[ b ];
	numeros[ b ] = temp;
}
int comprobar (){
	int i,j;
	for (i = 0; i <4; i++)
	{
		for (j = 0; j <4; j++)
		{
			if(j!=i){
				if(numeros[i]==numeros[j]){
					return 0;
				}
				
			}

		}
		
	}
	
	return 1;
}
void imprimir(){
	int i,num1,num2,num3,num4,abso;
	s++;
	printf("S%d:\n",s );
	for (i = 0; i < 4; i++)
	{
		printf("%d\t", numeros[i] );
		if(i==1||i==3){
			printf("[%d]\n",numeros[i-1]+numeros[i]);}
		
		
	}
	num1=numeros[0]+numeros[1];
	num2=numeros[0]+numeros[2];
	num3=numeros[3]+numeros[2];
	num4=numeros[3]+numeros[1];
	abso=(abs(num1-num2)+abs(num3-num4));
	printf("[%d]\t[%d]\t<%d>\n\n",num2,num4,abso);
	
	if(menor==-1||abso<menor){
		//printf("S%d:\n",s );
		menor=abso;
		flag=s;
		for (i = 0; i < 4; i++)
		{
			final[i]=numeros[i];
		}
	}
}
void imp_final(){
	int i,num1,num2,num3,num4,abso;
	s++;
	printf("S%d:\n",s );
	for (i = 0; i < 4; i++)
	{
		printf("%d\t", final[i] );
		if(i==1||i==3){
			printf("[%d]\n",final[i-1]+final[i]);}
		
		
	}
	num1=final[0]+final[1];
	num2=final[0]+final[2];
	num3=final[3]+final[2];
	num4=final[3]+final[1];
	abso=(abs(num1-num2)+abs(num3-num4));
	printf("[%d]\t[%d]\t<%d>\n\n",num2,num4,abso);
	
	
}

int main (int argc, char *argv[])
{
	//printf("\n%s",argv[3]);
	system("clear");
	if( argc < 6  )
	{
		printf("\nError la entrada debe ser: ./examen -N n1 n2 n3 n4  Donde n=[1-9]\n\n" );
		
	}
	else if(strncmp(argv[1],"-N",strlen(argv[1]))!=0){ 
		printf("\nError la entrada debe ser: ./examen -N n1 n2 n3 n4  Donde n=[1-9]\n\n" );
	}
	else{

		int i;
		for (i = 2; i <6; i++)
		{
			//printf("\n%s",argv[i]);
			if(isdigit(*argv[i])!=0&&atoi(argv[i])<10&&atoi(argv[i])>0){
				
				numeros[i-2]=atoi(argv[i]);

				//printf("\n%d",numeros[i-2]);
			}
			else{
				printf("\nError la entrada debe ser: ./examen -N n1 n2 n3 n4 Donde n=[1-9]\n\n");
				return 0;
			}	
		}
		if(comprobar()==1){
				 int opciones=1;
				 int len= sizeof(numeros) / sizeof(numeros[0]);
				for( i = 1; i <= len ; i++ )
				{
					opciones *= i;
				}
				printf("Mostrando las %d Opciones:\n", opciones );

				for( i = 0; i < opciones ; i++ )
				{
					
					imprimir();
					element_swap(i % (len-1), len - 1 );
				}
				printf("s* =s%d\n",flag);
				imp_final();
		}
		else{
				printf("\nError la entrada debe ser: ./examen -N n1 n2 n3 n4 Donde n=[1-9]\n\n");
				return 0;
			}
	}

	return 0;
}