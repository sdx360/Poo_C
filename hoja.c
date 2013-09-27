/*
 Dan Williams Robledo Cruz
 Practica No. 2
La practica simula una pequeña hoja de calculo con datos tipo flotante
las operaciones se realizan utilizando las palabras reservadas:
SUMAR, MULTIPLICAR, BORRAR, INSERTAR
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
float hoja[5][5];
int fila [2]={0,4};
int columna [2]={0,4};
int opc=0,err=0,err2=0,err3=0,idx=0;
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
void imprimirerror(int err,int err2, int err3){

	if(err!=0){
		printf(">>Error #1 -----------------------------------------------------Operacion Invalida\n");
	}
	if(err2!=0){
		printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
	}
	if(err3!=0){
		printf(">>Error #3 -----------------------------------------------------Sintaxis Erronea\n");
	}

}
int comprobar(){
	if((columna [0]<columna [1]&&fila[0]==fila[1])||(columna [0]==columna [1]&&fila[0]<fila[1]))
	{
		return 1;
	}
	else{
		err2=2;
		return 0;
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
						if(err2!=2){
							printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
						}
					

					}
					else if(comprobar()==1||flag_p==-1)
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
						if(err2!=2){
							printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
						}
					}
			break;
		case 2:
				if(flag_p==0){
					hoja[fila[0]][columna[0]]=0;
					print_hoja();
				}
				else if(comprobar()==1||flag_p==-1)
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
					if(err2!=2){
							printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
						}
				}
			break;
		case 3:
				if(flag_p==0){
					hoja[fila[0]][columna[0]]=number1;
					print_hoja();
				}
				else if(comprobar()==1||flag_p==-1)
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
					if(err2!=2){
							printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
						}
				}
			break;
		case 4:
				resultado=1;
					if(flag_p==0){
						if(err2!=2){
							printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
						}
					}
					else if(comprobar()==1||flag_p==-1)
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
						if(err2!=2){
							printf(">>Error #2 -----------------------------------------------------Rango incorrecto\n");
						}
					}
			break;
		
		
	}
	return ;

}
void operation(char aux[]) {
	
	if(strncmp(aux,"SUMAR",strlen(aux))==0&&strncmp(aux,"SUMAR",5)==0)
	{
		opc=1;
		
	}
	else if(strncmp(aux,"MULTIPLICAR",strlen(aux))==0&&strncmp(aux,"MULTIPLICAR",11)==0)
	{
		opc=4;
		
	}
	else if(strncmp(aux,"BORRAR",strlen(aux))==0&&strncmp(aux,"BORRAR",6)==0)
	{
		opc=2;
		
	}
	else if(strncmp(aux,"INSERTAR",strlen(aux))==0&&strncmp(aux,"INSERTAR",8)==0)
	{
		opc=3;
		
	}
	else{err=1;}
} 


int main (int argc, char** argv)
{
	int flag,i,k,j,flag_p=0;
	char operacion[50];
	char temp[ 2 ]; 
 	system("clear");
 	print_hoja();
 	printf("Elegir opcion \tINSERTAR  BORRAR  SUMAR  MULTIPLICAR\n");
 	do
 	{
 		flag=0;
 		opc=0;
 		err=0;
 		err2=0;
 		err3=0;
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
 		
 		if(strlen(operacion)!=0)
 		{
 				for (i = 0; i < strlen(operacion); i++)
		 		{
		 			
		 			if(operacion[i]!='('){
		 				if((isalpha((unsigned char)operacion[i])!=0&&flag==0)||operacion[i]==' ')
			 			{
			 					temp[ 0 ] = operacion[i];
								temp[ 1 ] = '\0'; 
			 					strcat(aux,temp);
			 					
		 				}
		 				
		 				
		 			}
		 			else{
		 				operation(aux);
		 				
		 				for(k=i+1; k<strlen(operacion); k++)
		 				{

		 					if(operacion[k]==')'&& operacion[k-1]!='(')
		 					{
		 						flag=1;
		 						for (j=i+1 ;j < k; j++)
		 						{
		 						
		 							if(isdigit((unsigned char)operacion[j])!=0&&flag==2){
				 						temp[ 0 ] = operacion[j]; 
										temp[ 1 ] = '\0'; 
				 						int sum=atoi(temp);
				 						
				 						if(sum<=5){
				 							fila[flag_p]=sum-1;
				 							flag=4;
				 						}
				 						else{
				 							err2=2;
				 							flag=-1;
				 							
				 						}
				 					}
				 					else if(operacion[j]==':'&&flag==4){
				 						flag_p=1;
				 						flag=1;

				 					}
				 					else if(isalpha((unsigned char)operacion[j])!=0&&flag==1){
				 						switch(operacion[j]){
					 						case 'A':
					 							columna[flag_p]=0;
					 							flag=2;
					 							
					 						break;
					 						case 'B':
					 							columna[flag_p]=1;
					 							flag=2;
					 						break;
					 						case 'C':
					 							columna[flag_p]=2;
					 							flag=2;
					 						break;
					 						case 'D':
					 							columna[flag_p]=3;
					 							flag=2;
					 						break;
					 						case 'E':
					 							columna[flag_p]=4;
					 							flag=2;
					 						break;
					 						default:
					 							err2=2;
					 							
				 						}
				 					}
				 					else{
				 						err2=2;
				 						
				 					}
		 						}
		 						if(flag!=4){
		 							err2=2;
		 						}
		 						if(err2!=2&&flag==4){
		 							comprobar();
		 						}

		 						idx=k+1;
		 						i=idx;
		 						k=strlen(operacion);
		 						
		 					}
		 					if(operacion[k-1]=='('&&operacion[k]==')'){

		 							flag_p=-1;
		 							
		 							idx=k+1;
		 							i=idx;
		 							k=strlen(operacion);
		 					}

		 					
		 				}
		 				
		 				if(operacion[strlen(operacion)-1]!=';'){err3=3;}
		 				else{

		 					for (j = idx; j < strlen(operacion); j++)
			 				{
			 					
			 					if(operacion[j]==';')
				 				{
					 				if(opc==3&&number1==0){
					 						flag=-1;
					 						err3=3;
					 				}
					 				else{
					 						flag=7;	
					 				}
				 					
				 				}
				 				else if(operacion[j]==' '&&opc==3)
				 				{
				 					int cont=0;
				 					for (k = j+1; k <strlen(operacion)-1; k++)
				 					{
				 						
			 							if(isdigit((unsigned char)operacion[k])!=0||operacion[k]=='.'){
			 								temp[ 0 ] = operacion[k]; 
											temp[ 1 ] = '\0'; 
				 							strcat(aux2,temp);
				 							
				 							if(operacion[k]=='.'){
				 								cont++;

				 							}
				 							if(cont>=2){
				 								flag=-1;
				 								err3=3;
				 								break;
				 							}
				 						}
			 							else{
			 								flag=-1;
			 								err3=3;
			 								
			 							}
			 							i=k;
				 					}

				 					if(flag!=-1){
				 						number1=atof(aux2);
				 						flag=6;
				 					}
				 					j=i;
								}
								else{
				 					err3=3;
				 					flag=-1;
				 				}

			 				}

		 				}
		 				
		 				if(flag==7&&err==0&&err2==0&&err3==0){
				 				procesar(flag_p,number1);
					 	}
					 	else {
					 		if(flag==0){err3=3;}
					 		printf("%d%d%d%s",err,err2,err3,"\n");
					 			imprimirerror(err,err2,err3);
						}

		 			}
		 		}
		}
	} while (flag!=-2);
 	
  return 0;
} 