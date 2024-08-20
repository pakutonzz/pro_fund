#include <stdio.h>
#include <stdlib.h>
#include <time.h.>

int main(){
    srand(time(NULL));

    for(int i = 0; i < 5; i++){
        int o = rand()% 2;
        printf("%d", rand() % 90 + 10);

        if(o == 0) printf(" + ");
        else printf(" - ");

        printf("%d =\n", rand() % 90 + 10);
    }
}