// 수박수박수박수박수박수? (https://school.programmers.co.kr/learn/courses/30/lessons/12922?language=c)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int n) {

    char* answer = (char*)malloc(sizeof(char) * (n * 3 + 1));
    memset(answer, 0, sizeof(char) * (n * 3 + 1));
    char* su = "수";
    char* bak = "박";

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            strcat(answer, su);
        else
            strcat(answer, bak);
    }
    answer[n * 3] = '\0';

    return answer;
}

void main()
{

    printf("%s", solution(3));
    printf("\n");
    printf("%s", solution(4));

}