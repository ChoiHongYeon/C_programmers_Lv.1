// 약수의 개수와 덧셈 (https://school.programmers.co.kr/learn/courses/30/lessons/77884?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int left, int right) {
    
    int answer = 0;

    for (int i = left;i <= right;i++) {
        int num = 0;
        for (int j = 1;j <= i;j++) {
            if (i % j == 0)
                num++;
        }
        if (num % 2 == 0)
            answer += i;
        else
            answer -= i;
    }

    return answer;
}

void main()
{
    int left1 = 13, right1 = 17, left2 = 24, right2 = 27;
    int answer1 = solution(left1, right1);
    int answer2 = solution(left2, right2);
    printf("%d %d", answer1, answer2);
}