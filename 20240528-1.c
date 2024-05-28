// 부족한 금액 계산하기 (https://school.programmers.co.kr/learn/courses/30/lessons/82612?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    
    long long price_l = (long long)price;
    long long money_l = (long long)money;
    long long count_l = (long long)count;
    long long x;

    if (count_l % 2 == 0) {
        x = (count_l + 1) * (count_l / 2);
    }
    else {
        x = count_l * ((count_l - 1) / 2) + count_l;
    }
    
    long long answer = (x * price) - money;
    if (answer < 0)
        answer = 0;
    return answer;
}

void main()
{
    int price = 3, money = 20, count = 4;
    int result = solution(price, money, count);
    printf("%d", result);
}