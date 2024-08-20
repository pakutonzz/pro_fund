/*
--draft--
num = เลขทุกตัวตั้งแต่ 1 - 10,000
sum = ผลบวกของตัวประกอบของ num
ถ้า sum = num
    แสดงผล num
    
--simple command--
ให้ num = 1
    ทำงานต่อไปนี้ซ้ำถ้า num <= 10,000
        sum = 0
        i = 1
        ทำงานต่อไปนี้ซ้ำถ้า i < num
            ถ้า i หาร num ลงตัว
                sum = sum + i
            i++
        ถ้า num = sum
            แสดงค่า num
        num++
*/
#include <stdio.h>

int main(){
    int i, num, sum;
    
    for(num = 1; num <= 10000; num++){
        sum = 0;
        for(i = 1; i < num; i++){
            if(num % i == 0){
            sum += i;
        }
    }
    if(num == sum) printf("%d ", num);
    }

    return 0;
}