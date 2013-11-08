#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <regex.h>
#include <unistd.h>
#include <math.h>
typedef struct{
	int coor_x;
	int coor_y;
	float costo_gas;
}DatosUbicacion;

typedef struct{
	char codigo[15];
	char tipo;
	float precio;
	DatosUbicacion ubicacion;
}DatosPropiedad;
	
typedef struct{
	char codigo[5];
	char nombre[80];
	DatosUbicacion ubicacion;
}DatosAgenteV;

typedef struct 
{
	float total;
	char asignaciones[200];
}Asignacion;

Asignacion solucion;
DatosAgenteV *agente;
DatosPropiedad *propiedad;
int *vector;
int m=0,n=0;
int evaluar(char a[],char b[]){
	regex_t regex;
	int re;

	re=regcomp(&regex,a,REG_EXTENDED);
	return re=regexec(&regex, b, 0, NULL, 0);

}

void tokenizer(char s1[],int pos,char opc){
		char *t1;
		switch(opc){
 		case 'p':
 			t1 = strtok(s1,"\t");
				propiedad[pos].ubicacion.coor_x=atoi(t1);
			t1 = strtok(NULL,"\t");
			 	propiedad[pos].ubicacion.coor_y=atoi(t1);
			t1 = strtok(NULL,"\t");
		 		propiedad[pos].ubicacion.costo_gas=atof(t1);
 		break;
 		case 'v':
 			t1 = strtok(s1,"\t");
				agente[pos].ubicacion.coor_x=atoi(t1);
			t1 = strtok(NULL,"\t");
			 	agente[pos].ubicacion.coor_y=atoi(t1);
			t1 = strtok(NULL,"\t");
		 		agente[pos].ubicacion.costo_gas=atof(t1);
 		break;
 	}
	
}
double CurrentTime(){
  struct timeval tv;
  gettimeofday(&tv, 0);
  return (tv.tv_sec + tv.tv_usec/1000000.0);
}
void error(int opc){
	switch(opc){
		case 1:printf("Error al abrir el archivo\n");
		break;
		case 2:printf("Sintaxis incorrecta\n");
		break;
		case 3:printf("tiene que ser un archivo .txt\n");
		break;
	}
	FILE *pt;
 	if((pt=fopen("Error.txt","a"))==NULL){
 		error(1);
 	}
 	fprintf(pt, "Error\n");
 	fclose(pt);
	exit(-1);
}
 void memory(int row,char opc){
 	switch(opc){
 		case 'p':
 			propiedad=(DatosPropiedad*) malloc(row*sizeof(DatosPropiedad));
 			vector=(int*)malloc(row*sizeof(int));
			if(!propiedad){
				fprintf(stderr,"Error in Memory Matrix!\n"); 
				exit(-1);
			}
 		break;
 		case 'v':
 			agente=(DatosAgenteV*) malloc(row*sizeof(DatosAgenteV));
			if(!agente){
				fprintf(stderr,"Error in Memory Matrix!\n"); 
				exit(-1);
			}
 		break;
 	}
	
 }
