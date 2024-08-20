#include <string.h>
#include <stdio.h>

int main(){
    int num, temp;
    int i = 2;
    int first = 2;

    scanf("%d", &num);

    if(num == 1){
        printf("1");
        return 0;
    }

    while(num > 1){
        if (num % i == 0){
            num /= i;
            printf("%d ", i);
            break;
        }
        else i++;
    }
    i = 2;

    while(num > 1){
        if (num % i == 0){
            num /= i;
            printf("* %d ", i);
        }
        else i++;
    }
}