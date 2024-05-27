// 신고 결과 받기 (https://school.programmers.co.kr/learn/courses/30/lessons/92334?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// id_list_len은 배열 id_list의 길이입니다.
// report_len은 배열 report의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    int** relation = (int**)malloc(sizeof(int*) * id_list_len);
    int* report_number = (int*)malloc(sizeof(int) * id_list_len);
    char* report_a = (char*)malloc(sizeof(char) * report_len);
    char* report_b = (char*)malloc(sizeof(char) * report_len);

    for (int i = 0; i < id_list_len;i++) {
        relation[i] = (int*)malloc(sizeof(int) * id_list_len);
        for (int j = 0;j < id_list_len;j++) {
            relation[i][j] = 0;
        }
        report_number[i] = 0;
    }

    for (int i = 0;i < report_len;i++) {
        int a, b;
        sscanf(report[i], "%s %s", report_a[i], report_b[i]);
        for (int j = 0;j < id_list_len;j++) {
            if (strcmp(report_a[i], id_list[j]) == 0) {
                a = j;
                break;
            }
        }
        for (int j = 0;j < id_list_len;j++) {
            if (strcmp(report_b[i], id_list[j]) == 0) {
                b = j;
                break;
            }
        }
        if (relation[a][b] == 0)
            relation[a][b]++;
    }

    int* answer = (int*)malloc(sizeof(int) * id_list_len);

    for (int i = 0;i < id_list_len;i++) {
        for (int j = 0;j < id_list_len;j++) {
            report_number[i] += relation[i][j];
        }
        answer[i] = 0;
    }

    for (int i = 0;i < id_list_len;i++) {
        if (report_number[i] >= k) {
            for (int j = 0;j < id_list_len;j++) {
                if (relation[j][i] != 0)
                    answer[j]++;
            }
        }
    }

    for (int i = 0;i < id_list_len;i++) {
        free(relation[i]);
    }
    free(report_number);
    free(report_a);
    free(report_b);
    
    return answer;
}

void main()
{
    const char* id_list1[] = { "muzi", "frodo", "apeach", "neo" };
    const char* id_list2[] = { "con", "ryan" };
    size_t id_list_len1 = 4;
    size_t id_list_len2 = 2;
    const char* report1[] = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    const char* report2[] = { "ryan con", "ryan con", "ryan con", "ryan con" };
    size_t report_len1 = 5;
    size_t report_len2 = 4;
    int k1 = 2;
    int k2 = 3;
    int* result1 = solution(id_list1, id_list_len1, report1, report_len1, k1);
    int* result2 = solution(id_list2, id_list_len2, report2, report_len2, k2);

    for (int i = 0;i < 4;i++) {
        printf("%d ", result1[i]);
    }
    free(id_list1);
    free(report1);
    free(result1);
    printf("\n");

    for (int i = 0;i < 2;i++) {
        printf("%d ", result2[i]);
    }
    free(id_list2);
    free(report2);
    free(result2);
    printf("\n");

}