#include <stdio.h>
#include <math.h>
int main()
{
    float x0, y0, xn, yn, h, k;
    x0 = y0 = 0;
    xn = yn = 3;
    h = k = 1;
    int xseg = (xn - x0)/h, yseg = (yn - y0)/k;
    float mat[xseg + 1][yseg + 1];
    for(int i = 0;i <= xseg; i++){
        for(int j = 0; j <= yseg ; j++){
            if(i == 0 || j == yseg){
                mat[i][j] = 200;
            }
            else if(j == 0 || i== xseg){
                mat[i][j] = 100;
            }
            else{
                mat[i][j] = 0;
            }
        }
    }
    float error = 1;
    while(error > 0.005f){
        float oldval = mat[1][1];
        for(int i = 1; i < xseg; i++){
            for(int j = 1; j < yseg; j++){
                mat[i][j] = (mat[i - 1][j] + mat[i + 1][j] + mat[i][j - 1] + mat[i][j + 1])/4.0;
            }
        }
        error = (mat[1][1] - oldval)/mat[1][1]; 
    }    
    for(int i = 1; i < xseg; i++){
            for(int j = 1; j < yseg; j++){
                printf("F(%d,%d): %f\n", i, j, mat[i][j]);
            }
    }
    return 0;
}
