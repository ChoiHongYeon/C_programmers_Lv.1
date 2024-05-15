// [PCCP 기출문제] 1번 / 붕대 감기 (https://school.programmers.co.kr/learn/courses/30/lessons/250137?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len은 배열 bandage의 길이입니다.
// attacks_rows는 2차원 배열 attacks의 행 길이, attacks_cols는 2차원 배열 attacks의 열 길이입니다.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    
    int now_health = health;
    int time = 0;
    int attack_time = 0;
    int success_time = 0;

    for (time = 1; time <= attacks[attacks_cols - 1][0]; time++) {
        if (time == attacks[attack_time][0]) {
            success_time = 0;
            now_health -= attacks[attack_time][1];
            attack_time++;
        }
        else {
            now_health += bandage[1];
            success_time += 1;
            if (success_time == bandage[0]) {
                success_time = 0;
                now_health += bandage[2];
            }
            if (now_health > health)
                now_health = health;
        }
        if (now_health <= 0)
            break;
    }
    
    int answer = now_health;
    if (now_health <= 0)
        return -1;
    return answer;
}

void main()
{
    int bandage1[] = { 5,1,5 };
    int bandage2[] = { 3,2,7 };
    int bandage3[] = { 4,2,7 };
    int bandage4[] = { 1,1,1 };
    size_t bandage_len = sizeof(bandage1) / sizeof(bandage1[0]);
    int health1 = 30;
    int health2 = 20;
    int health3 = 20;
    int health4 = 5;
    size_t size2 = 2;
    size_t size3 = 3;
    size_t size4 = 4;
    
    int** attacks1 = (int**)malloc(size4 * sizeof(int*));
    attacks1[0] = (int*)malloc(2 * sizeof(int));
    attacks1[1] = (int*)malloc(2 * sizeof(int));
    attacks1[2] = (int*)malloc(2 * sizeof(int));
    attacks1[3] = (int*)malloc(2 * sizeof(int));
    attacks1[0][0] = 2; attacks1[0][1] = 10;
    attacks1[1][0] = 9; attacks1[1][1] = 15;
    attacks1[2][0] = 10; attacks1[2][1] = 5;
    attacks1[3][0] = 11; attacks1[3][1] = 5;

    int** attacks2 = (int**)malloc(size3 * sizeof(int*));
    attacks2[0] = (int*)malloc(2 * sizeof(int));
    attacks2[1] = (int*)malloc(2 * sizeof(int));
    attacks2[2] = (int*)malloc(2 * sizeof(int));
    attacks2[0][0] = 1; attacks2[0][1] = 15;
    attacks2[1][0] = 5; attacks2[1][1] = 16;
    attacks2[2][0] = 8; attacks2[2][1] = 6;

    int** attacks3 = (int**)malloc(size3 * sizeof(int*));
    attacks3[0] = (int*)malloc(2 * sizeof(int));
    attacks3[1] = (int*)malloc(2 * sizeof(int));
    attacks3[2] = (int*)malloc(2 * sizeof(int));
    attacks3[0][0] = 1; attacks3[0][1] = 15;
    attacks3[1][0] = 5; attacks3[1][1] = 16;
    attacks3[2][0] = 8; attacks3[2][1] = 6;

    int** attacks4 = (int**)malloc(size2 * sizeof(int*));
    attacks4[0] = (int*)malloc(2 * sizeof(int));
    attacks4[1] = (int*)malloc(2 * sizeof(int));
    attacks4[0][0] = 1; attacks4[0][1] = 2;
    attacks4[1][0] = 3; attacks4[1][1] = 2;

    int result1 = solution(bandage1, bandage_len, health1, attacks1, size4, size2);
    int result2 = solution(bandage2, bandage_len, health2, attacks2, size3, size2);
    int result3 = solution(bandage3, bandage_len, health3, attacks3, size3, size2);
    int result4 = solution(bandage4, bandage_len, health4, attacks4, size4, size2);

    printf("%d\n", result1);
    printf("%d\n", result2);
    printf("%d\n", result3);
    printf("%d\n", result4);

}