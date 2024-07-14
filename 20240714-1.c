// 콜라츠 추측 (https://school.programmers.co.kr/learn/courses/30/lessons/12943?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {

    if (num == 1)
        return 0;

    long long l_num = (long long)num;
    int answer = 0;
    for (int i = 0;i < 500;i++) {
        if (l_num % 2)
            l_num = (l_num * 3) + 1;
        else
            l_num /= 2;
        answer++;
        if (l_num == 1)
            return answer;
    }

    return -1;
}

void main()
{
    int result1 = solution(6);
    int result2 = solution(16);
    int result3 = solution(626331);
    printf("%d %d %d", result1, result2, result3);
}