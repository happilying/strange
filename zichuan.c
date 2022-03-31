#include<stdio.h>
#include<string.h>
#define N 10000
int main(void)
{
    char str1[N],str2[N];
    scanf("%s",&str1);
    scanf("%s",&str2);
    printf("%d\n",(int)(strstr(str1,str2)-&str1[0])+1);
    return 0;
}