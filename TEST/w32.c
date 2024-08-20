#include <stdio.h>
#include <string.h>

int main(){
    char hex[100];
    int dec = 0, length, val;

    gets(hex);
    length = strlen(hex);

    for(int i = 0; i < length; i++){
        if(hex[i] >= '0' && hex[i] <= '9'){
            dec = dec * 16 + (hex[i] - '0');
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F'){
            dec = dec * 16 + (hex[i] - 'A' + 10);
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f'){
            dec = dec * 16 + (hex[i] - 'a' + 10);
        }

        
    }

    printf("%d", dec);
}
