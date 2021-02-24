#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define W 1920
#define H 1080

void put_pixel(unsigned char ***raster, int x, int y, unsigned char r, unsigned char g, unsigned char b);
void printRaster(unsigned char ***raster);
int main(){
	unsigned char ***myRaster;
	//Asigno memoria dinamicamente para mi matriz de 3 dimensiones..
	myRaster=(unsigned char***)malloc(1080*sizeof(unsigned char**));
	for(int i=0; i < H; i++)
	{
		myRaster[i]=(unsigned char**)malloc(1920*sizeof(unsigned char*));		
		for(int j=0; j < W; j++)
		{
			myRaster[i][j]=(unsigned char*)malloc(3*sizeof(unsigned char));		
		}
	}
			
	srand(time(NULL));
	for(int i=0;i<H; i++){
		for(int j=0;j<W;j++){
			put_pixel(myRaster, i, j, rand()%256, rand()%256, rand()%256 );
		}		
	}
	printRaster(myRaster, 0);
}

void put_pixel(unsigned char *** raster, int x, int y, unsigned char r, unsigned char g, unsigned char b){
	raster[x][y][0] = r;
	raster[x][y][1] = g;
	raster[x][y][2] = b;
}

void printRaster(unsigned char *** raster, colorBase){
	FILE *f;
	unsigned char r, g, b;
	srand(time(NULL));
	f = fopen( "imageRaster.ppa", "w");
	fprintf(f, "P3\n");	
	fprintf(f, "1920 1080 255\n");
	for(int i=0;i<H; i++){
		for(int j=0;j<W;j++){
			r = (raster[i][j][0]=30)?raster[i][j][0]:colorBase;
			fprintf(f, "%d %d %d ", raster[i][j][0], raster[i][j][1], raster[i][j][2] );
		}
		fprintf(f, "\n");
	}
	fclose(f);
}
