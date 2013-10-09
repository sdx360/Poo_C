# include <stdio.h>
# include <stdlib.h>
#include <string.h>
#include <ctype.h>

int miebros[4];

void error(){
	printf("\nError! La sintaxis es \"./Castores -e1 nombre1 aportación1 nombre2 aportacion2 [nombre3 aportacion3] -e2 ..\"\n\n" );

}
int nombre(char nomb[]){

	int k;
	for (k = 0; k <strlen(nomb); k++)
	{	 						
		if(isalpha((unsigned char)nomb[k])==0)
		{
			return 0;
		}
		
	}
	return 1;
}

float decimal(char num[]){
	char temp[2];
	int k;
	char aux2[20];
	int cont=0,cont2=0;
	float number1=0;
	
	for (k = 0; k <strlen(num); k++)
	{	 						
		if(isdigit((unsigned char)num[k])!=0||num[k]=='.'||num[k]=='-')
		{
			temp[ 0 ] = num[k]; 			
			temp[ 1 ] = '\0'; 
			strcat(aux2,temp);
			
			if(num[k]=='.'){
				cont++;
			}
			if(num[k]=='-'){
				cont2++;
			}
			if(cont>=2||cont2>=2){

			return -1;
			}
		}
		else{
			 return -1;					
		}
		
	}

	number1=atof(aux2);
	return number1;

}
int comprobar_e(char *equipos[],char *argv[],int c){
	int i,j=0;
	float numero=0,name;
	for (i = 1; i <c ; ++i)
		{
			int flag=0,cont=0;
			
			if(strncmp(argv[i],equipos[j],strlen(argv[i]))==0)
			{

				i++;
				do{
					if(i<c){

						name=nombre(argv[i]);
						numero=decimal(argv[i+1]);

						if(name!=0 && numero!=-1){

							i+=2;
							cont++;
							
						}
						else{
							if(cont!=2&&cont!=3)
							{
								return 0;
							}
							i--;
							miebros[j]=cont;
							j++;
							flag=-1;
						}
					}
					else{
						if(cont!=2&&cont!=3)
							{
								return 0;
							}
						flag=-1;
						miebros[j]=cont;
					}
					
				}while(flag!=-1);
				
			}
			else{
				return 0;
			}
		}
		return 1;
}

float **reservar_matriz(int rows, int cols){
	float **matriz;
	int i;
	matriz=(float**) malloc(rows*sizeof(float*));

	for (i = 0; i < rows; ++i)
	{
		matriz[i]=(float*)malloc(cols*sizeof(float));
	}
return matriz;
}

int main(int argc, char *argv[])
{
	int i;
	char *equipos[5]={"-e1","-e2","-e3","-e4"};

	system("clear");
	if( argc < 21 || argc >29 )
	{
			error();	
	}
		if(comprobar_e(equipos,argv,argc)!=0){
			for (i = 0; i < 4; ++i)
			{
				printf("%d\n", miebros[i]);
			}


		}
		else{
			error();	
		}

	return 0;
}