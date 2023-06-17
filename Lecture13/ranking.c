#define _CRT_SECURE_NO_WARNINGS
#include "screen.h"
// 점수와 이름을 담는 구조체
typedef struct Score
{
    int score;
    char name[15];
} Score;

// 파일에 점수를 기록하는 함수
void recordScore(const char* fileName, Score score)
{
    // 수정 모드("a")
    FILE* file = fopen(fileName, "a");
    if (file != NULL) 
    {      
        fprintf(file, "%s %d\n", score.name, score.score);        
        fclose(file);
    }
    else 
        printf("Failed to open the file\n");
}

// 파일로부터 점수를 불러오고, 정렬하여 출력하는 함수
void loadAndSortScores(const char* fileName)
{
    Score scores[50];
    int count = 0;

    //읽기 모드("r")
    FILE* file = fopen(fileName, "r");
    if (file == NULL) 
    {
        perror("Error opening file");
        return;
    }
    if (file != NULL) 
    {
        while (fscanf(file, "%s %d", scores[count].name, &scores[count].score) == 2) 
        {
            count++;
        }
        fclose(file);
    }
    else 
    {
        printf("Failed to open the file\n");
    }

    // 점수를 내림차순으로 정렬
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = i + 1; j < count; ++j)
        {
            if (scores[i].score < scores[j].score)
            {
                // 점수가 더 높은 요소를 찾으면 두 요소를 교환
                Score temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }

    // 랭킹을 출력
    for (int i = 0; i < count && i < 10; ++i)
    {
        setCursorPos(20, 3 + i);
        printf("[%2d등] %-15s  %5d Score\n", i + 1, scores[i].name, scores[i].score);
        
    }

}
