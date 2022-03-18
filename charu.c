#include<stdio.h>
#define N 10000
int main(void)
{
    int a,b[N],flag=0;register int c;
    char d;
    for(c=0;d!='\n';c++)
    {
        if((d=getchar())==','){c--;continue;}
        else if(d=='\n'){break;}
        else b[c]=(d-'0');
    }
    scanf("%d",&a);
    if(a<=b[0]){printf("%d,%d,",a,b[0]);}
    else {printf("%d,",b[0]);}
    for(register int d=1;d<c-1;d++)
    {
        if(a>=b[d-1]&&a<=b[d]&&flag==0){printf("%d,",a);d--;flag=1;}
        else printf("%d,",b[d]);
    }
    printf("%d\n",b[c-1]);
    return 0;
}