# include <stdio.h>
# include <stdlib.h>
#include <string.h>
#include <ctype.h>

int miebros[4];
float **m_aportacion;
char **m_nombres[4];
int v[4]={1,1,1,1};


void utilidades(){
	int i;
	float total=0;
	//printf("[%d]\t[%d]\t[%d]\t[%d]\n",v[0],v[1],v[2],v[3]);
	for (i = 0; i < 4; ++i)
	{
		total+=m_aportacion[i][v[i]-1];
	}
	printf("Utilidad minima: %.2f\n", total);
	printf("%s[%.2f]\t%s[%.2f]\t%s[%.2f]\t%s[%.2f]\n\n",m_nombres[0][v[0]-1],m_aportacion[0][v[0]-1],m_nombres[1][v[1]-1],m_aportacion[1][v[1]-1],m_nombres[2][v[2]-1],m_aportacion[2][v[2]-1],m_nombres[3][v[3]-1],m_aportacion[3][v[3]-1]);
}

int combinaciones(int aux){
	aux++;
	int i;
	for (i = 0; i < miebros[aux]; ++i)
	{
		v[aux]=i+1;
		if(aux<(sizeof(miebros) / sizeof(miebros[0])-1)){
			//printf("------------------------------------\n");
			combinaciones(aux);
		}
		else{
			
			utilidades();
		}
	}
return 0;
}

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

int decimal(char num[]){
	char temp[2];
	int k;
	char aux2[20];
	int cont=0,cont2=0;
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

			return 0;
			}
		}
		else{
			 return 0;					
		}
	}
	return 1;
}
int comprobar_e(char *equipos[],char *argv[],int c){
	int i,j=0;
	int numero=0,name;
	for (i = 1; i <c ; ++i)
		{
			int flag=0,cont=0;
			
			if(strncmp(argv[i],equipos[j],strlen(argv[i]))==0)
			{
				i++;
				do{
					if(i+1<c){

						name=nombre(argv[i]);
						numero=decimal(argv[i+1]);
						if(name!=0 && numero!=0){

							i+=2;
							cont++;
							
						}
						else{
							if((cont!=2&&cont!=3)||i+1==c-1)
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
						if((cont!=2&&cont!=3)||i==c-1)
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

void reservar_matriz(int rows){
	
	int i;
	m_aportacion=(float**) malloc(rows*sizeof(float*));
	for (i = 0; i < rows; ++i)
	{

		m_aportacion[i]=(float*)malloc(miebros[i]*sizeof(float));
		m_nombres[i]=(char**) malloc(miebros[i]*sizeof(char*));
		if(!m_aportacion[i]){
		fprintf(stderr,"Error in Memory Matrix!\n"); 
		exit(-1);
		}

	}

}
void llenar_matriz(char *argv[]){
	int i,j,pos=3;
	for (i = 0; i < sizeof(miebros) / sizeof(miebros[0]); ++i)
	{
		for (j = 0; j < miebros[i]; ++j)
		{
			m_aportacion[i][j]=atof(argv[pos]);
			m_nombres[i][j]=argv[pos-1];
			pos+=2;
		}
		pos++;
	}

}

int main(int argc, char *argv[])
{
	int i,j,aux=-1;
	char *equipos[5]={"-e1","-e2","-e3","-e4"};
	

	system("clear");
	if( argc < 21 || argc >29 )
	{
			error();	
	}
	else{
		if(comprobar_e(equipos,argv,argc)!=0){
			for (i = 0; i < 4; ++i)
			{
				//printf("%d\n", miebros[i]);
			}
			printf("\n");
			reservar_matriz(4);
		
			llenar_matriz(argv);
			for (i = 0; i < 4; ++i)
			{
				for (j = 0; j < miebros[i]; ++j)
				{
					printf("%s (%.2f)\t",m_nombres[i][j],m_aportacion[i][j]);
				}
				printf("\n");
			}
			printf("\n\n");
			combinaciones(aux);

		}
		else{
			error();	
		}

	}
	return 0;
}