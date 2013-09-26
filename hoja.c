
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
float hoja[5][5];
int fila [2]={0,4};
int columna [2]={0,4};
int opc=0;
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
void procesar(int flag_p,float number1)
{
	int i,k;
	float resultado=0;
	switch(opc)
	{
		case 1:
					if(flag_p==0){
						printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
					}
					else if((columna [0]<columna [1]&&fila[0]==fila[1])||(columna [0]==columna [1]&&fila[0]<fila[1])||flag_p==-1)
					{
						for (i = fila[0]; i <=fila[1]; i++)
						{
						
							for (k = columna[0]; k <=columna[1]; k++)
							{
								resultado+=hoja[i][k];
							}
						}
						printf(">>Resultado -----------------------------------------------------%.2f%s",resultado,"\n\n");
					}
					else
					{
						printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
					}
			break;
		case 2:
				if(flag_p==0){
					hoja[fila[0]][columna[0]]=0;
					print_hoja();
				}
				else if((columna [0]<columna [1]&&fila[0]==fila[1])||(columna [0]==columna [1]&&fila[0]<fila[1])||flag_p==-1)
				{
					for (i = fila[0]; i <=fila[1]; i++)
					{
					
						for (k = columna[0]; k <=columna[1]; k++)
						{
							hoja[i][k]=0;
						}
					}
					print_hoja();
				}
				else
				{
					printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
				}
			break;
		case 3:
				if(flag_p==0){
					hoja[fila[0]][columna[0]]=number1;
					print_hoja();
				}
				else if((columna [0]<columna [1]&&fila[0]==fila[1])||(columna [0]==columna [1]&&fila[0]<fila[1])||flag_p==-1)
				{
					for (i = fila[0]; i <=fila[1]; i++)
					{
					
						for (k = columna[0]; k <=columna[1]; k++)
						{
							hoja[i][k]=number1;
						}
					}
					print_hoja();
				}
				else
				{
					printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
				}
			break;
		case 4:
				resultado=1;
					if(flag_p==0){
						printf("Sintaxis Erronea\n");
					}
					else if((columna [0]<columna [1]&&fila[0]==fila[1])||(columna [0]==columna [1]&&fila[0]<fila[1])||flag_p==-1)
					{

						for (i = fila[0]; i <fila[1]; i++)
						{
						
							for (k = columna[0]; k < columna[1]; k++)
							{
								resultado*=hoja[i][k];
							}
						}
						printf(">>Resultado -----------------------------------------------------%.2f%s",resultado,"\n\n");
					}
					else{
						printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
					}
			break;
		default:
		printf(">>Error #1 -----------------------------------------------------Operacion Invalida\n");
	}
	return ;

}
int operation(char aux[]) {

	if(strncmp(aux,"sumar",strlen(aux))==0&&strncmp(aux,"sumar",5)==0)
	{
		opc=1;
		return 1;
	}
	else if(strncmp(aux,"multiplicar",strlen(aux))==0&&strncmp(aux,"multiplicar",11)==0)
	{
		opc=4;
		return 1;
	}
	else if(strncmp(aux,"borrar",strlen(aux))==0&&strncmp(aux,"borrar",6)==0)
	{
		opc=2;
		return 1;
	}
	else if(strncmp(aux,"insertar",strlen(aux))==0&&strncmp(aux,"insertar",8)==0)
	{
		opc=3;
		return 1;
	}
	else{return 0;}
	} 


