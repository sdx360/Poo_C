#import <stdio.h>
#import <stdlib.h>
#import <string.h>
#include <ctype.h>
void conteo(int *v, int *c, int *n, int *e, int * o,char cad[]){
int i;
	for (i = 0; i <strlen(cad); i++)
	{
		if(isalpha((unsigned char)cad[i])!=0)
		{
			 switch(cad[i]){
			 	case 'A':
			 	case 'a':
			 		++*v;
			 	break;
			 	case 'E':
			 	case 'e':
			 		++*v;
			 		break;
			 	case 'I':
			 	case 'i':
			 		++*v;
			 		break;
			 	case 'O':
			 	case 'o':
			 		++*v;
			 		break;
			 	case 'U':
			 	case 'u':
			 		++*v;
			 		break;
			 		default:
			 		++*c;
			 }
			 		
		}
		else if(isdigit(cad[i])!=0){
			 			++*n;
		}
		else if(cad[i]==' '){
			++*e;
		}
		else{
			//printf("%c\n",cad[i]);
			++*o;
		}	


	}


}

int main (int argc, char * argv[]){
	int i,longitud=0;
	int vocales=0,consonantes=0,numeros=0,espacios=0,otros=0;
	char *cadena;
	system("clear");

	for (i = 1; i <argc; i++)
	{
		longitud+=strlen(argv[i])+1;
		
	}

	cadena=(char *) malloc(longitud-1 * sizeof(char));
	

	for (i = 1; i <argc; i++)
	{
		strcat(cadena, argv[i]);

		strcat(cadena, " ");
	}
	cadena[strlen(cadena)-1]='\0';
	conteo(&vocales,&consonantes,&numeros,&espacios,&otros,cadena);
	printf("%s\n",cadena);
	printf("%d--%d--%d--%d--%d\n",vocales, consonantes, numeros, espacios, otros);
	return 0;

}