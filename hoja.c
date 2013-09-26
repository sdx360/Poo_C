
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
float hoja[5][5];
int fila [2]={0,5};
int columna [2]={0,5};
void print_hoja(){
	int i,k;
	printf("\t\t A\t B\t C\t D\t E\n");
	for (i = 1; i <=5; ++i)
	{
		printf("\t%d",i);
		for (k = 0; k < 5; ++k)
		{
			printf("\t%.2f", hoja[i-1][k]);
		}
		printf("\n");
	}

}
float procesar(int opc,int flag_p,int number1){
	int i,k;
	float resultado;
	printf("\t%d%s", opc,"\n");
	switch(opc){
		case 5:
			
				for (i = fila[0]; i <fila[1]; ++i)
				{
					
					for (k = columna[0]; k < columna[1]; ++k)
					{
						resultado+=hoja[i][k];
					}
					
				}
				return resultado;
			
		
			break;
		case 6:
			break;
		case 8:
				if(flag_p==1){
					hoja[0][0]=number1;
				}
				else{
					for (i = fila[0]; i <fila[1]; ++i)
					{
					
						for (k = columna[0]; k < columna[1]; ++k)
						{
							hoja[i][k]=number1;
						}
					
					}
				}
				
				return resultado;
<<<<<<< HEAD

			break;
		case 11:
			break;
		default:
		printf("Operacion no valida \n");
	}

	return 0;

=======

			break;
		case 11:
			break;
		default:
		printf("Operacion no valida \n");
	}

	return 0;

>>>>>>> 1aceadc1c42710d1d573561c244f73fe833272c2
}

int main (int argc, char** argv){
	int flag,i,k,flag_p=0;
	char operacion[50];
	
	
	char temp[ 2 ]; 
 	system("clear");
 	do
 	{
 		flag=0;
 		flag_p=-1;
 		float number1=0;
 		char aux[20]="";
 		char aux2[20]="";
 		print_hoja();
 		printf("Elegir opcion \tINSERTAR  BORRAR  SUMAR  MULTIPLICAR\n");
 		printf(">> ");
 		fgets(operacion,50,stdin);
 		operacion[strlen(operacion)-1]='\0';
 		printf("%s %s", operacion,"\n");


 		for (i = 0; i < strlen(operacion); ++i)
 		{

 			if(isalpha(operacion[i])!=0&&flag==0){
 					temp[ 0 ] = operacion[i]; 
					temp[ 1 ] = '\0'; 
 					strcat(aux,temp);

 				
 			}
 			else if(strncmp(aux,"sumar",strlen(aux))==0||strncmp(aux,"multiplicar",strlen(aux))==0||strncmp(aux,"borrar",strlen(aux))==0||strncmp(aux,"insertar",strlen(aux))==0)
 			{

 				
 				
 				if(operacion[i]==')'&&(flag==4||flag==2)){
	 				if (((strncmp(aux,"sumar",strlen(aux))==0)||strncmp(aux,"multiplicar",strlen(aux))==0)&&flag!=2)
	 				{
	 					if(flag_p==1){
	 						flag=5;
	 					}
	 					else{
	 						flag=-1;
	 						printf("Sintaxis Erronea \n");
	 						break;
	 						
	 					}
	 				}
	 				else{
	 					flag=5;
	 				}
	 				
	 				
 				}
 				else if(operacion[i]=='('){
 				flag=2;
 				}
 				else if(flag<5)
 				{
 					
 					if(isdigit(operacion[i])!=0){
 						temp[ 0 ] = operacion[i]; 
						temp[ 1 ] = '\0'; 
 						int sum=atoi(temp);
 						if(sum<=5){
 							fila[flag_p]=sum-1;
 							flag=4;
 						}
 						else{
 							printf("Fuera de rango numerico \n");
 							flag=-1;
 						}
 						
 					}
 					else if(operacion[i]==':'&&flag==4){
 						flag_p=1;
 						
 					}
 					else{
 						switch(operacion[i]){
 						case 'A':
 							flag_p=0;
 							columna[flag_p]=0;
 							flag=3;
 						break;
 						case 'B':
 							flag_p=0;
 							columna[flag_p]=1;
 							flag=3;
 							
 						break;
 						case 'C':
 							flag_p=0;
 							columna[flag_p]=2;
 							flag=3;
 						break;
 						case 'D':
 							flag_p=0;
 							columna[flag_p]=3;
 							flag=3;
 						break;
 						case 'E':
 							flag_p=0;
 							columna[flag_p]=4;
 							flag=3;
 						break;
 						default:
 							printf("Fuera de rango \n");
 							flag=-1;
 						}
 					}
 					
 					
 				}
 				else{
 					
	 				if(operacion[i]==';')
	 				{
	 					//printf("Lectura completada %c%s", operacion[i],"\n");
	 					flag=7;	
	 				}
	 				else if(operacion[i]==' '&&flag==5)
	 				{
	 					
	 					
	 					for (k = i; k <strlen(operacion)-1; ++k)
	 					{
	 						temp[ 0 ] = operacion[k]; 
							temp[ 1 ] = '\0'; 
 							strcat(aux2,temp);
 							i=k;
	 					}
	 					printf("%.s", aux2);
	 					number1=atof(aux2);
	 					if(number1!=0){
	 						printf("%.2f", number1);
	 						flag=6;
	 					}
	 					else{
	 						printf("Sintaxis Erronea\n");
	 						flag=-1;
	 					}


	 					
	 				}
	 				else{
	 					printf("Sintaxis Erronea\n");
	 					flag=-1;
	 				}
	 				
	 				
 				
 				}
 			}

 		}
 		if(flag==0){printf("Operacion no valida \n");}
 		
 		if(flag==7){
 			procesar(strlen(aux),flag_p,number1);
 		}


 	} while (flag!=-2);
 	
  return 0;
} 
