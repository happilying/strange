#include<stdio.h>
#include<stdlib.h>
typedef struct link //定义节点
{
    int data;
    struct link *next;
}LINK,*PLINK;
PLINK create(int m) //创建节点数为m的环表
{
    PLINK p,q;
    p=(PLINK)malloc(sizeof(LINK));
    p->data=1;
    p->next=NULL;
    q=p;
    for(register int n=2;n<=m;n++)
    {
        PLINK r;
        r=(PLINK)malloc(sizeof(LINK));
        r->data=n;
        r->next=q->next;
        q->next=r;
        q=q->next;
    }
    q->next=p;
    return p;
}
int main(void)
{
    int m,s,n;
    PLINK p,q;
    scanf("%d",&m);
    p=create(m);
    q=p;
    p=p->next;
    scanf("%d%d",&s,&n);
    for(s--;s>1;s--)
    {
        p=p->next;
        q=q->next;
    }
    while(1)
    {
        p=q->next;
        for(register int i=n;i>1;i--)
        {
            p=p->next;
            q=q->next;
        }
        printf("%d，",p->data);
        q->next=p->next;
        if(p==q){free(p);break;}
        free(p);
    }
    printf("\n");
    return 0;
}