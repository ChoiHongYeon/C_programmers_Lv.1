// 문자열 다루기 기본 (https://school.programmers.co.kr/learn/courses/30/lessons/12918?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solution(const char* s) {

    bool answer = false;

    if (strlen(s) == 4 || strlen(s) == 6)
        answer = true;

    for (int i = 0; i < strlen(s); i++) {
        if (answer == true) {
            if (s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9')
                answer = false;
        }
    }

    return answer;
}

void main()
{

    const char* s1 = "a234";
    const char* s2 = "1234";
    printf("%d\n", solution(s1));
    printf("%d", solution(s2));

}