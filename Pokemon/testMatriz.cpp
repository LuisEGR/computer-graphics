#include<iostream>
#include "matriz.h"
using namespace std;
int main()
{
    
    int a[4][4], b[4][4],c[4][4];
    int x,y,i,j,m,n;


    cout<<"\nEnter the number of rows and columns for Matrix A:::\n\n";
    cin>>x>>y;

    // x denotes number rows in matrix A
    // y denotes number columns in matrix A

    cout<<"\n\nEnter elements for Matrix A :::\n\n";

    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            cin>>a[i][j];
        }
        cout<<"\n";
    }

    cout<<"\n\nMatrix A :\n\n";
    printMatrix(a);
    multiplicateMatrix(a, a, c);
    printMatrix(c);
   
    return 0;
}