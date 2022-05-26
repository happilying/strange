#include<stdio.h>
int main(void)
{
    int n,m;
    int a[100001];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        a[0]=-1;
        for(register int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
    }
    return 0;
}