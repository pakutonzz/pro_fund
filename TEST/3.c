#include <stdio.h>

int main(){
    int num[2];
    int temp;

    scanf("%d", &num[0]);
    scanf("%d", &num[1]);

    if(num[0] > num[1]){
        temp = num[0];
        num[0] = num[1];
        num[1] = temp;
    }
    int i = num[0] + 1;

    while(i > num[0] && i < num[1]){
        if(i % num[0] == 0 && num[1] % i == 0){
            printf("%d ", i);
        }
        i++;
    }
}