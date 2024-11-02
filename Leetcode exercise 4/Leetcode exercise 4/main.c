//程序题目：
/*
输入两个数字链表，两个链表的数字以正序排列，并由此构建一个新链表
*/




#include"head.h"
int number[len];
int main(void)
{
	int number[len];
	int* p = number;
	struct num_1* p_1;
	struct num_2* p_2;
	struct num_fi* p_fi;
	int i = 0;
	int j = 0;
	p_1 = line_1();

	for (i = 0; p_1 != NULL; i++)
	{
		number[i] = p_1->number_1;
		p_1 = p_1->pNext_1;
	}

	p_2 = line_2();
	for (; p_2 != NULL; i++)
	{
		number[i] = p_2->number_2;
		p_2 = p_2->pNext_2;
	}
	
	p = sequence(p);

	p_fi = line_final(p);
	if (p_fi==NULL)
	{
		printf("空链表\n");
	}
	else
	{
		while (p_fi != NULL)
		{
			printf("%d  ", p_fi->number_fi);
			p_fi = p_fi->pNext_fi;
		}
	}
	return 0;
}