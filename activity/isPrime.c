#include <stdio.h>

int isPrime(int x)
{
    int prime = 0;

    for(int i = 2; i < x; i++){
        if(x % i == 0) prime++;
    }
    
    if(prime == 0) return 1;
    else return 0;
}

int main(){
    int a;
    printf("Input number : ");
    scanf("%d", &a);
    if (isPrime(a)==1){
        printf("Prime Number.");
    }
    else{
        printf("Not Prime Number.");
    }
    return 0;
}