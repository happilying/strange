#include<stdio.h>
#define Maxlength 10000
int a[Maxlength],heada=0,reara=0,b[Maxlength],headb=0,rearb=0,c[Maxlength],headc=0,rearc=0;
int main(void)
{
    int d,e;
    scanf("%d",&d);
    for(;d!=0;d--)
    {
        scanf("%d",&e);
        if((e/10)>=10){a[reara]=e;reara++;}
        else if((e/10)<=5){c[rearc]=e;rearc++;}
        else {b[rearb]=e;rearb++;}
    }
    printf("60>x:");
    while(headc!=rearc){printf("%d ",c[headc]);headc++;}
    printf("\n");
    printf("60<=x<100:");
    while(headb!=rearb){printf("%d ",b[headb]);headb++;}
    printf("\n");
    printf("x>=100:");
    while(heada!=reara){printf("%d ",a[heada]);heada++;}
    printf("\n");
    return 0;    
}