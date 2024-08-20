#include <stdio.h>

int main(void){
    int num, i;
    scanf("%d", &num);

    for(i = 0; i < num; i++){
        printf("*");
    }

    for(i = 0; i < num-2; i++){
        printf("\n*");
        for(int j = 0; j < num-2; j++){
            printf(" ");
        }
        printf("*");
    }
    printf("\n");
    for(i = 0; i < num; i++){
        printf("*");
    }
}