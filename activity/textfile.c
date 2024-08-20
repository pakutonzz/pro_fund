#include <stdio.h>

int main(){
    struct player{
        char name[50];
        int lvl;
        int score;
    } p[5];

    FILE *fp;
    fp = fopen("textfile2.txt", "w");

    for (int i = 0 ; i < 5; i++){
        printf("player %d Name : ", i+1);
        scanf("%s", &p[i].name);
        printf("player %d level : ", i+1);
        scanf("%d", &p[i].lvl);
        printf("player %d score : ", i+1);
        scanf("%d", &p[i].score);
    }
        
    fwrite(&p, sizeof(struct player), 5, fp);
    fclose(fp);

    return 0;
}