#include"head.h"

struct num_fi* line_final(int *p)
{
	struct num_fi* pNew = NULL;
	struct num_fi* pEnd = NULL;
	struct num_fi* pHead = NULL;
	int i = 0;
	pNew = (struct num_fi*)malloc(sizeof(struct num_fi));
	if (count_1 + count_2 >= 1)
	{
		for (i = 0; i < (count_1 + count_2); i++)
		{
			if (i == 0)
			{
				pNew->number_fi = *(p + i);
				pNew->pNext_fi = NULL;
				pHead = pEnd = pNew;
			}
			else
			{
				pNew->number_fi = *(p + i);
				pNew->pNext_fi = NULL;
				pEnd->pNext_fi = pNew;
				pEnd = pNew;
			}
			pNew = (struct num_fi*)malloc(sizeof(struct num_fi));

		}
		
	}
	free(pNew);
	return pHead;
}