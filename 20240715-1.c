// 짝수와 홀수 (https://school.programmers.co.kr/learn/courses/30/lessons/12937?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int num) {

    return num % 2 ? "Odd" : "Even";

}

void main()
{
    printf("%s %s", solution(3), solution(4));
}