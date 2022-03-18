#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
int CaculateWeekDay(int y,int m, int d)
{
    if(m==1||m==2){m+=12;y--;}
    int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return iWeek;
}
int main(void)
{
    int y,m,d,c;unsigned int e;
    time_t a,b;
    scanf("%d%d%d",&y,&m,&d);
    c=CaculateWeekDay(y,m,d);
    if(c==5||c==6){printf("Free.\n");return 0;}
    typedef struct tm tim;
    struct tm *p,*q;p=(tim*)malloc(sizeof(tim));q=(tim*)malloc(sizeof(tim));memset(p,0,sizeof(tim));memset(q,0,sizeof(tim));
    p->tm_mday=d;p->tm_mon=m-1;p->tm_year=y-1900;a=mktime(p);
    q->tm_mday=9;q->tm_mon=3;q->tm_year=2012-1900;b=mktime(q);
    e=difftime(a,b)/3600/24/7;c=c-(e/13);
    while(c<0)
    {
        c=c+5;
    }
    switch(c)
    {
        case 0:printf("3 and 8.\n");break;
        case 1:printf("4 and 9.\n");break;
        case 2:printf("5 and 0.\n");break;
        case 3:printf("1 and 6.\n");break;
        case 4:printf("2 and 7.\n");break;
    }
    return 0;
}