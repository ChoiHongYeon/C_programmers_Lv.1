// 가운데 글자 가져오기 (https://school.programmers.co.kr/learn/courses/30/lessons/12903?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* s) {

    char* answer = (char*)malloc(sizeof(char) * (3 - (strlen(s) % 2)));
    
    if (strlen(s) % 2 == 1) {
        int n = strlen(s) / 2;
        answer[0] = s[n];
        answer[1] = '\0';
    }
    else {
        int n = strlen(s) / 2 - 1;
        answer[0] = s[n];
        answer[1] = s[n + 1];
        answer[2] = '\0';
    }

    return answer;
}

void main()
{

    char* s1 = "abcde";
    char* s2 = "qwer";
    printf("%s\n", solution(s1));
    printf("%s", solution(s2));

}