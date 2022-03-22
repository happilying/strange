#include<stdio.h>
#define Maxlength 10000
int ji[Maxlength],head1=0,rear1=0,ou[Maxlength],head2=0,rear2=0;
int main(void)
{
    int c,d,e=0;
    scanf("%d",&c);
    for(;c!=0;c--)
    {
        scanf("%d",&d);
        if(d%2)
        {
            ji[rear1]=d;
            rear1++;
        }
        else
        {
            ou[rear2]=d;
            rear2++;
        }
    }
    for(;e!=rear1&&e!=rear2;e++)
    {
        printf("%d %d\n",ji[e],ou[e]);
    }
    return 0;
}