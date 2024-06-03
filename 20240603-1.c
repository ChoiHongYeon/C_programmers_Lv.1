// 음양 더하기 (https://school.programmers.co.kr/learn/courses/30/lessons/76501?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) {
    
    int answer = 0;

    for (int i = 0;i < signs_len;i++) {
        if (signs[i] == true)
            answer += absolutes[i];
        else
            answer -= absolutes[i];
    }

    return answer;
}

void main() {
    int absolutes1[] = { 4,7,12 };
    int absolutes2[] = { 1,2,3 };
    size_t absolutes_len = 3;
    bool signs1[] = { true,false,true };
    bool signs2[] = { false,false,true };
    size_t signs_len = 3;
    int result1 = solution(absolutes1, absolutes_len, signs1, signs_len);
    int result2 = solution(absolutes2, absolutes_len, signs2, signs_len);
    printf("%d %d", result1, result2);
}