/*************************************************************************
    > File Name: 6-fabo.c
    > Author: Ye Anda
    > Company: Lemote Loongson 
    > Created Time: 2014年09月23日 星期二 09时06分15秒
 ************************************************************************/

#include<stdio.h>
int fabo(int i){return (i>2)?fabo(i-1)+fabo(i-2):1;}
int main(){printf("%d\n",fabo(10));}
