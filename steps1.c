#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void step(int n,char *a,int i)
{
	if(n<0)
	{
		a[--i]='\0';
		return ;
	}
	if(n==0)
	{
		a[i]='\0';
		puts(a);
	}
	else
	{
		a[i]='s';
		step(n-1,a,i+1);
		a[i]='d';
		step(n-2,a,i+1);
	}
}
void main()
{
	int n;
	char *a;
	a=(char *)malloc(sizeof(char));
	printf("enter n:");
	scanf("%d",&n);
	step(n,a,0);
	getch();
}