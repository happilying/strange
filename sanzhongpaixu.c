#include<stdio.h>
#define length 10
int a[length+1];
void print(int m) //输出函数
{
    for(register int i=m;i<=length;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void charu(void) //插入排序函数
{
    int j;
    for(register int i=2;i<=length;i++) //遍历数字
    {
        if(a[i]<a[i-1])
        {
            a[0]=a[i];//设置备份
            for(j=i-1;a[0]<a[j];j--) //后移
            {
                a[j+1]=a[j];
            }
            a[j+1]=a[0];//覆盖
        }
        print(0);
    }
}
void kfen(int low1,int high1) //快速排序递归函数体
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
            print(0);
        }
        a[low]=a[0];
        kfen(low1,low-1);
        kfen(low+1,high1);
    }
}
void kuaisu(void) //快速排序函数
{
    kfen(1,length);
}
void xuanze(void) //选择排序函数
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
        print(0);
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
    switch (m) //根据输入选择排序方法
    {
        case 1:{charu();break;}
        case 2:{kuaisu();break;}
        case 3:{xuanze();break;}
        default:{printf("ERROR\n");return 1;}
    }
    print(1);
    return 0;
}