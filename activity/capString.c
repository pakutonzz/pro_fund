#include <stdio.h>
#include <string.h>

int main(){
    char s[100];
    
    scanf("%s", &s);

    int length = strlen(s);

    for(int i = 0; i < length; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            printf("%c", s[i]);
        }
    }
return 0;
}