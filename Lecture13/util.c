#include "util.h"

//오류검사
void CHECKERROR(int e)
{
	if (e == 1)
	{
		printf("\n[line:%d, %s]에러 발생\n", __LINE__, __func__);
		exit(1);
	}
}