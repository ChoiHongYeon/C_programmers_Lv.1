// 자연수 뒤집어 배열로 만들기 (https://school.programmers.co.kr/learn/courses/30/lessons/12932?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {

    long long number = 1;
    int size = 0;
    while (n >= number) {
        number *= 10;
        size++;
    }

    int* answer = (int*)malloc(sizeof(int) * size);
    int count = 0;

    while (n > 0) {
        answer[count] = n % 10;
        n /= 10;
        count++;
    }

    return answer;
}

void main()
{
    int* result = solution(12345);
    for (int i = 0;i < 5;i++) {
        printf("%d ", result[i]);
    }
}