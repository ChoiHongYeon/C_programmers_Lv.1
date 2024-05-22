// 개인정보 수집 유효기간 (https://school.programmers.co.kr/learn/courses/30/lessons/150370?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(const char* today, const char* terms[], size_t terms_len, const char* privacies[], size_t privacies_len) {

    int today_year, today_month, today_day;
    sscanf(today, "%d.%d.%d", &today_year, &today_month, &today_day);
    today_day += (today_year * 12 * 28) + (today_month * 28);
    
    char terms_type[20];
    int terms_day[20];
    for (int i = 0;i < terms_len;i++) {
        sscanf(terms[i], "%c %d", &terms_type[i], &terms_day[i]);
        terms_day[i] *= 28;
    }

    int privacies_day[100];
    char privacies_type[100];
    for (int i = 0;i < privacies_len;i++) {
        int privacies_year, privacies_month;
        sscanf(privacies[i], "%d.%d.%d %c", &privacies_year, &privacies_month, &privacies_day[i], &privacies_type[i]);
        privacies_day[i] += (privacies_year * 12 * 28) + (privacies_month * 28);
    }

    for (int i = 0;i < privacies_len;i++) {
        for (int j = 0;j < terms_len;j++) {
            if (privacies_type[i] == terms_type[j]) {
                privacies_day[i] += terms_day[j] - 1;
                break;
            }
        }
    }

    int answer_len = 0;
    for (int i = 0;i < privacies_len;i++) {
        if (today_day > privacies_day[i])
            answer_len++;
    }

    int* answer = (int*)malloc(sizeof(int) * answer_len);
    int k = 0;
    for (int i = 0;i < privacies_len;i++) {
        if (today_day > privacies_day[i])
            answer[k++] = i + 1;
    }

    return answer;
}

void main()
{
    const char* today1 = "2022.05.19";
    const char* today2 = "2020.01.01";
    const char* terms1[] = { "A 6", "B 12", "C 3" };
    const char* terms2[] = { "Z 3", "D 5" };
    size_t terms_len1 = 3;
    size_t terms_len2 = 2;
    const char* privacies1[] = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };
    const char* privacies2[] = { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" };
    size_t privacies_len1 = 4;
    size_t privacies_len2 = 5;
    int* result1 = solution(today1, terms1, terms_len1, privacies1, privacies_len1);
    int* result2 = solution(today2, terms2, terms_len2, privacies2, privacies_len2);

    printf("%d %d\n", result1[0], result1[1]);
    printf("%d %d %d\n", result2[0], result2[1], result2[2]);

    free(result1);
    free(result2);
}