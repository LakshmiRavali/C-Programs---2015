//Given a unsorted array and a number then find the number of occurances of the number
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int counter(int n,int *a,int count,int i,int len)
{
	if(a[i]==n)
		count=count+1+counter(n,a,count,i+1,len);
	else if(len==i)
		return count;
	else
		 counter(n,a,count,i+1,len);
}
void main()
{
	int n,*a,len,i;
	printf("enter the size of array");
	scanf("%d",&len);
	a=(int *)malloc(sizeof(int)*len);
	printf("enter elements");
	for(i=0;i<len;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter search element");
	scanf("%d",&n);
	n=counter(n,a,0,0,len);
	if(n==0)
		printf("there no such element");
	else
		printf("occurance:%d",n);
	getch();
}