void guardar_archivo(char a[]){
 	FILE *pt;
 	if((pt=fopen(a,"a"))==NULL){
 		error(1);
 	}
 	fprintf(pt, "%.3f\t%s\n", solucion.total,solucion.asignaciones);
 	fclose(pt);
}
void llenar(FILE *archivo1,char opc){
int pos=0;
char texto[200];
	fscanf(archivo1,"%[^\n]\n",texto);
		if(evaluar("^[0-9]+",texto)!=0){error(1);}
		
		switch(opc) {
			case 'p':
				n=atoi(texto);
				memory(n,opc);
				char *t;
				while(!feof(archivo1)&&pos<n){
					fscanf(archivo1,"%[^\n]\n",texto);
					t = strtok(texto,"\t");
					strcpy(propiedad[pos].codigo, t);
					t = strtok(NULL,"\t");
					propiedad[pos].tipo=t[0];
					t = strtok(NULL,"\t");
					propiedad[pos].precio=atof(t);
					t = strtok(NULL,"\n");
					tokenizer(t,pos,opc);
					//printf("%s\t%c\t%.2f\t%d\t%d\t%.2f\n", propiedad[pos].codigo,propiedad[pos].tipo,propiedad[pos].precio,propiedad[pos].ubicacion.coor_x,propiedad[pos].ubicacion.coor_y,propiedad[pos].ubicacion.costo_gas);
					pos++;
				};
			break;
			case 'v':
				m=atoi(texto);				
				memory(m,opc);
				while(!feof(archivo1)&&pos<m){
					fscanf(archivo1,"%[^\n]\n",texto);
					strcpy(agente[pos].codigo, texto);
					fscanf(archivo1,"%[^\n]\n",texto);
					strcpy(agente[pos].nombre, texto);
					fscanf(archivo1,"%[^\n]\n",texto);
					tokenizer(texto,pos,opc);
					//printf("%s\n%s\n%d\t%d\t%.2f\n", agente[pos].codigo,agente[pos].nombre,agente[pos].ubicacion.coor_x,agente[pos].ubicacion.coor_y,agente[pos].ubicacion.costo_gas);
					pos++;
				};
			break;
		}
		
}
void asignar(){
	int alpha,cont=0,i,pos=0,rnum=0,j;
	alpha=n/m;
	do{
		for (i = 1; i <= m; ++i)
		{
			vector[pos]=i;
			pos++;
		}
		cont++;
	}while(cont!=alpha);
	cont=pos;
	vector[pos]=0;
	if(n%m!=0){
		srand(getpid());
		for (i = 0; i <(n-m*alpha); ++i)
		{
			rnum=rand()%m+1;
			for (j = cont; j <=pos; ++j)
			{
				if(rnum==vector[j]){
					rnum=rand()%m+1;
					j=cont-1;
				}
			}
			vector[pos]=rnum;
			pos++;
		}
		
	}
	solucion.total=0;
}
void costo(){
	int i;float total=0,x,y;
	char temp[100]="";
	for (i = 0; i <n; ++i)
	{
		x=abs(agente[vector[i]-1].ubicacion.coor_x- propiedad[i].ubicacion.coor_x)*100;
		y=abs(agente[vector[i]-1].ubicacion.coor_y- propiedad[i].ubicacion.coor_y)*100;
		total+=((sqrt((x*x)+(y*y)))*agente[vector[i]-1].ubicacion.costo_gas)+((sqrt((x*x)+(y*y)))*propiedad[i].ubicacion.costo_gas);
		sprintf(temp, "%s%s,%s\t",temp,propiedad[i].codigo,agente[vector[i]-1].codigo);	
	}
	if(total<solucion.total||solucion.total==0){
		solucion.total=total;
		strcpy(solucion.asignaciones, temp);
	}
	
}

void switchpos(){
	int i,j,temp;
	do{
	i=rand()%n;
	j=rand()%n;
	while(j==i){
		j=rand()%n;
	}
	
}while(vector[i]==vector[j]);
	temp=vector[i];
	vector[i]=vector[j];
	vector[j]=temp;
	
}
int main(int argc, char *argv[])
{
	//system("clear");
	//double start, end,seconds;
	//start=CurrentTime();
	FILE *archivo1=NULL,*archivo2=NULL;
	char *resp;
	char nombre[200];
	int combinaciones=1,i;
	resp=strstr( argv[2], ".txt" );
	if(resp==NULL){
   		error(3);
   	}
	if(argc==4&&strcmp(argv[1],"-FILES")==0)
	{
		if(((archivo1=fopen(argv[2],"r"))==NULL)||((archivo2=fopen(argv[3],"r"))==NULL)){
			error(1);
		}
		llenar(archivo1,'p');
		llenar(archivo2,'v');	
		asignar();
		for (i = 1; i <=m; ++i)
		{
			combinaciones=(combinaciones*(n-i+1))/i;
		}
		costo();
		srand(getpid());
		for (i = 1; i <combinaciones; ++i)
		{
		switchpos();
		costo();	
		}
		sprintf( nombre, "%s_%s.out", strtok(argv[2],"."), strtok(argv[3],"."));
		guardar_archivo(nombre);
		fclose(archivo1);
		fclose(archivo2);
		
	}
	else{error(2);}

	//end=CurrentTime();
	//seconds=(end-start);
	//printf("\n\nSegundos: %.5f\tReloj de computadora:%.10f\n",seconds,seconds/(double)CLOCKS_PER_SEC);
   return 0;
}