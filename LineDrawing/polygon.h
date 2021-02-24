#ifndef POLYGON_H
#define POLYGON_H
void drawPolygon(unsigned char *** myRaster,Segment v1, Segment v2, Segment v3, Color linec){
  InputData input;
  input = {myRaster, v1, linec}; 
  createLine(input);
  input = {myRaster, v2, linec}; 
  createLine(input);
  input = {myRaster, v3, linec}; 
  createLine(input);
}
#endif