// 핸드폰 번호 가리기 (https://school.programmers.co.kr/learn/courses/30/lessons/12948?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* phone_number) {

    char* answer = (char*)malloc(sizeof(char) * (strlen(phone_number) + 1));

    for (int i = 0;i < strlen(phone_number) - 4;i++) {
        answer[i] = 42;
    }
    for (int i = strlen(phone_number) - 4;i < strlen(phone_number);i++) {
        answer[i] = phone_number[i];
    }
    answer[strlen(phone_number)] = '\0';

    return answer;
}

void main()
{
    char* phone_number1 = "01033334444";
    char* phone_number2 = "027778888";
    char* return1 = solution(phone_number1);
    char* return2 = solution(phone_number2);
    printf("%s %s", return1, return2);
}