/*
--draft--
รับค่า num
แสดงผล * เป็นรูปผีเสื้อตามค่า num
--simple command--
รับค่า num
i = 1
ทำงานต่อไปนี้ซ้ำถ้า i < num
    j = 0
    ทำงานต่อไปนี้ซ้ำถ้า j < i
        แสดง *
        j++
    j = 0
    ทำงานต่อไปนี้ซ้ำถ้า j < 2num - (2i + 1)
        แสดงผล ช่องว่างหนึ่งช่อง
        j++
    j = 0
    ทำงานต่อไปนี้ซ้ำถ้า j < i
        แสดง *
        j++
    i++
    ขึ้นบรรทัดใหม่
i = 0
ทำงานต่อไปนี้ซ้ำถ้า i < 2num - 1
    แสดงผล *
    i++
ขึ้นบรรทัดใหม่
i = 1
ทำงานต่อไปนี้ซ้ำถ้า i < num
    j = num
    ทำงานต่อไปนี้ซ้ำถ้า j > i
        แสดงผล *
        j--
    j = num
    ทำงานต่อไปนี้ซ้ำถ้า j > num - (2i - 1)
        แสดงผล ช่องว่างหนึ่งช่อง
        j--
    j = num
    ทำงานต่อไปนี้ซ้ำถ้า j > i
        แดสงผล *
        j--
    i++
    ขึ้นบรรทัดใหม่
*/
#include <stdio.h>

int main(){
    int i, j, num;

    scanf("%d", &num);

    for(i = 1; i < num; i++){
        for(j = 0; j < i; j++){
            printf("*");
        }
        for(j = 0; j < 2*num - (2*i+1); j++){
            printf(" ");
        }
        for(j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
    for(i = 0; i < 2 * num - 1; i++){
        printf("*");
    }
    printf("\n");

    for(i = 1; i < num; i++){
        for(j = num; j > i; j--){
            printf("*");
        }
        for(j = num; j > num - (2*i-1); j--){
            printf(" ");
        }
        for(j = num; j > i; j--){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}