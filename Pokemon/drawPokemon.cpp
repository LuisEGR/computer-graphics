#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <vector>
#include <sstream>
#include "raster.h"
#include "line.h"
#include "polygon.h"
#include "matriz.h"
#define PI 3.14159265
#define SCALE_FACTOR 10
using namespace std;

int main()
{
	
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
	Color linec = {2, 42, 212};	
   //ifstream archivo("who.is.that.pokemon.obj");
   ifstream file("Sonic.obj");
   //ifstream file("cube.obj");
   string str;
   string file_contents;
   string vertices[20000];
   string faces[20000];
   
   int fcs_1[20000];
   int fcs_2[20000];
   int fcs_3[20000];

   int vcs_x[20000];
   int vcs_y[20000];
   int vcs_z[20000];

   //Perspective vertexes
   int vcs_px[20000];
   int vcs_py[20000];

   //rotation vertexes
   int vcs_rx[20000];
   int vcs_ry[20000];
   int vcs_rz[20000];

   int vc, fc;
   vc = 1;
   fc = 0;
   string::size_type sz;
   while (getline(file, str))
   {
   vector<string>tokens;
   string buf="";            
      if(str.substr(0,1) == "v"){
         vertices[vc] = str.substr(2);         
         stringstream ss(vertices[vc]);
         while(ss>>buf){
         	tokens.push_back(buf);
         }
         vcs_x[vc] = (int) (stof(tokens[0],&sz) * SCALE_FACTOR); 
         vcs_y[vc] = (int) (stof(tokens[1],&sz) * SCALE_FACTOR); 
         vcs_z[vc] = (int) (stof(tokens[2],&sz) * SCALE_FACTOR);
         // cout<<"VCX("<<vc<<"): "<<vcs_x[vc]<<"\t";
         // cout<<"VCY("<<vc<<"): "<<vcs_y[vc]<<"\t";
         // cout<<"VCZ("<<vc<<"): "<<vcs_z[vc]<<"\t\n";
         vc++;
      }

      if(str.substr(0,1) == "f"){
        faces[fc] = str.substr(2);
        stringstream ff(faces[fc]);
      	while(ff>>buf){
        	tokens.push_back(buf);
        }
        //Saving the faces points on int format, so I can use as index in the vertex array
         fcs_1[fc] = stoi(tokens[0],&sz);
         fcs_2[fc] = stoi(tokens[1],&sz);
         fcs_3[fc] = stoi(tokens[2],&sz);
         cout<<"FC1("<<fc<<"): "<<fcs_1[fc]<<"\t";
         cout<<"FC2("<<fc<<"): "<<fcs_2[fc]<<"\t";
         cout<<"FC3("<<fc<<"): "<<fcs_3[fc]<<"\t\n";
         fc++;
      }
     //file_contents += str;
     //file_contents.push_back('|');
   }  
   cout<<"vertices: "<<vc<<endl;
   cout<<"Caras: "<<fc<<endl;
    
    for(int k = 1; k<=360; k++){
      cleanRaster(myRaster);


    ///////////////Y-Axis Rotation////////
    for(int i = 0; i<vc; i++){
    float q = (k*PI)/180;   
    //rotation
    vcs_rx[i] = (int) vcs_x[i] * cos(q) - vcs_z[i] * sin(q);
    vcs_rz[i] = (int) vcs_z[i] * cos(q) + vcs_x[i] * sin(q);
    vcs_ry[i] = vcs_y[i];
    //vcs_x[i] = (int) ( (vcs_z[i] * cos(q)) - (vcs_x[i] * sin(q)) );
    //vcs_z[i] = (int) ( (vcs_z[i] * sin(q)) + (vcs_x[i] * cos(q)) ); 
    }  
    ////////////////////////////////////////


   ///////////////////////////////////////
   ////3d axis
   // Segment Y = {0,0,-1080,0};
   // Segment X = {0,0,0,1920};
   // Segment Z = {0,0,0,0};
   // InputData input = {myRaster, Y,{0,255,0}}; 
   // createLine(input);
   // input = {myRaster, X,{255,0,0}}; 
   // createLine(input);
   // input = {myRaster, Z,{0,0,255}}; 
   // createLine(input);

   for(int i = 0; i<fc; i++){
    // //Vista Frontal xy
    Segment l1 = {-vcs_ry[fcs_1[i]],vcs_rx[fcs_1[i]],-vcs_ry[fcs_2[i]],vcs_rx[fcs_2[i]]};
    Segment l2 = {-vcs_ry[fcs_2[i]],vcs_rx[fcs_2[i]],-vcs_ry[fcs_3[i]],vcs_rx[fcs_3[i]]};
    Segment l3 = {-vcs_ry[fcs_3[i]],vcs_rx[fcs_3[i]],-vcs_ry[fcs_1[i]],vcs_rx[fcs_1[i]]};
    //Vista superior xz
    // Segment l1 = {vcs_rz[fcs_1[i]],vcs_rx[fcs_1[i]],vcs_rz[fcs_2[i]],vcs_rx[fcs_2[i]]};
    // Segment l2 = {vcs_rz[fcs_2[i]],vcs_rx[fcs_2[i]],vcs_rz[fcs_3[i]],vcs_rx[fcs_3[i]]};
    // Segment l3 = {vcs_rz[fcs_3[i]],vcs_rx[fcs_3[i]],vcs_rz[fcs_1[i]],vcs_rx[fcs_1[i]]};
  	drawPolygon(myRaster, l1, l2, l3, linec);
   }

  char nombre[30];
  sprintf(nombre, "Sonic_%d.ppm", k);  
	printRaster(myRaster,nombre, fondo);
  }
   return 0;
}






