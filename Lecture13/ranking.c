#define _CRT_SECURE_NO_WARNINGS
#include "ranking.h"
#include "screen.h"
// ������ �̸��� ��� ����ü

// ���Ͽ� ������ ����ϴ� �Լ�
void recordScore(const char* fileName, Score score)
{
    // ���� ���("a")
    FILE* file = fopen(fileName, "a+");
    if (file != NULL) 
    {      
        fprintf(file, "%s %d\n", score.name, score.score);        
        fclose(file);
    }
    else 
        printf("Failed to open the file\n");
}

// ���Ϸκ��� ������ �ҷ�����, �����Ͽ� ����ϴ� �Լ�
void loadAndSortScores(const char* fileName)
{
    Score scores[50];
    int count = 0;

    //�б� ���("r")
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

    // ������ ������������ ����
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = i + 1; j < count; ++j)
        {
            if (scores[i].score < scores[j].score)
            {
                // ������ �� ���� ��Ҹ� ã���� �� ��Ҹ� ��ȯ
                Score temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }

    // ��ŷ�� ���
    for (int i = 0; i < count && i < 10; ++i)
    {
        setCursorPos(20, 3 + i);

        if (i == 0) //1�� �ݻ�
            SetColor(0, 14); 

        else if (i == 1) //2�� ����
            SetColor(0, 8); 

        else if (i == 2) //3�� ����
            SetColor(0, 6); 
        
        else
            SetColor(0, 15); 

        printf("[%2d��] %-15s  %5d Score\n", i + 1, scores[i].name, scores[i].score);
        
    }

}
