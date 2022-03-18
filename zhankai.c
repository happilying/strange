#include<stdio.h>
#define N 1000
int cata(char a)
{
	if(a>=48&&a<=57){return 1;}
	if(a>=65&&a<=90){return 2;}
	if(a>=97&&a<=122){return 3;}
	return 0;
}  // b为1，为数字；b为2，为大写；b为3，为小写； b为0，为其他 。 
int cal(char a,char b)
{
	if(cata(a)==cata(b)&&(cata(a)!=0&&cata(b)!=0)){return 1;}
	else{return 0;}
}
int main(void)
{
	char a,b,c;register int flag=0,d;
	while(scanf("%c",&a)!=EOF)
	{
		if(flag)
		{
		    c=a;if(cal(b,c)&&b<c)
		    {
		    	for(d=b+1;d<=c;d++)
		    	{
		    		printf("%c",d);
				}
			}
			else{printf("%c%c",45,c);}flag=0;
		}
		else
		{
			if(a!=45){b=a;printf("%c",b);}
			else{flag=1;continue;}
		}	
	}
	return 0;
}
