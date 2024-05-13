// ªÔ√—ªÁ(https://school.programmers.co.kr/learn/courses/30/lessons/131705?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int number[], size_t number_len) {
    
    int answer = 0;

    for (int a = 0;a < number_len - 2;a++) {
        for (int b = a + 1;b < number_len - 1;b++) {
            for (int c = b + 1;c < number_len;c++) {
                if (number[a] + number[b] + number[c] == 0) {
                    answer++;
                }
            }
        }
    }

    return answer;
}

/*
void main()
{
    int A[] = { -2,3,0,2,-5 };
    int B[] = { -3,-2,-1,0,1,2,3 };
    int C[] = { -1,1,-1,1 };
    size_t a = sizeof(A) / sizeof(A[0]);
    size_t b = sizeof(B) / sizeof(B[0]);
    size_t c = sizeof(C) / sizeof(C[0]);
    int aa = solution(A, a);
    int bb = solution(B, b);
    int cc = solution(C, c);

    printf("%d %d %d", aa, bb, cc);
}
*/