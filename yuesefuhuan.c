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
    p=(PLINK)malloc(sizeof(LINK)); //分配头节点空间
    p->data=1;
    p->next=NULL;
    q=p;
    for(register int n=2;n<=m;n++) //生成环表
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
    p=create(m);  //生成环表
    q=p; //指向头节点
    p=p->next; //指向q的下一节点
    scanf("%d%d",&s,&n);
    for(s--;s>1;s--) //定位s的位置
    {
        p=p->next;
        q=q->next;
    }
    while(1)
    {
        p=q->next;//指向q的下一节点
        for(register int i=n;i>1;i--) //步进n个节点
        {
            p=p->next;
            q=q->next;
        }
        printf("%d，",p->data); //输出节点
        q->next=p->next; //重赋值
        if(p==q){free(p);break;}  //判断相等，若相等，证明环已全部输出完毕
        free(p); //删除p
    }
    printf("\n");
    return 0;
}