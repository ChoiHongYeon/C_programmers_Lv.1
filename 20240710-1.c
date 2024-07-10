// 하샤드 수 (https://school.programmers.co.kr/learn/courses/30/lessons/12947?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solution(int x) {

    char c[6];
    sprintf(c, "%d", x);

    int h = 0;
    for (int i = 0;i < strlen(c); i++) {
        h += c[i] - '0';
    }

    return x % h == 0;
}

void main()
{
    bool return1 = solution(10);
    bool return2 = solution(11);
    bool return3 = solution(12);
    bool return4 = solution(13);
    printf("%d %d %d %d", return1, return2, return3, return4);
}