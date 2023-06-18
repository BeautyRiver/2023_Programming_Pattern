#pragma once
typedef struct Score {
	int score;
	char name[15];
}Score;

void recordScore(const char* fileName, Score score);
void loadAndSortScores(const char* fileName);