//程序题目：
/*
整数数组的一个排列，就是将其所有成员以序列或线性顺序排列
例如，arr=[1,2,3]，以下这些都可以视作arr的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1]
整数数组的下一个排列是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的下一个排列就是在这个有序容器中排在它后面的那个排列
如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）
例如，arr=[1,2,3]的下一个排列是 [1,3,2]
类似地，arr= [2,3,1] 的下一个排列是[3,1,2]
而arr=[3,2,1]的下一个排列是[1,2,3]，因为[3,2,1]不存在一个字典序更大的排列
*/




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define len 6
void output(int *p);
int main(void)
{
int arr[len]={0};
int i=0;
printf("请输入数字\n");
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