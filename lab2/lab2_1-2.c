#include <stdio.h>

int main(){
    int num1 = 8, num2 = 12, temp;
    int common = 1;

    printf("enter first number : ");
 //   scanf("%d", &num1);
    printf("enter second number: ");
  //  scanf("%d", &num2);
    
    while (num2 != 0) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    
    printf("common = %d", num1);
    return 0;
}
