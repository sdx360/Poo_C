#include <stdio.h>
#include <stdlib.h>
int main( int argc, char *argv[] )
{


	int y, *ip; 
	y = 12; 
	printf ("\nValor de y %d, de ip %d", y, ip); /*sin asignar ip */ 
	ip = &y; 
	*ip = *ip + 10; 
	printf ("\nValor de y %d, de *ip %d y de ip %d", y, *ip, ip); 
	y = *ip + 10; 
	printf ("\nValor de y %d, de *ip %d", y, *ip); 
	*ip += 1; 
	printf ("\nValor de y %d, de *ip %d", y, *ip); 
		  
}