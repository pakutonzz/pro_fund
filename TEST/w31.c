#include <stdio.h>
#include <string.h>

int Searching(char *long_str, char *sub_str){
    int long_length = strlen(long_str);
    int sub_length = strlen(sub_str);
    int i, j;
    for(int i = 0; i <= long_length - sub_length; i++){
        for(j = 0; j < sub_length; j++){
            if(long_str[i + j] != sub_str[j])
            break;
        }
        if ( j == sub_length) return i;
    }
    return -1;
}

int main(){
    char longstr[100], substr[100];
    int result;

    gets(longstr);
    gets(substr);
    
    result = Searching(longstr, substr);

    printf("%d", result);

    return 0;
}