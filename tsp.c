
#include <stdio.h>
#include <stdlib.h>

void matriz(int width, int heigth){
	float **matriz, i;
	matriz=(float**) malloc(heigth * sizeof(float*));
	if(!matriz){
		fprintf(stderr, "Error in memory matriz\n" );
		exit(-1);
	}
	for(i=0; i<width;i++){
		matriz[i]=(float*)malloc(width * sizeof(float));
		if(!matriz[i]){
			fprintf(stderr, "%sError in memory matriz\n");
			exit(-1);
		}
	}
	return matriz;
}


int main(int argc, char*argv[]) {
    int num=0;
    num=atoi(argv[2]);
    if(num>=3 && num<=6&&argc<=10){
    	
    	printf("%d%s", num,"\n");
    	

    }
    else
    {
    	printf("Error \n");
    }
    
    return 0;
   
}

