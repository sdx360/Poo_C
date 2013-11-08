#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char s[11] = "Hola amigos";
   
   char *resp;
   printf( "s=%s\t", s );
   printf( "c=%s\n", "la" );
   resp=strstr( s, "00" );
   if(resp==NULL){
   	printf("NUlo\n");
   }
   else{
   printf( "strchr=%s\n",  resp);
}
   return 0;
}