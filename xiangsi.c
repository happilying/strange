#include<stdio.h>
#include<stdlib.h>
typedef struct points
{
    struct points *front,*left,*right;
    char data;
} POINT,*POINTS;
POINTS createpoint(char datas)
{
    POINTS p;
    p=(POINTS)malloc(sizeof(POINT));
    p->data=datas;p->front=p->left=p->right=NULL;
    return p;
}
POINTS insertpoint(char datas,POINTS q,int directions)
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
int leav=0,deptho=0,depthn=0;
int max(int a,int b)
{
    if(a>=b)return a;
    else return b;
}
void leaf (POINTS T)
{
    if (T) 
    {
        if(T->left==NULL&&T->right==NULL){leav++;}
        leaf(T->left); // 遍历左子树
        leaf(T->right);// 遍历右子树
    }
}
void depth (POINTS T)
{
    depthn++;
    if (T) 
    {
        depth(T->left); // 遍历左子树
        depthn--;deptho=max(deptho,depthn);
        depth(T->right);// 遍历右子树
        depthn--;deptho=max(deptho,depthn);
    }
}
int main(void)
{
    char a;
    int c=0;
    POINTS head1,p,head2,q;
    a=getchar();
    head1=createpoint(a);
    p=head1;
    while((a=getchar())!='\n')
    {  
        if(a=='#'&&c==0){c=1;continue;}
        if(a=='#'&&c==1&&p!=head1)
        {
            p=p->front;
            while(p->right!=NULL&&p!=head1)
            {
                p=p->front;
            }
            continue;
        }
        if(a!='#'){p=insertpoint(a,p,c);}
        c=0;
    }
    a=getchar();
    head2=createpoint(a);
    q=head2;
    c=0;
    while((a=getchar())!='\n')
    {  
        if(a=='#'&&c==0){c=1;continue;}
        if(a=='#'&&c==1&&q!=head2)
        {
            q=q->front;
            while(q->right!=NULL&&q!=head2)
            {
                q=q->front;
            }
            continue;
        }
        if(a!='#'){q=insertpoint(a,q,c);}
        c=0;
    }
    leaf(head1);
    depth(head1);
    int leav1=leav,depth1=deptho;
    leav=0;
    depthn=0;
    deptho=0;
    leaf(head2);
    depth(head2);
    if(leav==leav1&&deptho==depth1){printf("A与B相似\n");}
    else{printf("A与B不相似\n");}
    return 0;
}