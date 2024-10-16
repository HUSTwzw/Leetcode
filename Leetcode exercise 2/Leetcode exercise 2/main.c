//程序题目：
/*
给定一个长度为num的整数数组arr，有num条垂线第i条线的两个端点是(i,0)和(i,arr[i])
找出其中的两条线，使得它们与x轴共同构成的容器可以容纳最多的水
输出容器可以储存的最大水量，以及对应的两条边
（默认容器为长方体且底面宽固定为1，高和底面的长不确定，即体积=1*(i-j)*min{arr[i],arr[j]}）
*/


/*
此题既可以用暴力解法（遍历）也可以用双指针法
双指针法运算次数少，更高效
双指针法原理是两个指针变量分别储存数组的首地址与末地址，如果前指针对应的数比后指针对应的数小，那就使前指针向后移1，否则就使后指针向前移1
在移动过程中容器底面的长不断减小，所以如果指针移动后指向的数没有变大就不用再与max比较，直接进入下一次指针移动
直到前指针与后指针相邻时结束循环，开始输出
*/




#include<stdio.h>
void input(int *p);
void search(int *p1,int *p2,int arr[]);
int main(void)
{
int arr[100]={0};
int num=0;
printf("请问要输入几个数?");
scanf("%d",&num);
input(arr,num);
search(arr,arr+num-1,arr);
return 0;
}


void input(int *p,int num)
{
int i=0;
for(i=0;i<num;i++)
{
printf("请输入第%d个数:",i+1);
scanf("%d",p+i);
}
}


void search(int *p1,int *p2,int arr[])
{
int max=0;
int *p_1=p1;
int *p_2=p2;

if(*p1<*p2)
{
max=*p1*(p2-p1);
}
else
{
max=*p2*(p2-p1);
}
for(;p1<p2;)
{
if(*p1<*p2)
{
p1++;
}
else 
{
p2--;
}
if(*(p1-1)<*(p1)||*(p2+1)<*(p2))
{
if(*p1>*p2)
{
if(*p2*(p2-p1)>max)
{
max=*p2*(p2-p1);
p_1=p1;
p_2=p2;
}
}
else
{
if(*p1*(p2-p1)>max)
{
max=*p1*(p2-p1);
p_1=p1;
p_2=p2;
}
}
}
}
printf("%d\n",max);
printf("最大体积对应的直线是第%d条和第%d条\n",p_1-arr+1,p_2-arr+1);
}