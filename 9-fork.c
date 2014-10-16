/*************************************************************************
    > File Name: 9-fork.c
    > Author: Ye Anda
    > Company: Lemote Loongson 
    > Created Time: 2014年09月23日 星期二 14时24分53秒
 ************************************************************************/

#include<stdio.h>
int main()
{
  int pid;
  int stat=0;

  pid=fork();
  printf("pid is %d\n",pid);
  switch(pid)
  {
    case -1:
      perror("fork failed");
      break;
    case 0:
      printf("this is the child process %d\n",getpid());
      execl("/bin/ls","ls",(char*)0);
      break;
    default:
      pid=wait(&stat);
      printf("child process %d is done\n",pid);
      printf("parent process %d\n",getpid());
      break;
  }

  return 0;
}
