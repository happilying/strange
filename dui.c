#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
#define OK -2
typedef struct dui
{
    int *data;
    int length;
    int n;
}DUI,*PDUI;
PDUI createdui(void) //创建一个堆
{
    PDUI a=(PDUI)malloc(sizeof(DUI));
    a->n=100;
    a->data=(int *)malloc(sizeof(int)*(a->n));
    return a;
}
void swap(PDUI *a) //从后到前交换顺序
{
    PDUI b=(*a);
    int temp,weizhi=(b->length-1),daxiao;
    if(*(b->data)>*(b->data+1)){daxiao=0;}
    else daxiao=1; //判断堆是大顶堆还是小顶堆
    for(;weizhi>0;weizhi--)
    {
        if(weizhi%2) //判断左节点右节点
        {
            switch(daxiao)
            {
                case 0:
                {
                    if(*(b->data+weizhi)>*(b->data+(weizhi-1)/2))
                    {
                        temp=*(b->data+weizhi);
                        *(b->data+weizhi)=*(b->data+(weizhi-1)/2);
                        *(b->data+(weizhi-1)/2)=temp;
                    }
                    break;
                }
                case 1:
                {
                    if(*(b->data+weizhi)<*(b->data+(weizhi-1)/2))
                    {
                        temp=*(b->data+weizhi);
                        *(b->data+weizhi)=*(b->data+(weizhi-1)/2);
                        *(b->data+(weizhi-1)/2)=temp;
                    }
                    break;
                }
            }
        }
        else
        {
            switch(daxiao)
            {
                case 0:
                {
                    if(*(b->data+weizhi)>*(b->data+(weizhi-2)/2))
                    {
                        temp=*(b->data+weizhi);
                        *(b->data+weizhi)=*(b->data+(weizhi-2)/2);
                        *(b->data+(weizhi-2)/2)=temp;
                    }
                    break;
                }
                case 1:
                {
                    if(*(b->data+weizhi)<*(b->data+(weizhi-2)/2))
                    {
                        temp=*(b->data+weizhi);
                        *(b->data+weizhi)=*(b->data+(weizhi-2)/2);
                        *(b->data+(weizhi-2)/2)=temp;
                    }
                    break;
                }
            }
        }
    }
}
int rudui(PDUI *a,int data) //入堆
{
    PDUI b=(*a);
    if(b->length==b->n){return ERROR;}
    *(b->data+b->length)=data;
    b->length++;
    return OK;
}
int main(void)
{
    PDUI a=createdui();
    int b;
    scanf("%d",&a->length); //输入原堆元素数量
    for(register int i=0;i<=a->length-1;i++) //输入原堆元素
    {
        scanf("%d",&(*(a->data+i)));
    }
    scanf("%d",&b); //输入加入的数
    if(rudui(&a,b)==OK) //判断堆是否溢出
    {
        swap(&a);
    }
    for(register int i=0;i<a->length;i++) //输出新堆
    {
        printf("%d ",*(a->data+i));
    }
    return 0;
}