int main (int argc, char** argv){
	int flag,i,k,flag_p=0;
	char operacion[50];
	char temp[ 2 ]; 
 	system("clear");
 	print_hoja();
 	printf("Elegir opcion \tINSERTAR  BORRAR  SUMAR  MULTIPLICAR\n");
 	do
 	{
 		flag=0;
 		opc=0;
 		flag_p=0;
 		columna[0]=0;
 		columna[1]=4;
 		fila[0]=0;
 		fila[1]=4;
 		float number1=0;
 		char aux[20]="";
 		char aux2[20]="";
 		printf(">> ");
 		fgets(operacion,50,stdin);
 		operacion[strlen(operacion)-1]='\0';
 		
 		if(strlen(operacion)!=0){
 				for (i = 0; i < strlen(operacion); ++i)
		 		{

		 			if(isalpha((unsigned char)operacion[i])!=0&&flag==0)
		 			{
		 					temp[ 0 ] = operacion[i]; 
							temp[ 1 ] = '\0'; 
		 					strcat(aux,temp);
		 			}
		 			else if(operation(aux)==1)
		 			{
		 				if(operacion[i]==')'&&(flag==4||flag==2))
		 				{
			 				if ((opc==1||opc==4)&&flag!=2)
			 				{
			 					if(flag_p==1){
			 						flag=5;
			 					}
			 					else{
			 						flag=-1;
			 						printf(">>Error #3 -----------------------------------------------------Sintaxis Erronea\n");
			 						break;
			 					}
			 				}
			 				else{
			 					if(flag==2){flag_p=-1;}
			 					flag=5;
			 				}	
		 				}
		 				else if(operacion[i]=='('){
		 					flag=2;
		 				}
		 				else if(flag<5)
		 				{
		 					if(isdigit((unsigned char)operacion[i])!=0){
		 						temp[ 0 ] = operacion[i]; 
								temp[ 1 ] = '\0'; 
		 						int sum=atoi(temp);
		 						if(sum<=5){
		 							fila[flag_p]=sum-1;
		 							flag=4;
		 						}
		 						else{
		 							printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
		 							flag=-1;
		 						}
		 					}
		 					else if(operacion[i]==':'&&flag==4){
		 						flag_p=1;
		 					}
		 					else{
		 						switch(operacion[i]){
			 						case 'A':
			 							columna[flag_p]=0;
			 							flag=3;
			 						break;
			 						case 'B':
			 							columna[flag_p]=1;
			 							flag=3;
			 						break;
			 						case 'C':
			 							columna[flag_p]=2;
			 							flag=3;
			 						break;
			 						case 'D':
			 							columna[flag_p]=3;
			 							flag=3;
			 						break;
			 						case 'E':
			 							columna[flag_p]=4;
			 							flag=3;
			 						break;
			 						default:
			 							printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
			 							flag=-1;
		 						}
		 					}	
		 				}
		 				else{
		 					
			 				if(operacion[i]==';')
			 				{
			 					if(opc==3&&number1==0){
			 						flag=-1;
			 						printf(">>Error #3 -----------------------------------------------------Sintaxis Erronea\n");
			 					}
			 					else{
			 						flag=7;	
			 					}
			 					
			 				}
			 				else if((operacion[i]=='-'||operacion[i]==' '||isdigit((unsigned char)operacion[i])!=0)&&flag==5&&opc==3)
			 				{
			 					int cont=0;
			 					for (k = i; k <strlen(operacion)-1; k++)
			 					{
			 						
		 							if(isdigit((unsigned char)operacion[k])!=0||operacion[k]=='.'){
		 								temp[ 0 ] = operacion[k]; 
										temp[ 1 ] = '\0'; 
			 							strcat(aux2,temp);
			 							i=k;
			 							if(operacion[k]=='.'){
			 								cont++;

			 							}
			 							if(cont>=2){
			 								flag=-1;
			 								break;
			 							}
			 						}
		 							else{
		 								flag=-1;
		 								break;
		 							}
			 					}

			 					if(flag!=-1){
			 						number1=atof(aux2);
			 						flag=6;
			 					}
			 					else{
			 						printf(">>Error #3 -----------------------------------------------------Sintaxis Erronea\n");
			 						
			 					}
							}
			 				else{
			 					printf(">>Error #3 -----------------------------------------------------Sintaxis Erronea\n");
			 					flag=-1;
			 				}
		 				}
		 			}
		 			if(flag==-1){
						break;
		 			}
		 		}
		 	if(flag==0){printf(">>Error #1 -----------------------------------------------------Operacion Invalida\n");}
 			else{
	 			if(flag==7){
	 				procesar(flag_p,number1);
		 		}
		 		else if(flag!=-1){
		 			printf(">>Error #3 -----------------------------------------------------Sintaxis Erronea\n");
			 	}
 			}

 		}
 		
 	} while (flag!=-2);
 	
  return 0;
} 