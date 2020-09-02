//Fine the number of posibilities of climbing stairs leaving one or none at a time
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int fun(int n,int res)
{
	int i=0;
	if(n==0)
		return res+1;
	if(n<0)
		return res;
	else
	{
		res=fun(n-1,res);
		res=fun(n-2,res);
	}
	return res;
}
void main()
{
	int n;
	printf("enter n");
	scanf("%d",&n);
	if(n==0)
		printf("0");
	else
		n=fun(n,0);
	printf("The number of steps required are:%d",n);
	getch();
}