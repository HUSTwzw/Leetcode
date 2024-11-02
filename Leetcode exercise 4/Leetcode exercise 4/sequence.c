#include"head.h"
int* sequence(int* p)
{
	int i = 0;
	int j = 0;
	int tran = 0;
	for (i=0;i<count_1+count_2-1;i++)
	{
		for (j=0;j+1<count_1+count_2-i;j++)
		{
			if (*(p + j)> *(p + j + 1))
			{
				tran = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = tran;
			}
		}
	}
	return p;
}