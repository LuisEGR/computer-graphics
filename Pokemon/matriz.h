#ifndef MATRIZ_H
#define MATRIZ_H
#include<iostream>
using namespace std;

void multiplicateMatrix(int (&a)[4][4], int (&b)[4][4], int (&c)[4][4]){
    int i,j;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            c[i][j]=0;
            for(int k=0; k<4; k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
}
// void multiplicateMatrix_1x4_4x4(int (&a)[4][4], int (&b)[4][4], int (&c)[4][4]){
//     int x,y,i,j,m,n;
//     x = 4;
//     y = 4;
//     m = 4;
//     n = 4;

//     for(i=0; i<4; i++)
//     {
//         for(j=0; j<4; j++)
//         {
//             c[i][j]=0;
//             for(int k=0; k<4; k++)
//             {
//                 c[i][j]=c[i][j]+a[i][k]*b[k][j];
//             }
//         }
//     }
//}
void printMatrix( int (&a)[4][4] ){
    int i,j;
    cout<<"\n\nMatrix:\n\n";
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            cout<<"\t"<<a[i][j];
        }
        cout<<"\n\n";
    }
}

#endif