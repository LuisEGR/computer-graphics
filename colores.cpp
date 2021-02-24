#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "raster.h"


int main(){
	unsigned char ***myRaster;
	Color fondo = {10, 10, 10}; //{R, G B}
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
	/*	for (int i = 0; i < 200; ++i)
		{
			put_pixel(myRaster, i, i, rand()%256, rand()%256, rand()%256 );
		}
	*/
	printRaster(myRaster, fondo);
}
