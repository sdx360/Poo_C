

#include <stdio.h>
#include <stdlib.h>

int number[4];

void imprimir(int count){
    int i;
    for (i = 0; i < count; ++i)
    {
        printf("\t%d", number[i]);
    }
        printf("\n\n");

}
void ordenar(int count){
    int i,j,aux;
    for (i = 0; i < count; ++i)
    {
                    
            for (j        = 0; j < count-i; j++) {
                    if (number[j] < number[j + 1]) {
                    aux           = number[j];
                    number[j]     = number[j + 1];
                    number[j + 1] = aux;
                    }
                
            }
            
    }
}
/*
 * 
 */
int main(int argc, char** argv) {
    int flag=0,numero=0,i,digito;
    do{
        printf("Cuantos numeros quieres ordenar \n");
        scanf("%d", &numero);
        while (getchar() != '\n');

        number[numero];
        for (i = 0; i < numero; ++i)
        {
            printf("Ingresa el numero %d%s", i+1,"\n");
            scanf("%d", &digito);
            number[i]=digito;
        }
        imprimir(numero);
        ordenar(numero);
        imprimir(numero);
        
    }while(flag!=0);
    
    return0
}