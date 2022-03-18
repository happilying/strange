#include<stdio.h>
int main(void)
{
    int a,b,c,d=0,e,f,flag=0;
    for(c=1;c<=7;c++)
    {
        scanf("%d%d",&a,&b);
        e=a+b;
        if(c==1||e>d){d=e;f=c;}
        if(e>=10){flag=1;}
    }
    if(flag){printf("%d\n",f);}
    else{printf("0\n");}
    return 0;
}