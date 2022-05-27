#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
PNUM createnum(int data) //创建数字栈
{
    PNUM s;
    s=(PNUM)malloc(sizeof(NUM));
    s->num=data;
    s->next=NULL;
    return s;
}
PCAL createcal(char data) //创建符号栈
{
    PCAL s;
    s=(PCAL)malloc(sizeof(CAL));
    s->cal=data;
    s->next=NULL;
    return s;
}
void PushNum(int data,PNUM *s) //将数据写入数字栈
{
    PNUM p;
    p=createnum(data);
    p->next=(*s);
    (*s)=p;
}
void PushCal(char data,PCAL *s) //将数据写入符号栈
{
    PCAL p;
    p=createcal(data);
    p->next=(*s);
    (*s)=p;
}
void OutNum(PNUM *s) //移除数字栈栈顶
{
    PNUM p;
    p=(*s)->next;
    free(*s);
    (*s)=p;
}
void OutCal(PCAL *s) //移除符号栈栈顶
{
    PCAL p;
    p=(*s)->next;
    free(*s);
    (*s)=p;
}
int PanDuan(char a,char b) //对两个符号进行大小判断
{
    if(a=='#')return 0;
    switch(b)
    {
        case ')':return 1;
        case '^':
        case '*':
        case '/':
        {
            if(a=='*'||a=='/'||a=='^')
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
        if(a=='*'||a=='/'||a=='^')
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
    int c=0;
    PNUM num;
    PCAL cal;
    num=createnum(-1);
    cal=createcal('#');
    while(1)
    {
        scanf("%c",&a);
        if(a=='=')a='#';
        if(a>='0'&&a<='9') //实现多位数输入
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
                switch(cal->cal) //根据符号类型，分别进行运算操作
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
                    case '^':
                    {
                        num->next->num=pow(num->next->num,num->num);
                        OutNum(&num);
                        OutCal(&cal);
                        break;
                    }
                }
                switch(a) //根据符号判断是否继续运算或输出结果
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