#include<stdio.h>
#define Maxlength 10000
char a[Maxlength];
int head=0,rear=0;
int main(void)
{
    char b;
    while(1)
    {
        b=getchar();
        switch(b)
        {
            case '{':
            case '}':
            case '[':
            case ']':
            case '(':
            case ')':{a[rear]=b;rear++;break;}
            case '\n':goto k;
        }
    }
    k:if(rear%2)
    {
        printf("¿®∫≈≤ª≈‰∂‘\n");
        return 1;
    }
    while(rear!=head&&(rear-head)!=1)
    {
        rear--;
        if((a[rear]-a[head])!=2&&(a[rear]-a[head])!=1)
        {
            printf("¿®∫≈≤ª≈‰∂‘\n");
            return 1;
        }
        head++;
    }
    printf("¿®∫≈≈‰∂‘\n");
    return 0;
}