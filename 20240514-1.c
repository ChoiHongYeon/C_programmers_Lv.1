// 숫자 짝꿍 (https://school.programmers.co.kr/learn/courses/30/lessons/131128?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* X, const char* Y) {

    int X_len = strlen(X);
    int Y_len = strlen(Y);
    int X_count[] = { 0,0,0,0,0,0,0,0,0,0 };
    int Y_count[] = { 0,0,0,0,0,0,0,0,0,0 };
    int X_Y[] = { 0,0,0,0,0,0,0,0,0,0 };

    for (int i = 0; i < X_len;i++) {
        X_count[X[i] - '0']++;
    }
    for (int i = 0;i < Y_len;i++) {
        Y_count[Y[i] - '0']++;
    }
    for (int i = 0;i < 10;i++) {
        if (X_count[i] > Y_count[i])
            X_Y[i] = Y_count[i];
        else
            X_Y[i] = X_count[i];
    }

    int answer_len = 0;
    for (int i = 0;i < 10;i++) {
        answer_len += X_Y[i];
    }
    
    char* answer;
    int a = 0;
    if (answer_len == 0) {
        answer = (char*)malloc(sizeof(char) * 3);
        answer[0] = '-';
        answer[1] = '1';
        answer[2] = '\0';
    }
    else if (answer_len == X_Y[0]) {
        answer = (char*)malloc(sizeof(char) * 2);
        answer[0] = '0';
        answer[1] = '\0';
    }
    else {
        answer = (char*)malloc(sizeof(char) * (answer_len + 1));
        for (int i = 9;i >= 0;i--) {
            for (int j = 0;j < X_Y[i];j++) {
                answer[a++] = i + '0';
            }
        }
        answer[answer_len] = '\0';
    }

    return answer;
}

void main()
{
    char* X1 = "100";
    char* X2 = "100";
    char* X3 = "100";
    char* X4 = "12321";
    char* X5 = "5525";

    char* Y1 = "2345";
    char* Y2 = "203045";
    char* Y3 = "123450";
    char* Y4 = "42531";
    char* Y5 = "1255";

    char* result1 = solution(X1, Y1);
    char* result2 = solution(X2, Y2);
    char* result3 = solution(X3, Y3);
    char* result4 = solution(X4, Y4);
    char* result5 = solution(X5, Y5);

    printf("%s\n", result1);
    free(result1);
    printf("%s\n", result2);
    free(result2);
    printf("%s\n", result3);
    free(result3);
    printf("%s\n", result4);
    free(result4);
    printf("%s\n", result5);
    free(result5);

}