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
            case '[':
            case '(':{q:a[rear]=b;rear++;break;}
            case '}':
            case ']':
            case ')':{if((b-a[rear-1])==1||(b-a[rear-1])==2){rear--;break;}else{goto q;}}
            case '\n':goto k;
        }
    }
    k:if(head!=rear)
    {
        printf("¿®∫≈≤ª≈‰∂‘\n");
        return 1;
    }
    else
    {
        printf("¿®∫≈≈‰∂‘\n");
        return 0;
    }
}