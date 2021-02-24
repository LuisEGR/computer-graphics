#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	FILE *f;
	srand(time(NULL));
	f = fopen("imagen.ppa", "w");
	fprintf(f, "P3\n");	
	fprintf(f, "1920 1080 255\n");
	for(int i=0;i<1920; i++){
		for(int j=0;j<1080;j++){
			fprintf(f, "%d %d %d ", rand()%256, rand()%256, rand()%256);
		}
		fprintf(f, "\n");
	}
	fclose(f);
}


