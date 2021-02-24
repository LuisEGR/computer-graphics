#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void put_pixel(unsigned char ***Raster, int cols, int rows, int r, int g, int b);
int main(void)
{
	unsigned char ***Raster;	
	unsigned int columns =0;
	unsigned int rows =0;
	int r, g, b;	
	//FILE *f=0;
	FILE *fp=0;
	
	Raster=(unsigned char***)malloc(1080*sizeof(unsigned char**));
	int i;
	int j;	
	for(i=0; i < 1080; i++)
	{
		Raster[i]=(unsigned char**)malloc(1920*sizeof(unsigned char*));		
		for(j=0; j < 1920; j++)
		{
			Raster[i][j]=(unsigned char*)malloc(3*sizeof(unsigned char));		
		}
	}
			
	srand(time(NULL));
	
	for (rows=0; rows<1080;rows++)
	{ 	//inner loop control columns
		for(columns=0; columns<1920; columns ++)
		{
			r=rand()%256;
			g=rand()%256;
			b=rand()%256;			
			put_pixel(Raster, columns, rows, r, g, b);

			/*f=fopen("sal.txt", "a+");	
	
			fprintf(f, "Raster[%d][%d][0]=%d r=%d\t",cols, rows, Raster[rows][cols][0], r);
			fprintf(f, "Raster[%d][%d][1]=%d g=%d\t",cols, rows, Raster[rows][cols][1], g);
			fprintf(f, "Raster[%d][%d][2]=%d b=%d\t",cols, rows, Raster[rows][cols][2], b);
			fprintf(f, "\n");

			fclose(f); */

			/*printf("Raster[%d][%d][0]=%d r=%d\t",columns, rows, Raster[rows][columns][0], r);
			printf("Raster[%d][%d][1]=%d g=%d\t",columns, rows, Raster[rows][columns][1], g);
			printf("Raster[%d][%d][2]=%d b=%d\t",columns, rows, Raster[rows][columns][2], b);
			printf("\n"); */
		}
	}
	
	fp=fopen("output.ppm", "w");
	//header
	fprintf(fp,"P3\n1920 1080 255\n"); //255=MAXIMUM VALUE PER CHANNEL/COLOR
	for (rows=0; rows<1080;rows++)
	{
		for(columns=0; columns<1920; columns ++)
		{
			fprintf(fp, "%d %d %d ", (Raster[rows][columns][0]),  (Raster[rows][columns][1]),  (Raster[rows][columns][2])); //red, green, blue
		}
		fprintf(fp, "\n");
	}
	fclose(fp);	
	
	return 0;
}

void put_pixel(unsigned char ***Raster, int cols, int rows, int r, int g, int b)
{
	//FILE *f=0;

	//f=fopen("sal.txt", "a+");	
	Raster[rows][cols][0]=r;	
	//fprintf(f, "Raster[%d][%d][0]=%d r=%d\t",cols, rows, Raster[rows][cols][0], r);
	Raster[rows][cols][1]=g;
	//fprintf(f, "Raster[%d][%d][1]=%d g=%d\t",cols, rows, Raster[rows][cols][1], g);
	Raster[rows][cols][2]=b;
	//fprintf(f, "Raster[%d][%d][2]=%d b=%d\t",cols, rows, Raster[rows][cols][2], b);

	//fprintf(f, "\n");

	//fclose(f);
}
