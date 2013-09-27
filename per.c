#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
void element_swap( char *buffer, size_t a, size_t b );
 
int main( int argc, char *argv[] )
{
	size_t i=0;
	char *buffer;
 
	if( argc < 2 )
	{
		printf("Uso:\n%s <numero>\n", argv[0] );
		return 0;
	}
 
	size_t len = strlen( argv[1] );
	buffer = (char*)malloc( len );
	strcpy(buffer, argv[1] );
	size_t opciones = 1;
	for( i = 1; i <= len ; i++ )
	{
		opciones *= i;
	}
 	printf("%d -------------------\n", 3 % 4);
	printf("Mostrando las %d Opciones:\n", opciones );
	for( i = 0; i < opciones ; i++ )
	{
		printf("%d -------------------\n", i % (len-1));
		printf("%s\n", buffer );
		element_swap(buffer, i % (len-1), len - 1 );
	}
 
	free( buffer );
	return 0;
}
 
 
void element_swap( char *buffer, size_t a, size_t b )
{
	char temp = buffer[ a ];
	buffer[ a ] = buffer[ b ];
	buffer[ b ] = temp;
}