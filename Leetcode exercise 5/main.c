//程序题目：将正序链表改为逆序链表
/*
例如，输入[1，3，4，9，0]链表，返回[0，9，4，3，1]链表
*/




#include<stdio.h>
#include<stdlib.h>
struct book
{
    int num;
    struct book *pNext;
};


struct book * input(int n);
void sequence(struct book *pHead);
struct book * reverse(struct book*pFront);
extern struct book*rev_pHead;
int main(void)
{   
    int n=0;
    printf("请输入链表长度");
    scanf("%d",&n);
    getchar();
    struct book *pHead=input(n);
    printf("正顺序:");
    sequence(pHead);
    printf("\n");
    struct book *temp=reverse(pHead);
    temp->pNext=NULL;
    printf("逆顺序:");
    sequence(rev_pHead);
    return 0;
}


struct book * input(int n)
{
    if (n<1)
    {
        printf("输入错误\n");
        return -1;
    }
    else
    {
        struct book *pHead;
        struct book *pNew;
        pNew=pHead=(struct book *)malloc(sizeof(struct book));
        pNew->pNext=NULL;
        for (int i=1;i<=n;i++)
        {
            printf("请输入第%d个数",i);
            scanf("%d",&(pNew->num));
            getchar();
            if(i+1<=n)
            {
                pNew=pNew->pNext=(struct book *)malloc(sizeof(struct book));
                pNew->pNext=NULL;
            }
        }
        return pHead;
    }
}


void sequence(struct book *pHead)
{
    for (struct book * p1=pHead;;)
    {
        printf("%d",p1->num);
        if (p1->pNext==NULL)
        {
            break;
        }
        else
        {
            p1=p1->pNext;
        }
    }
}


struct book * rev_pHead;
struct book * reverse(struct book*pFront)
{
    if (pFront->pNext==NULL)
    {
        static struct book*rev_pNew;
        rev_pNew=rev_pHead=(struct book*)malloc(sizeof(struct book));
        rev_pNew->num=pFront->num;
        return rev_pNew;
    }
    else
    {
        static struct book *rev_pNew;
        struct book *rev_temp;
        rev_temp=reverse(pFront->pNext);
        rev_pNew=rev_temp->pNext=(struct book*)malloc(sizeof(struct book));
        rev_pNew->num=pFront->num;
        return rev_pNew;
    }
}