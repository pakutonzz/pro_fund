#include <stdio.h>

int main(){
    int num[3];
    int temp;
    
    for(int i = 0; i < 3; i++){
        scanf("%d", &num[i]);
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3-i; j++){
            if(num[j] > num[j+1]){
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
    if(num[0] + num[1] > num[2]){
        printf("Yes");
    }
    else printf("no");
}