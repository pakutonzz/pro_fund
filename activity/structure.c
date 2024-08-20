#include <stdio.h>
#include <string.h>

int main(){
    struct student{
        int id;
        char name[50];
        int age;
    };
    struct student s[10];
    int i;
    
    for ( i = 0 ; i < 3; i++){
        printf("student %d ID : ", i+1);
        scanf("%d", &s[i].id);
        printf("student %d Name : ", i+1);
        scanf("%s", &s[i].name);
        printf("student %d Age : ", i+1);
        scanf("%d", &s[i].age);
    }

    printf("-student list-\n");
    for ( i = 0 ; i < 3; i++){
        printf("student %d : %d %s %d\n", i+1,  s[i].id, s[i].name, s[i].age);
    }
}