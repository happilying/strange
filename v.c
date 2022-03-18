#include<stdio.h>
char xunhuan(int a)
{
    if(a>'Z')
    while(a>'Z')
    {
        a='A'+a-'Z'-1;
    }
    return a;
}
int main(void)
{
    int a,b,c,d,e;char z;
    scanf("%d %c",&a,&z);
    b=a+(a-1)+a+(a-1)-1;
    for(register int f=1;f<=a-1;f++)
    {
        register int h=1;
        for(register int g=1;g<=(b-1)/2;g++)
        {
            if(g%2==0){printf(" ");continue;}
            if(f==1&&g==1){printf("%c",z);}
            else if(f!=1&&g==1){printf("%c",xunhuan(z+(a-1)*3-f+1));h++;}
            else
            {
                if(f!=1&&h==f){printf("%c",xunhuan(z+f-1));}
                else{printf(" ");}
                h++;
            }
        }
        printf(" ");h--;
        for(register int g=(b-1)/2;g>=1;g--)
        {
            if(g%2==0){printf(" ");continue;}
            if(f==1&&g==1){printf("%c",z);}
            else if(f!=1&&g==1){printf("%c",xunhuan(z+(a-1)*3-f+1));h--;}
            else
            {
                if(f!=1&&h==f){printf("%c",xunhuan(z+f-1));}
                else{printf(" ");}
                h--;
            }           
        }
        printf("\n");
    }
    register int h=0;
    for(register int f=a,g=1;g<=(b-1)/2;g++)
    {
        if(g%2==0){printf(" ");continue;}
        else{printf("%c",xunhuan(z+(a-1)*2-h));h++;}
    }
    printf("%c",xunhuan(z+a-1));h--;
    for(register int f=a,g=(b-1)/2;g>=1;g--)
    {
        if(g%2==0){printf(" ");continue;}  
        else{printf("%c",xunhuan(z+(a-1)*2-h));h--;}
    }
    printf("\n");
    return 0;
}