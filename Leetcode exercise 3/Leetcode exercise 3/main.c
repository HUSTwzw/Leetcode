//������Ŀ��
/*
���������һ�����У����ǽ������г�Ա�����л�����˳������
���磬arr=[1,2,3]��������Щ����������arr�����У�[1,2,3]��[1,3,2]��[3,1,2]��[2,3,1]
�����������һ��������ָ����������һ���ֵ����������С�����ʽ�أ����������������и������ֵ�˳���С����������һ�������У���ô�������һ�����о������������������������������Ǹ�����
�����������һ����������У���ô��������������Ϊ�ֵ�����С�����У�������Ԫ�ذ��������У�
���磬arr=[1,2,3]����һ�������� [1,3,2]
���Ƶأ�arr= [2,3,1] ����һ��������[3,1,2]
��arr=[3,2,1]����һ��������[1,2,3]����Ϊ[3,2,1]������һ���ֵ�����������
*/




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define len 6
void output(int *p);
int main(void)
{
int arr[len]={0};
int i=0;
printf("����������\n");
for(i=0;i<len;i++)
{
scanf("%d",arr+i);
}
output(arr);
return 0;
}


void output(int *p)
{
int bridge=0;
int i=0;
int j=0;
int k=0;


if(*(p+len-1)>*(p+len-2))
{
bridge=*(p+len-2);
*(p+len-2)=*(p+len-1);
*(p+len-1)=bridge;
}


else
{
for(i=0;i<=len-2;)
{
if(*(p+len-1-i)<*(p+len-2-i))
{
i++;
}
else
{
break;
}
}

if(i>len-2)
{
for(i=0;i<len-1;i++)
{
for(j=0;j+1<len-i;j++)
{
if(*(p+j)>*(p+j+1))
{
bridge=*(p+j);
*(p+j)=*(p+j+1);
*(p+j+1)=bridge;
//printf("%d",*(p+j));
//printf("%d",*(p+j+1))
}
}
}
}

else
{
k=len-2-i;
for(i=0;i<len-2-k;i++)
{
for(j=k+1;j+1<len-i;j++)
{
if(*(p+j)>*(p+j+1))
{
bridge=*(p+j);
*(p+j)=*(p+j+1);
*(p+j+1)=bridge;
}
}
}
for(i=k+1;i<len&&*(p+i)<*(p+k);i++)
{
}
bridge=*(p+i);
*(p+i)=*(p+k);
*(p+k)=bridge;
}
}

for(i=0;i<len;i++)
{
printf("%d  ",*(p+i));
}
}