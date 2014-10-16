/*************************************************************************
    > File Name: 7-file.c
    > Author: Ye Anda
    > Company: Lemote Loongson 
    > Created Time: 2014年09月23日 星期二 11时26分23秒
 ************************************************************************/

#include<stdio.h>
//========================================================================
void readchar()
{
  
  FILE *fin=NULL;
  FILE *fout=NULL;
  char c='\0';
  
  fin=fopen("data","r");
  fout=fopen("copy","w");
  while((c=fgetc(fin))!=EOF)
    {
    printf("%c",c); 
    fputc(c,fout);
    }
  fclose(fin);
  fclose(fout);
}
//========================================================================
void readf()
{
  FILE *fin=NULL;
  FILE *fout=NULL;
  int c=0;

  fin=fopen("data","r");
  fout=fopen("copy","w");
  while(fread(&c,sizeof(char),1,fin))
    fwrite(&c,sizeof(char),1,fout);
  fclose(fin);
  fclose(fout);
}
//=========================================================================
int main()
{
  readchar();

  return 0;
}
