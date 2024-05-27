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
    int* reported_num = (int*)malloc(sizeof(int) * id_list_len);
    int* answer = (int*)malloc(sizeof(int) * id_list_len);

    for (int i = 0;i < id_list_len;i++) {
        relation[i] = (int*)malloc(sizeof(int) * id_list_len);
        for (int j = 0;j < id_list_len;j++) {
            relation[i][j] = 0;
        }
        reported_num[i] = 0;
        answer[i] = 0;
    }

    for (int i = 0;i < report_len;i++) {
        char A[11];
        char B[11];
        int a, b;
        sscanf(report[i], "%s %s", A, B);
        for (int j = 0;j < id_list_len;j++) {
            if (strcmp(A, id_list[j]) == 0) {
                a = j;
                break;
            }
        }
        for (int j = 0;j < id_list_len;j++) {
            if (strcmp(B, id_list[j]) == 0) {
                b = j;
                break;
            }
        }
        if (relation[a][b] == 0)
            relation[a][b]++;
    }

    for (int i = 0;i < id_list_len;i++) {
        for (int j = 0;j < id_list_len;j++) {
            reported_num[i] += relation[j][i];
        }
    }

    for (int i = 0;i < id_list_len;i++) {
        if (reported_num[i] >= k) {
            for (int j = 0;j < id_list_len;j++) {
                if (relation[j][i] != 0)
                    answer[j]++;
            }
        }
    }
    
    for (int i = 0;i < id_list_len;i++) {
        free(relation[i]);
    }
    free(relation);
    free(reported_num);

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
    printf("\n");
    for (int i = 0;i < 2;i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");

    free(result1);
    free(result2);

}