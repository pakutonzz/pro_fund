#include <stdio.h>
#include <string.h>

int uniq(char stra[], char strb[]){
    char *ap, *bp;
    ap = stra, bp = strb;
    char temp[2];

    while(*ap != '\0' || *bp != '\0'){
        if(*ap != *bp){
            return 1;
        }
        
        temp[0] = *ap;
        temp[1] = *bp;
        ap++;
        bp++;

        while(temp[0] == *ap){
            temp[0] = *ap;
            ap++;
        }

        while(temp[1] == *bp){
            temp[1] = *bp;
            bp++;
        }
    }
    return 0;
}

int main (){
    char strA[50],strB[50];

    printf("strA : ");
    scanf("%s", strA);
    printf("strB : ");
    scanf("%s", strB);

    if (uniq(strA, strB) == 0) printf("same uniq");
    else printf("diff uniq");
}