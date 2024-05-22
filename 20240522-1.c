// 성격 유형 검사하기 (https://school.programmers.co.kr/learn/courses/30/lessons/118666)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* survey[], size_t survey_len, int choices[], size_t choices_len) {

    char* answer = (char*)malloc(5 * sizeof(char));

    char types[] = { 'R','T','C','F','J','M','A','N' };
    int scores[] = { 0,0,0,0,0,0,0,0 };

    for (int i = 0;i < survey_len;i++) {
        for (int j = 0;j < 8;j++) {
            if (survey[i][0] == types[j]) {
                scores[j] += 4 - choices[i];
            }
        }
    }

    for (int i = 0;i < 4;i++) {
        if (scores[2 * i + 1] > scores[2 * i])
            answer[i] = types[2 * i + 1];
        else
            answer[i] = types[2 * i];
    }

    answer[4] = '\0';

    return answer;
}

void main()
{
    const char* survey1[] = { "AN", "CF", "MJ", "RT", "NA" };
    const char* survey2[] = { "TR", "RT", "TR" };
    size_t survey_len1 = 5;
    size_t survey_len2 = 3;
    int choices1[] = { 5, 3, 2, 7, 5 };
    int choices2[] = { 7, 1, 3 };
    size_t choices_len1 = 5;
    size_t choices_len2 = 3;
    char* result1 = solution(survey1, survey_len1, choices1, choices_len1);
    char* result2 = solution(survey2, survey_len2, choices2, choices_len2);

    printf("%s\n", result1);
    printf("%s\n", result2);
    
    free(result1);
    free(result2);
}