#include"head.h"
int count_2 = 0;
struct num_2* line_2(void)
{
	struct num_2* pHead = NULL;
	struct num_2* pNew=NULL;
	struct num_2* pEnd = NULL;
	pNew = (struct num_2*)malloc(sizeof(struct num_2));
	printf("ÇëÊäÈëÊı×Ö\n");
	scanf("%d", &(pNew->number_2));
	while (pNew->number_2 >= 0)
	{
		count_2++;
		if (count_2 == 1)
		{
			pNew->pNext_2 = NULL;
			pHead = pEnd = pNew;
		}
		else
		{
			pNew->pNext_2 = NULL;
			pEnd->pNext_2 = pNew;
			pEnd = pNew;
		}
		pNew = (struct num_2*)malloc(sizeof(struct num_2));
		printf("ÇëÊäÈëÊı×Ö\n");
		scanf("%d", &(pNew->number_2));
	}
	free(pNew);
	return pHead;
}