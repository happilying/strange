#include<stdio.h>
#include<stdlib.h>
typedef struct points
{
    struct points *front,*left,*right;
    char data;
} POINT,*POINTS;
POINTS createpoint(char datas) //创建节点函数
{
    POINTS p;
    p=(POINTS)malloc(sizeof(POINT));
    p->data=datas;p->front=p->left=p->right=NULL;
    return p;
}
POINTS insertpoint(char datas,POINTS q,int directions) //插入结点函数
{
    POINTS r;
    r=createpoint(datas);
    switch(directions)
    {
        case 0:{q->left=r;break;}
        case 1:{q->right=r;break;}
    }
    r->front=q;
    return r;
}
void Preorder (POINTS T) //先序遍历函数
{
    if (T) 
    {
        printf("%c ",T->data); // 访问结点
        Preorder(T->left); // 遍历左子树
        Preorder(T->right);// 遍历右子树
    }
}
void InTrR(POINTS T) //中序遍历函数
{
    if (T) 
    { 
        InTrR(T->left);
        printf("%c ",T->data);
        InTrR(T->right);
    }
}
void AfTrR(POINTS T) //后序遍历函数
{
    if (T) 
    { 
        AfTrR(T->left);
        AfTrR(T->right);
        printf("%c ",T->data);
    }
}
void cengxu(POINTS T) //层序遍历函数
{
    POINTS dui[100],t;
    int front=0;
    int rear=-1;
    dui[++rear]=T;
    while(rear>=front)
    {
        t=dui[front++];
        printf("%c ",t->data);
        if(t->left)
        {
            dui[++rear]=t->left;
        }
        if(t->right)
        {
            dui[++rear]=t->right;
        }
    }
}
int main(void)
{
    char a;
    int c=0;
    POINTS head,p;
    a=getchar();
    head=createpoint(a);
    p=head;
    while((a=getchar())!='\n')
    {  
        if(a=='#'&&c==0){c=1;continue;}
        if(a=='#'&&c==1&&p!=head)
        {
            p=p->front;
            while(p->right!=NULL&&p!=head)
            {
                p=p->front;
            }
            continue;
        }
        if(a!='#')p=insertpoint(a,p,c);
        c=0;
    }
    printf("前序遍历结果：");
    Preorder(head);
    printf("\n中序遍历结果：");
    InTrR(head);
    printf("\n后序遍历结果：");
    AfTrR(head);
    printf("\n层序遍历结果：");
    cengxu(head);
    printf("\n");
    return 0;
}