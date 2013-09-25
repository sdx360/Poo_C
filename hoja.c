

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
float hoja[5][5];

void print_hoja(){
	int i,k;
	printf("\t\t A\t B\t C\t D\t E\n");
	for (i = 1; i <=5; ++i)
	{
		printf("\t%d",i);
		for (k = 0; k < 5; ++k)
		{
			printf("\t%.2f", hoja[i][k]);
		}
		printf("\n");
	}

}


int main (int argc, char** argv){
	int flag=0,i;
	char operacion[50];

	char aux[10]="";
	char temp[ 2 ]; 
 	system("clear");
 	do
 	{
 		print_hoja();
 		printf("Elegir opcion \tINSERTAR  BORRAR  SUMAR  MULTIPLICAR\n");
 		printf(">> ");
 		scanf("%s", operacion);
 		printf("%s %s", operacion,"\n");


 		for (i = 0; i < strlen(operacion); ++i)
 		{
 			if(isalpha(operacion[i])!=0&&flag==0){
 					temp[ 0 ] = operacion[i]; 
					temp[ 1 ] = '\0'; 
 					strcat(aux,temp);

 					//printf("%s%s", aux,"\n");
 			}
 			else if(strncmp(aux,"suma",4)==0||strncmp(aux,"multiplicar",11)==0||strncmp(aux,"borrar",6)==0||strncmp(aux,"insertar",8)==0){
 			
 				//printf("%c%s", operacion[i],"\n");
 				if(operacion[i]==')'&&flag==4){
	 				
	 				//printf("cierrre %c%s", operacion[i],"\n");
	 				flag=5;
 				}
 				else if(operacion[i]=='('){
 					
 				//printf("Apertura %c%s", operacion[i],"\n");
 				flag=2;
 				}
 				else if(flag<5){
 					
 					if(isdigit(operacion[i])!=0){
 						temp[ 0 ] = operacion[i]; 
						temp[ 1 ] = '\0'; 
 						int sum=atoi(temp);
 						if(sum<=5){
 							
 							flag=4;
 						}
 						else{
 							flag=-1;
 						}
 						
 					}
 					else if(operacion[i]==':'&&flag==4){
 						
 						
 					}
 					else{
 						switch(operacion[i]){
 						case 'A':
 							flag=3;
 						break;
 						case 'B':
 							flag=3;
 						break;
 						case 'C':
 							flag=3;
 						break;
 						case 'D':
 							flag=3;
 						break;
 						case 'E':
 							flag=3;
 						break;
 						default:
 							flag=-1;
 						}
 					}
 					
 					
 				}
 				else{
 					
	 				
	 				printf("Lectura completada %c%s", operacion[i],"\n");
	 				
 				
 				}
 			}
 			
 			
 			
 		}
		
		
 	} while (flag<=10);
 	
  return 0;
} 
