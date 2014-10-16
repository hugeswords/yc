/*************************************************************************
    > File Name: 12-sort.c
    > Author: Ye Anda
    > Company: Lemote Loongson 
    > Created Time: 2014年09月24日 星期三 14时20分39秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
//==========================================================
//swap
//==========================================================
void swap(int *a,int *b)
{
  int p;
  p=*a;
  *a=*b;
  *b=p;
}
//==========================================================
//printarray
//==========================================================
void printarray(int a[],int n)
{
  int i;

  for(i=0;i<n;i++)
  printf("%d\t",a[i]);

  printf("\n\n");
}
//==========================================================
//1.bubble sort
//==========================================================
void bubble(int a[],int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
	  if(a[j]>a[j+1])
        swap(&a[j],&a[j+1]);
    }
  }
}
//==========================================================
//2.select sort
//==========================================================
void select_sort(int a[],int n)
{
  int i,j,num;
  for(i=0;i<n-1;i++)
  {
    num=i;
	for(j=i+1;j<n;j++)
    {
      if(a[j]<a[num])
        num=j; 
    }
    swap(&a[i],&a[num]);
  }
}
//==========================================================
//3.insert sort
//==========================================================
void insert(int a[],int n)
{
  int i,j,k;
  for(i=0;i<n-1;i++)
  {
    k=i+1;
    for(j=i;j>=0&&a[k]<a[j];j--)
    {
      swap(&a[k],&a[j]);
      k=j;
    }
  }
}
//==========================================================
//4.shell sort, it is based on the insert sort,
//the difference is that interval is d
//==========================================================
void shell_insert(int a[],int d,int n)
{
  int i,j,k;
  for(i=0;i<n-d;i++)
  {
    k=i+d;
    for(j=i;j>=0&&a[k]<a[j];j=j-d)
    {
      swap(&a[k],&a[j]);
      k=j;
    }
  }

}
void shell(int a[],int n)
{
  int d=n>>1;

  while(d>=1)
  {    
    shell_insert(a,d,n);
    d>>=1;
  }
}
//===========================================================
//5.heap sort
//===========================================================
void heap_adjust(int a[],int i,int length)
{
  int child;

  for(;i*2+1<length-1;i=child)
  {
    child=i*2+1;
   
    if((child+1<=length-1)&&a[child+1]>a[child])
	  child++;
    if(a[child]>a[i])
	  swap(&a[i],&a[child]);
  }
}
void heap(int a[],int length)
{
  int i;
  for(i=length/2-1;i>=0;i--)
    heap_adjust(a,i,length);
  for(i=length;i>=0;i--)
  {
    swap(&a[0],&a[length]);
    length--;
    heap_adjust(a,0,length);
  }
}
//===========================================================
//6.top_down merge sort
//===========================================================
void merge(int a[],int start,int mid,int end)
{ 
  int *b;
  b=(int*)malloc(sizeof(int)*(end-start+1));
  int i=start;
  int j=mid+1;
  int cul=0;

  while(i<=mid&&j<=end)
  {
    if(a[i]<a[j])
      b[cul++]=a[i++];
	else 
	  b[cul++]=a[j++];
  }
  while(i<=mid)
    b[cul++]=a[i++];
  while(j<=end)
    b[cul++]=a[j++];
  
  for(i=start,cul=0;i<=end;i++)
	a[i]=b[cul++];
  free(b);
}
void top_down_merge(int a[],int start,int mid,int end)
{
  int *tmp;
  tmp=(int*)malloc(sizeof(int)*(end-start+1));
  if(start==end)
    return;
  else
    {
      top_down_merge(a,start,(start+mid)/2,mid);
      top_down_merge(a,mid+1,(mid+1+end)/2,end);
      merge(a,start,mid,end);
    }
}
void down_top_merge(int a[],int length)
{  
  int i;
  int j=1;
  while((2*j)<length)
  {
    j*=2;
    for(i=0;i<length-j;i=i+j)
      {
        merge(a,0+i,j/2+i,j+i-1);
      }
    merge(a,i-j,(i-j+length-1)/2,length-1);
  }
}
//===========================================================
//7.quick sort
//===========================================================
void quick(int a[],int start,int end)
{
  if(start==end)
    return;
  if(start==end-1&&a[start]<a[end])
    return;
  if(start==end-1&&a[start]>a[end])
    swap(&a[start],&a[end]);
  int i=start+1;
  int j=end;

  while(i!=j)
  {
    if(a[j]>a[start])
      {
        j--;
        continue;
      }
    if(a[i]<a[start])
      {
	    i++;
	    continue;
      }
	if(a[i]>=a[start]&&a[j]<=a[start])
      {
        swap(&a[i],&a[j]);
      }
  }
  swap(&a[start],&a[i]);

  quick(a,start,i);
  quick(a,i+1,end);
}
//===========================================================
//===========================================================
//try to not write select or below algorithm,too bad
//efficiency:
//down_top_merge>shell>heap>top_down_merge>>>select>insert>bubble
//===========================================================
int main()
{
  int a[N];
  int i,j;
  clock_t b,s;
  
  srand((unsigned)time(0));
  for(i=0;i<N;i++)
    a[i]=rand()%101;
  //printarray(a,N);
  b=clock();
  //bubble(a,N);
  //insert(a,N);
  //select_sort(a,N);

  //top_down_merge(a,0,N/2,N-1);
  //down_top_merge(a,N);
  //heap(a,N);
  //shell(a,N);
  quick(a,0,N-1);
  s=clock();
  //printarray(a,N);
  printf("%f\n",(double)(s-b));
}
