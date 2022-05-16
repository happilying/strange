#include<stdio.h>
int main(void)
{
    int a[20],n,target;
    scanf("%d",&n);
    for(register int i=0;i<=n-1;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&target);
    for(register int i=0;i<=n-1;i++)
    {
        register int j=i+1;
        for(;j<=n-1;j++)
        {
            if(target-a[i]==a[j]&&i!=j)
            {
                printf("%d %d\n",i,j);
                return 0;
            }
        }
    }
}