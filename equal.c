#include<stdio.h>
#include<string.h>
#define N 100000
int main(void)
{
    char str1[N],str2[N];
    scanf("%s",&str1);
    scanf("%s",&str2);
    if(strcmp(str1,str2)==0)
    {
        printf("equal\n");
        return 0;
    }
    else
    {
        printf("not equal\n");
        return 0;
    }
}