#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "raster.h"
#include "line.h"
int main(){
	unsigned char ***myRaster;
	
	//Asigno memoria dinamicamente para mi matriz de 3 dimensiones..para el raster
	myRaster=(unsigned char***)malloc(1080*sizeof(unsigned char**));
	for(int i=0; i < H; i++)
	{
		myRaster[i]=(unsigned char**)malloc(1920*sizeof(unsigned char*));		
		for(int j=0; j < W; j++)
		{
			myRaster[i][j]=(unsigned char*)malloc(3*sizeof(unsigned char));
		}
	}
	Color fondo = {10, 10, 10}; //{R, G B}
	//Segment linea = {x1, y1, x2, y2};
	// Segment linea1  = {200,-100,600,-300};//1st Quadrant
	// Segment linea2 = {100,-200,300,-600};//2nd Quadrant
	// Segment linea3 = {-100,-200,-200,-500};//3rd Quadrant
	// Segment linea4 = {-200,-100,-500,-300};//4th Quadrant
	// Segment linea5 = {-200,100,-600,300};//5th Quadrant
	// Segment linea6 = {-100,300,-300,600};//6th Quadrant
	// Segment linea7 = {100,200,300,600};//7th Quadrant
 	//Segment linea8 = {200,100,700,300};//8th Quadrant
	// Segment linea = linea8;
	
	// fixSlope(linea, getQuadrant(linea));	
	// InputData input = {myRaster, linea, linec};	
	// createLine(input);

	srand(time(NULL));//Random initializer){
	//for(int j=0;j<1920;j++){			
	// 	}		
	// }
	// for (int i = 0; i < 200; ++i)
	// {
		int x1, y1, x2, y2;
		x1 = rand() % 1920;
		y1 = rand() % 1080;
		x2 = rand() % 1920;
		y2 = rand() % 1080;
		cout<<x1<<","<<y1<<"\t"<<x2<<","<<y2<<"\n";
		Segment linea ={x1, y1, x2, y2};
		//Segment linea ={1762, 491, 973, 200};
		cout<<"1.Cuadrante: "<<getQuadrant(linea)<<endl;
		Color linec = {rand()%256, rand()%256, rand()%256};
		fixSlope(linea, getQuadrant(linea));	
		cout<<"2.Cuadrante: "<<getQuadrant(linea)<<endl;
		cout<<"linea: x1: "<<linea.x1<<", y1: "<<linea.y1;		
		InputData input = {myRaster, linea, linec};	
		createLine(input);
	// }
	
	printRaster(myRaster, fondo);
}
