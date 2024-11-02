#include"head.h"
int count_1 = 0;
struct num_1* line_1(void)
{
	struct num_1* pNew = NULL;
	struct num_1* pEnd = NULL;
	struct num_1* pHead = NULL;
	pNew = (struct num_1*)malloc(sizeof(struct num_1));
	printf("ÇëÊäÈëÊı×Ö\n");
	scanf("%d", &(pNew->number_1));
	while (pNew->number_1 >= 0)
	{
		count_1++;
		if (count_1 == 1)
		{
			pNew->pNext_1 = NULL;
			pHead = pEnd = pNew;
		}
		else
		{
			pNew->pNext_1 = NULL;
			pEnd->pNext_1 = pNew;
			pEnd = pNew;
		}
		pNew = (struct num_1*)malloc(sizeof(struct num_1));
		printf("ÇëÊäÈëÊı×Ö\n");
		scanf("%d", &(pNew->number_1));
	}
	free(pNew);
	return pHead;
}