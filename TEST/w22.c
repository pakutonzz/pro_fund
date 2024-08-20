#include <stdio.h>

int main(){
    int num;
    int i, j;

    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        if (i % 2 == 0){
            for(j = 0; j < num; j++){
                printf("*");
            }
            printf("\n");
        }
        else if(num % 2 == 0){
            for(j = 0; j < num/2; j++){
                printf("* ");
            }
            printf("\n");
        }
        else{
            for(j = 0; j < num/2; j++){
                printf("* ");
            }
            printf("*");
            printf("\n");
        }
    }
}