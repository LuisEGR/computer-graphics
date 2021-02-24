#ifndef POLYGON_H
#define POLYGON_H
void drawPolygon(unsigned char *** myRaster,Segment v1, Segment v2, Segment v3, Color linec){
  InputData input;
  //Segment v1Center = {v1.x1 + 960, v1.y1 + 540, v1.x2 + 960, v1.y2 + 540};
	cout<<endl<<"Drawing L1: ("<<v1.x1<<","<<v1.y1<<"->"<<v1.x2<<","<<v1.y2<<")"<<endl;
	input = {myRaster, v1, linec}; 
	createLine(input);
	
	cout<<endl<<"Drawing L2: ("<<v2.x1<<","<<v2.y1<<"->"<<v2.x2<<","<<v2.y2<<")"<<endl;
	input = {myRaster, v2, linec}; 
	createLine(input);

	cout<<endl<<"Drawing L3: ("<<v3.x1<<","<<v3.y1<<"->"<<v3.x2<<","<<v3.y2<<")"<<endl;
	input = {myRaster, v3, linec}; 
	createLine(input);
}
#endif