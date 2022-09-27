/*Write a program to approximate the functional value at any given 
x from given n no. of  data using Lagrange’s interpolation. 
*/
#include <stdio.h>
#include <stdlib.h>
float Lagrange(int *x, int *y, int xp, int size) {
    int i, j, numer, denom;
    float yp = 0;
    for(i = 0; i < size; i++) {
        numer = denom = 1;
        for(j = 0; j < size; j++) {
            if(i == j) {
                continue;
            } else {
                numer *= (xp - *(x+j));
                denom *= (*(x+i) - *(x+j));
            }
        }
        yp += (numer/(float)denom) * *(y+i);
    }
    return yp;
}
int main() {
    int *x, *y, xp, size, i;
    float yp;
    printf("Enter the number of data: ");
    scanf("%d", &size);
    x = (int*) malloc(size*sizeof(int));
    y = (int*) malloc(size*sizeof(int));
    printf("Enter the data:");
    for(i = 0; i < size; i++) {
        printf("\nX%d: ", i);
        scanf("%d", (x+i));
        printf("Y%d: ", i);
        scanf("%d", (y+i));
    }
    printf("Enter the x interpolation point: ");
    scanf("%d", &xp);
    yp = Lagrange(x, y, xp, size);
    printf("f(x): %.3f", yp);
    return 0;
}

