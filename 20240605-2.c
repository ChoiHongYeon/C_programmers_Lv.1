// 3진법 뒤집기 (https://school.programmers.co.kr/learn/courses/30/lessons/68935)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    
    int x = 3;
    int changed_num_len = 0;
    if (n < 3) {
        changed_num_len = 1;
    }
    else {
        for (int i = 2;i <= 17;i++) {
            x *= 3;
            if (n < x) {
                changed_num_len = i;
                break;
            }
        }
    }

    int* changed_num = (int*)malloc(sizeof(int) * changed_num_len);
    x /= 3;
    for (int i = 0;i < changed_num_len;i++) {
        changed_num[i] = 0;
        changed_num[i] = (int)(n / x);
        n -= (changed_num[i] * x);
        x /= 3;
    }

    int answer = 0;
    x = 1;
    for (int i = 0;i < changed_num_len;i++) {
        answer += (x * changed_num[i]);
        x *= 3;
    }

    free(changed_num);
    return answer;

}

void main()
{
    printf("%d\n", solution(45));
    printf("%d", solution(125));
}