// 개인정보 수집 유효기간 (https://school.programmers.co.kr/learn/courses/30/lessons/150370?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(const char* today, const char* terms[], size_t terms_len, const char* privacies[], size_t privacies_len) {

    char* terms_type = (char*)malloc(sizeof(char) * terms_len);
    int* terms_month = (int*)malloc(sizeof(int) * terms_len);
    int* privacies_year = (int*)malloc(sizeof(int) * privacies_len);
    int* privacies_month = (int*)malloc(sizeof(int) * privacies_len);
    int* privacies_date = (int*)malloc(sizeof(int) * privacies_len);
    char* privacies_type = (char*)malloc(sizeof(char) * privacies_len);

    int today_year, today_month, today_date;
    sscanf(today, "%d.%d.%d", &today_year, &today_month, &today_date);

    for (int i = 0;i < terms_len;i++) {
        sscanf(terms[i], "%c %d", &terms_type[i], &terms_month[i]);
    }

    for (int i = 0;i < privacies_len;i++) {
        sscanf(privacies[i], "%d.%d.%d %c", &privacies_year[i], &privacies_month[i], &privacies_date[i], &privacies_type[i]);
    }

    for (int i = 0;i < privacies_len;i++) {
        for (int j = 0;j < terms_len;j++) {
            if (privacies_type[i] == terms_type[j]) {
                privacies_month[i] += terms_month[j];
                break;
            }
        }
        while (privacies_month[i] > 12) {
            privacies_month[i] -= 12;
            privacies_year[i]++;
        }
    }

    int answer_len = 0;
    for (int i = 0;i < privacies_len;i++) {
        if (privacies_year[i] > today_year)
            answer_len++;
        else if (privacies_year[i] == today_year && privacies_month[i] > today_month)
            answer_len++;
        else if (privacies_year[i] == today_year && privacies_month[i] == today_month && privacies_date[i] > today_date)
            answer_len++;
    }

    int* answer = (int*)malloc(sizeof(int) * answer_len);
    int k = 0;
    for (int i = 0;i < privacies_len;i++) {
        if (privacies_year[i] > today_year)
            answer[k++] = i;
        else if (privacies_year[i] == today_year && privacies_month[i] > today_month)
            answer[k++] = i;
        else if (privacies_year[i] == today_year && privacies_month[i] == today_month && privacies_date[i] > today_date)
            answer[k++] = i;
    }

    free(terms_type);
    free(terms_month);
    free(privacies_year);
    free(privacies_month);
    free(privacies_date);
    free(privacies_type);

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
    int result_len1 = sizeof(result1) / sizeof(result1[0]);
    int result_len2 = sizeof(result2) / sizeof(result2[0]);

    for (int i = 0;i < result_len1;i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    for (int i = 0;i < result_len2;i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");

    free(result1);
    free(result2);
}