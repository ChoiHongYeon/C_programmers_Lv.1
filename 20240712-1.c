// 평균 구하기 (https://school.programmers.co.kr/learn/courses/30/lessons/12944?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
double solution(int arr[], size_t arr_len) {

    double answer = 0;

    for (int i = 0;i < arr_len;i++) {
        answer += (double)arr[i] / arr_len;
    }

    return answer;
}

void main()
{
    int arr1[] = { 1,2,3,4 };
    int arr2[] = { 5,5 };
    size_t arr1_len = 4;
    size_t arr2_len = 2;
    printf("%f\n", solution(arr1, arr1_len));
    printf("%f", solution(arr2, arr2_len));
}