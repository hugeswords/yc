#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"
//=====================================================
struct linka
{
    int data;
    struct linka *next;
};
typedef struct linka linka;
//=====================================================
linka* create(int n)
{
 linka *head,*pre,*cur,*ne;
 int i;
 head=(linka*)malloc(sizeof(linka));
 head->next=NULL;
 head->data=0;
 pre=head;
 for(i=1;i<=n;i++)
 {
  cur=(linka*)malloc(sizeof(linka));
  cur->data=i;
  cur->next=NULL;
  pre->next=cur;
  pre=cur;
 }
 return head;
}
//======================================================
void printlinka(linka *head)
{
 linka *cur;
 cur=head->next;
 while(cur)
 {
  printf("%2dnode is %2d\n",cur->data,cur->data);
  cur=cur->next;
 }
}
//======================================================
void reverse(linka *head)
{
   if(head==NULL)
  {   
    printf("link is null\n");
   return;
  }
 linka *pre,*cur,*ne;
 pre=head->next;
 cur=pre->next;
 pre->next=NULL;
 while(cur)
 {
  ne=cur->next;
  cur->next=pre;
  pre=cur;
  cur=ne;
 }
 head->next=pre;
}
//========================================================
int main()
{
linka *head=create(9);
printlinka(head);
printf("\nafter reverse:\n");
reverse(head);
printlinka(head);
return 0;
}
