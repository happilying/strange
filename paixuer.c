#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
    int data;
    struct link *llink,*rlink,*pre;
}LINK,*PLINK;
PLINK t,r=NULL,i;
PLINK createlink(int a)
{
    PLINK p;
    p=(PLINK)malloc(sizeof(LINK));
    p->data=a;
    p->llink=NULL;
    p->rlink=NULL;
    p->pre=NULL;
    return p;
}
void zhong(PLINK p)
{
    if(p->llink){zhong(p->llink);}
    printf("%d  ",p->data);
    if(p->rlink){zhong(p->rlink);}
}
void search(int s)
{
    if(t==NULL||t->data==s){return;}
    r=t;
    if(s>t->data)
    {
        t=t->rlink;search(s);
    }
    else
    {
        t=t->llink;search(s);
    }
}
int main(void)
{
    PLINK head;
    int a[100],b,n;
    scanf("%d",&n);
    for(register int c=0;c<=n-1;c++)
    {
        scanf("%d",&a[c]);
    }
    printf("原始数据：");
    for(register int c=0;c<=n-1;c++)
    {
        printf("%d ",a[c]);
    }
    printf("\n");
    head=createlink(a[0]);
    for(register int c=1;c<=n-1;c++)
    {
        PLINK q;
        q=createlink(a[c]);
        t=head;
        search(q->data);
        if(q->data>r->data)
        {
            r->rlink=q;
        }
        else
        {
            r->llink=q;
        }
        q->pre=r;
    }
    printf("中序遍历结果：");
    t=head;
    zhong(t);
    printf("\n");
    t=head;
    scanf("%d",&b);
    search(b);
    if(!t){printf("删除结点后结果：没有%d结点。\n",b);return 0;}
    if(t->llink==NULL&&t->rlink==NULL)
    {
        if(r->data<t->data){r->rlink=NULL;}
        else{r->llink=NULL;}
        free(t);
    }
    else if(!t->llink)
    {
        r->rlink=t->rlink;
        free(t);
    }
    else if(!t->rlink)
    {
        r->llink=t->llink;
        free(t);    
    }
    else
    {
        r=t;
        i=r;
        t=t->llink;
        while(t->rlink)
        {
            r=t;
            t=t->rlink;
        }
        i->data=t->data;
        r->rlink=t->llink;
        free(t);
    }
    printf("删除结点后结果：");
    t=head;
    zhong(t);
    printf("\n");
    return 0;
}