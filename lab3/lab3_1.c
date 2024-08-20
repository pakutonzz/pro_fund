/*
--draft--
รับค่า num
นำหลักของเลขแต่ละตัวมาบวกกัน
แสดงผลเลขใหม่
ถ้าหลักของเลขใหม่ที่ได้ยังไม่ใช่หลักเดียว
    นำเลขมาบวกกันอีกครั้ง
แสดงผลเลขใหม่

--simple command--
รับค่า num
ให้ทำงานต่อไปนี้ซ้ำไปเรื่อยๆ
    sum = 0
    ทำงานต่อไปนี้ซ้ำถ้า num ไม่เท่ากับ 0
        digit = เศษจากการหาร num ด้วย 10
        num = num หารด้วย 10
        sum = sum + digit
    แสดงค่า sum
    num = sum
    ถ้า num หารด้วย 10 แล้วมีค่าเป็น 0 ให้หยุดทำงาน
*/
#include <stdio.h>

int main(){
    int num, digit, sum;

    scanf("%d", &num);
    printf("%d", num);
    do{
        sum = 0;

        while(num != 0){
        digit = num % 10;
        num = num/10;
        sum += digit;
        }

        printf(" -> %d", sum);
        num = sum;

    }while(num / 10 != 0);
}