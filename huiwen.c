#include<stdio.h>
#include<stdlib.h>
#define Maxlength 100
char a[Maxlength];
int head=0,rear=0;
int main(void)
{
    char b;
    while((b=getchar())!='\n')
    {
        a[rear]=b;
        rear++;
    }
    while(rear!=head&&(rear-head)!=1)
    {
        rear--;
        if(a[rear]!=a[head])
        {
            printf("���ǻ���\n");
            return 1;
        }
        head++;
    }
    printf("�ǻ���\n");
    return 0;
}