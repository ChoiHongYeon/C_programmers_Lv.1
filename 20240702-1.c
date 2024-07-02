// 소수 만들기 (https://school.programmers.co.kr/learn/courses/30/lessons/12977?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int nums[], size_t nums_len) {
    
    int answer = 0;
    for (int i = 0; i < nums_len - 2; i++) {
        for (int j = i + 1;j < nums_len - 1;j++) {
            for (int k = j + 1; k < nums_len; k++) {
                int number = nums[i] + nums[j] + nums[k];
                int n = 0;
                for (int l = 2;l < number;l++) {
                    if (number % l == 0) {
                        n = 1;
                        break;
                    }
                }
                if (n == 0)
                    answer++;
            }
        }
    }

    return answer;
}

void main()
{
    int nums1[] = { 1,2,3,4 };
    int nums2[] = { 1,2,7,6,4 };
    size_t nums_len1 = 4;
    size_t nums_len2 = 5;
    int result1 = solution(nums1, nums_len1);
    int result2 = solution(nums2, nums_len2);
    printf("%d %d", result1, result2);
}