#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int x1,y1, x2,y2, x3,y3;
    
    scanf("%d %d %d %d %d %d", &x1,&y1, &x2,&y2, &x3,&y3);

    float d[5];
    
    d[1] = sqrt(pow((x1 - x2),2) + pow(y1-y2,2));
    d[2] = sqrt(pow((x2 - x3),2) + pow(y2-y3,2));
    d[3] = sqrt(pow((x3 - x1),2) + pow(y3-y1,2));

    d[4] = d[1] + d[2] + d[3];
    printf("%.3f", d[4]);
}