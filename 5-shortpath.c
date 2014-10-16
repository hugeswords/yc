/*************************************************************************
    > File Name: 5-shortpath.c
    > Author: Ye Anda
    > Company: Lemote Loongson 
    > Created Time: 2014年09月12日 星期五 16时41分41秒
 ************************************************************************/

#include<stdio.h>
#define MAX 9999
int a[][6]={0,6,3,MAX,MAX,MAX,
			6,0,2,5,MAX,MAX,
			3,2,0,3,4,MAX,
			MAX,5,3,0,2,3,
			MAX,MAX,4,2,0,5,
			MAX,MAX,MAX,3,5,0};
int min(int a,int b)
{
	return ((a<b)?a:b);
}
int select()
{
	int i,j,tmp;
	for(i=0;i<6;i++)
	{
		tmp=i;
		for(j=i+1;j<6&j!=i;j++)
			{
				if(a[0][i]>a[0][j])
					tmp=j;
			}
		a[0][i]=a[0][i]+a[0][tmp];
		a[0][tmp]=a[0][i]-a[0][tmp];
		a[0][i]=a[0][i]-a[0][tmp];
	}
}
void dijkstra()
{
	int i,j;
	for(i=1;i<6;i++)
		for(j=0;j<6;j++)
			{
              if(j!=i)
				a[0][j]=min(a[0][j],a[0][i]+a[i][j]);
			}
}
int main()
{
	int i;
	dijkstra();
	for(i=0;i<6;i++)
	printf("%d\t",a[0][i]);
}
