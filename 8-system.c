/*************************************************************************
    > File Name: 8-system.c
    > Author: Ye Anda
    > Company: Lemote Loongson 
    > Created Time: 2014年09月23日 星期二 13时51分46秒
 ************************************************************************/

#include<stdio.h>
void f1()
{
  printf("test function system :\n");
  system("sl");
}
void  f2()
{
  printf("test function execl :\n");
  execl("/bin/ls","ls","-l",(char*)0);
}
int main()
{
  f2();
  printf("done");
  return 0;
}
