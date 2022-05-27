#include<stdio.h>
#define length 10
int a[10001];
void charu(void)
{
    int j;
    for(register int i=2;i<=length;i++)
    {
        if(a[i]<a[i-1])
        {
            a[0]=a[i];
            for(j=i-1;a[0]<a[j];j--)
            {
                a[j+1]=a[j];
            }
            a[j+1]=a[0];
        }
    }
}
void kfen(int low1,int high1)
{
    int low=low1;
    int high=high1;
    if(low<high)
    {
        int key;
        a[0]=a[low];
        key=a[low];
        while(low<high)
        {
            while(low<high&&a[high]>=key)
            high--;
            a[low]=a[high];
            while(low<high&&a[low]<=key)
            low++;
            a[high]=a[low];
        }
        a[low]=a[0];
        kfen(low1,low-1);
        kfen(low+1,high1);
    }
}
void kuaisu(void)
{
    kfen(1,length);
}
void xuanze(void)
{
    for(register int i=1;i<length;i++)
    {
        register int j=i;
        for(register int k=i+1;k<=length;k++)
        {
            if(a[k]<a[j])j=k;
        }
        if(i!=j)
        {
            a[0]=a[j];
            a[j]=a[i];
            a[i]=a[0];
        }
    }
}
int main(void)
{
    int m;
    scanf("%d",&m);
    for(register int i=1;i<=length;i++)
    {
        scanf("%d",&a[i]);
    }
    switch (m)
    {
        case 1:{charu();break;}
        case 2:{kuaisu();break;}
        case 3:{xuanze();break;}
        default:{printf("ERROR\n");return 1;}
    }
    for(register int i=1;i<=length;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}