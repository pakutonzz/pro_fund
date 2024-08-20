#include <stdio.h>
#include <string.h>

int main (){
    char *p , str[20];
    p = str;

    printf("str : ");
    scanf("%s", str);

    while(*p != '\0'){
        if (*p >= 'A' && *p <= 'Z'){
            printf("%c", *p+' ');;
        }
        else if (*p >= 'a' && *p <= 'z'){
            printf("%c", *p-' ');
        }
        p++;
    }
    return 0;
}