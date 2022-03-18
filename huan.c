#include<stdio.h>
int main(void)
{
    int a[5][6],b[5][6];
    for(register int i=0;i<=4;i++)
    {
        for(register int j=0;j<=5;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(register int i=0;i<=4;i++)
    {
        for(register int j=0;j<=5;j++)
        {
            b[i][5-j]=a[i][j];
        }
    }
    printf("原始数组：\n");
    for(register int i=0;i<=4;i++)
    {
        for(register int j=0;j<=5;j++)
        {
            printf("%d",a[i][j]);
            if(j!=5)printf(" ");
        }
        printf("\n");
    }
    printf("对调数组：\n");
    for(register int i=0;i<=4;i++)
    {
        for(register int j=0;j<=5;j++)
        {
            printf("%d",b[i][j]);
            if(j!=5)printf(" ");
        }
        printf("\n");
    }
    return 0;
}