#include<stdio.h>
#include<math.h>
int main(void)
{
    double a,b,s;
    scanf("%lf,%lf",&a,&b);
    s=(a-b)/sqrt(a+b);
    printf("%.10000f\n",s);
    return 0;
}