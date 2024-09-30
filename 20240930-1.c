// 두 정수 사이의 합 (https://school.programmers.co.kr/learn/courses/30/lessons/12912?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {

    long long answer = 0;
    long long max = (a > b) ? (long long)a : (long long)b;
    long long min = (a > b) ? (long long)b : (long long)a;

    if ((a + b) % 2 == 0)
        answer = (max + min) / 2 * (max - min + 1);
    else
        answer = (max + min) * (max - min + 1) / 2;

    return answer;
}

void main()
{

    long long return1 = solution(3, 5);
    long long return2 = solution(3, 3);
    long long return3 = solution(5, 3);
    printf("%lld %lld %lld", return1, return2, return3);

}