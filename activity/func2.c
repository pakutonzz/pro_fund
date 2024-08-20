#include <stdio.h>
#include <stdlib.h>

float area(int x1,int y1,int  x2,int y2,int  x3,int y3){
    return abs((x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2)/2);
}

int main(){
    int x1, y1 ,x2, y2, x3, y3;
    scanf("%d %d %d %d %d %d", &x1,&y1, &x2,&y2, &x3,&y3);
    
    printf("%.2f", area(x1,y1 ,x2,y2, x3,y3));
}