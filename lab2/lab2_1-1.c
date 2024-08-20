#include <stdio.h>

int main(){
    int x, i;
    int first;

    scanf("%d", &x);
    
    if(x == 1){
        printf("1");
    }
    for(first = 2; first<=x; first++){
        if(x % first == 0){
            printf("%d ", first);
            x = x/first;
            break;
        }
    }
    for(int i = 2; i <= x; i++){
      while(x % i == 0){
        printf("* %d ", i);
        x = x/i;
      }
    }
return 0;
}