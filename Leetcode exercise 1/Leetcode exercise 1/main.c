//������Ŀ����һ����������arr,�ж��Ƿ������Ԫ��arr[i].arr[j],arr[k]
/*
��Ԫ������i!=j,j!=k,i!=k,ͬʱ������arr[i]+arr[j]+arr[k]==0
�뷵�����к�Ϊ0�Ҳ��ظ�����Ԫ��

ʾ��
���룺arr[6]={-1,0,1,2,-1,-4}
�����[ -1 ,-1 ,2 ]
      [ -1 ,0 ,1 ]
���ͣ�
arr[0]+arr[1]+arr[2]=(-1)+0+1=0 
arr[1]+arr[2]+arr[4]=0+1+(-1)=0 
arr[0]+arr[3]+arr[4]=(-1)+2+(-1)=0 
��ͬ����Ԫ���� [ -1 ,0 ,1 ]��[ -1 ,-1 ,2 ] 
ע�⣬�����˳�����Ԫ���˳�򲢲���Ҫ
*/




#include<stdio.h>
#define len 6
void input(int *p);
void calculation(int *p);
void sequence(int *p);
int main(void)
{
int arr[len]={0};
input(arr);
calculation(arr);
return 0;
}


void input(int *p)
{
int i=0;
for(i=0;i<=len-1;i++)
{
printf("�������%d����:",i+1);
scanf("%d",p+i);
}
}


void calculation(int *p)
{
int i=0;
int j=0;
int k=0;
int arr[3]={0};
int num=0;
int flag2=0;
int h=0;
int flag=0;
int a_r_r[100]={1};
int q=0;
int r=0;

for(i=0;i<=len-3;i++)
{
for(j=i+1;j<=len-2;j++)
{
for(k=j+1;k<=len-1;k++)
{
if(*(p+i)+*(p+j)+*(p+k)==0)
{
arr[0]=*(p+i);
arr[1]=*(p+j);
arr[2]=*(p+k);
sequence(arr);
for(num=0;2+num<=h-1;num+=3)
{
if(arr[0]==a_r_r[0+num]&&arr[1]==a_r_r[1+num]&&arr[2]==a_r_r[2+num])
{
flag2=1;
break;
}
}
for(flag=0;flag<3&&flag2==0;h++)
{
a_r_r[h]=arr[flag];
flag++;
}
flag=0;
flag2=0;
}
}
}
}
for(q=0;q<=h-1;q++)
{
r+=1;
if(r%3==1)
{
printf("[ ");
printf("%d ,",a_r_r[q]);
}
if(r%3==2)
{
printf("%d ,",a_r_r[q]);
}
if(r%3==0)
{
printf("%d ",a_r_r[q]);
printf("]");
printf("\n");
}
}
}


void sequence(int *p)
{
int i=0;
int j=0;
int bridge=0;
for(i=0;i<=1;i++)
{
for(j=0;j+1<=2-i;j++)
{
if(*(p+j)>*(p+j+1))
{
bridge=*(p+j+1);
*(p+j+1)=*(p+j);
*(p+j)=bridge;
}
}
}
}