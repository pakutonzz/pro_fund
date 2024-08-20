#include <stdio.h>
#include <string.h>

int main(){
    char *lp, *rp, str[100];
    lp = str, rp = str;

    scanf("%s", str);
    rp += strlen(str) - 1;

    for(*lp, *rp; lp < rp; lp++, rp--){
        if(*lp != *rp){
            printf("Not ");
            break;
        }
    }
    printf("Palindrome");
}