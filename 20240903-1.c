// 이상한 문자 만들기 (https://school.programmers.co.kr/learn/courses/30/lessons/12930?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* solution(const char* s) {

    char* answer = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    int count = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            answer[i] = ' ';
            count = 0;
        }
        else if (count % 2 == 0) {
            answer[i] = toupper(s[i]);
            count++;
        }
        else {
            answer[i] = tolower(s[i]);
            count++;
        }
    }
    answer[strlen(s)] = '\0';

    return answer;
}

void main()
{

    const char* s = "try hello world";
    char* result = solution(s);
    printf("%s", result);

}