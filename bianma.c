#include<stdio.h>
#include<string.h>
#define N 1000000
char a[N+1];
int cheng(int a,int b)
{
    int c=1;
    for(register int d=1;d<=b;d++)
    {
        c=c*a;a--;
    }
    return c;
}
int main(void)
{
    unsigned int n,b,c=0,d;
    scanf("%d",&n);
    for(register int i=1;i<=n;i++)
    {
        scanf("%s",&a);
        b=strlen(a);
        for(d=1;d<=b-1;d++)
        {
            int e=a[d-1]-d+1;if(e==0)continue;
            c=c+cheng(26-d+1,b-d);
        }
    c=c+a[b];
    printf("%u\n",c);
    }
    return 0;
}