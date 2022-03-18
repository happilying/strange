#include<stdio.h>
#include<string.h>
int daxie(char x)
{
	if(x>='A'&&x<='Z') return 1;
	else return 0;
}
int xiaoxie(char x)
{
	if(x>='a'&&x<='z') return 1;
	else return 0;
}
int fuhao(char x)
{
	if((x>='A'&&x<='Z')||(x>='a'&&x<='z')||(x>='0'&&x<='9')) return 0;
	else return 1;
}
int shuzi(char x)
{
	if(x>='0'&&x<='9') return 1;
	else return 0;
}
int main()
{
	int i,j,n;
	char a[200];
	scanf("%d\n",&n);
	for(i=0;i<n;i++) {
		int s=0,f1=0,f2=0,f3=0,f4=0;
		gets(a);
		if(strlen(a)<6) printf("Not Safe\n");
		else {
		    for(j=0;j<strlen(a);j++) {
			    if(daxie(a[j])) f1=1;
                else if(xiaoxie(a[j])) f2=1;
                else if(shuzi(a[j])) f3=1;
                else if(fuhao(a[j])) f4=1;
			}
			s=f1+f2+f3+f4;
			switch(s)
            {
            case 1:printf("Not Safe\n");break;
            case 2:printf("Medium Safe\n");break;
            case 3:printf("Safe\n");break;
            case 4:printf("Safe\n");
            }
		} 	
	}
	return 0;
}