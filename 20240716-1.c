// 정수 제곱근 판별 (https://school.programmers.co.kr/learn/courses/30/lessons/12934?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(long long n) {

    double s = sqrt(n);

    if (fmod(s, 1.0) > 0.0)
        return -1;

    return (long long)(s + 1) * (long long)(s + 1);

}

void main()
{

    printf("%d %d", solution(121), solution(3));

}