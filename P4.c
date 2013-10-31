#include <stdio.h>
#include <string.h>
#include <regex.h>
int evaluar(char a[],char b[]){
regex_t regex;
int re;

re=regcomp(&regex,a,REG_EXTENDED);
return re=regexec(&regex, b, 0, NULL, 0);

}
 
int main( )
{
   
	if(evaluar("^[-+]?([0-9]+)$","23")==0){
		printf("match\n" );
	}
   return 0;
}