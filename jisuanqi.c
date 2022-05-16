#include<stdio.h>
#include<stdlib.h>
typedef struct num
{
    int num;
    struct num *next;
}NUM,*PNUM;
typedef struct cal
{
    char cal;
    struct cal *next;
}CAL,*PCAL;
PNUM createnum(int data)
{
    PNUM s;
    s=(PNUM)malloc(sizeof(NUM));
    s->num=data;
    s->next=NULL;
    return s;
}
PCAL createcal(char data)
{
    PCAL s;
    s=(PCAL)malloc(sizeof(CAL));
    s->cal=data;
    s->next=NULL;
    return s;
}
void PushNum(int data,PNUM *s)
{
    PNUM p;
    p=createnum(data);
    p->next=(*s);
    (*s)=p;
}
void PushCal(char data,PCAL *s)
{
    PCAL p;
    p=createcal(data);
    p->next=(*s);
    (*s)=p;
}
void OutNum(PNUM *s)
{
    PNUM p;
    p=(*s)->next;
    free(*s);
    (*s)=p;
}
void OutCal(PCAL *s)
{
    PCAL p;
    p=(*s)->next;
    free(*s);
    (*s)=p;
}
int PanDuan(char a,char b)
{
    if(a=='#')return 0;
    switch(b)
    {
        case ')':return 1;
        case '*':
        case '/':
        {
            if(a=='*'||a=='/')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        case '+':
        case '-':
        if(a=='*'||a=='/')
        {
            return 1;
        }
        else
        {
            return 0;
        }
        case '#':return 1;
        case '(':return 0;
    }
}
int main(void)
{
    char a;
    int b,c=0,flag=1;;
    PNUM num;
    PCAL cal;
    num=createnum(-1);
    cal=createcal('#');
    while(1)
    {
        scanf("%c",&a);
        if(a=='=')a='#';
        if(a>='0'&&a<='9')
        {
            c=c*10+(int)(a-'0');
        }
        else
        {
            if(c!=0)
            {
                PushNum(c,&num);
            }
            c=0;
            k:if(PanDuan(cal->cal,a))
            {
                switch(cal->cal)
                {
                    case '+':
                    {
                        num->next->num=num->next->num+num->num;
                        OutNum(&num);
                        OutCal(&cal);
                        break;
                    }
                    case '-':
                    {
                        num->next->num=num->next->num-num->num;
                        OutNum(&num);
                        OutCal(&cal);
                        break;
                    }
                    case '*':
                    {
                        num->next->num=num->next->num*num->num;
                        OutNum(&num);
                        OutCal(&cal);
                        break;
                    }
                    case '/':
                    {
                        num->next->num=num->next->num/num->num;
                        OutNum(&num);
                        OutCal(&cal);
                        break;
                    }
                }
                switch(a)
                {
                    case ')':
                    {
                        if(cal->cal!='(')goto k;
                        else OutCal(&cal);
                        break;
                    }
                    case '#':
                    {
                        if(cal->cal=='#')
                        {
                            printf("计算结果是:%d\n",num->num);
                            return 0;
                        }
                        else goto k;
                    }
                    default :
                    {
                        PushCal(a,&cal);
                    }
                }
            }
            else
            {
                PushCal(a,&cal);
            }
        }
    }
}