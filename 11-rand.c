/*************************************************************************
    > File Name: 11-rand.c
    > Author: Ye Anda
    > Company: Lemote Loongson 
    > Created Time: 2014年09月24日 星期三 10时58分10秒
 ************************************************************************/

#include<stdio.h>

//==========================================================================
//by this function we can see that every time the rand return the fixed number
void testrand()
{
  int i;
  for(i=0;i<10;i++)
    printf("%d\t",rand()%11);
}
//==========================================================================
void testsrand()
{

  int i;
  srand((unsigned)time(0));
  for(i=0;i<10;i++)
    printf("%d\t",rand()%11);
}
//==========================================================================
int main()
{
 // testrand();
  testsrand();
  return 0;
}
