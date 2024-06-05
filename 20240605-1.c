// 내적 (https://school.programmers.co.kr/learn/courses/30/lessons/70128?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// a_len은 배열 a의 길이입니다.
// b_len은 배열 b의 길이입니다.
int solution(int a[], size_t a_len, int b[], size_t b_len) {
    
    int answer = 0;

    for (int i = 0;i < a_len;i++) {
        answer += (a[i] * b[i]);
    }

    return answer;
}

void main()
{
    int a1[] = { 1,2,3,4 };
    int a2[] = { -1,0,1 };
    int b1[] = { -3,-1,0,2 };
    int b2[] = { 1,0,-1 };
    int result1 = solution(a1, 4, b1, 4);
    int result2 = solution(a2, 3, b2, 3);
    printf("%d %d", result1, result2);

}