#include<stdio.h>
#include<stdlib.h>
typedef struct point
{
    int weizhi;
    struct point *next;
    int quan;
} POINT,*PPOINT;
typedef struct dingdian
{
    char data;
    PPOINT next;
}DD;
DD *head[10];
DD* createhead(char datas)
{
    DD *q;
    q=(DD*)malloc(sizeof(DD));
    q->data=datas;
    q->next=NULL;
    return q;
}
void createpoint(int wei,int quan,int c)
{
    PPOINT q;
    q=(PPOINT)malloc(sizeof(POINT));
    q->weizhi=wei;
    q->quan=quan;
    PPOINT s=head[c]->next;
    head[c]->next=q;
    q->next=s;
}
int main(void)
{
    int a,d;
    scanf("%d",&a);
    d=a;
    for(;a!=0;a--)
    {
        char b;
        scanf("%c",&b);if(b=='\n'||b==' '){scanf("%c",&b);}
        head[d-a]=createhead(b);
    }
    d--;
    for(int a=0;a!=(d+1);a++)
    {
        int g,h;
        while(1)
        {
            scanf("%d",&g);
            if(g==-1)break;
            scanf("%d",&h);
            createpoint(g,h,a);
        }
    }
    for(int a=0;a!=(d+1);a++)
    {
        printf("%c ",head[a]->data);
        PPOINT q;
        q=head[a]->next;
        while(1)
        {
            if(q)
            {
                printf(" (%d,%d)%d ",a,q->weizhi,q->quan);
                q=q->next;
            }
            else{printf(" \n");break;}
        }
    }
    return 0;
}