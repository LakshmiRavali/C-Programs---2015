//Searching a number in the given array and find the first position
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int searching(int *a,int key,int first,int last)
{
	int index=-1;
	if(first==last)
	{
		if(key==a[first])
			return first;
	}
	else
	{
		index=searching(a,key,0,(first+last)/2);
		if(index!=-1)
			return index;
		index=searching(a,key,((first+last)/2)+1,last);
		if(index!=-1)
			return index;
	}
	return index;
}
void main()
{
	int n,*a,key,i=0;
	printf("enter size of array");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("enter array elements");
	while(i<n)
	{
		scanf("%d",&a[i]);
		i++;
	}
	printf("enter search element");
	scanf("%d",&key);
	key=searching(a,key,0,n);
	if(key==-1)
		printf("not present");
	else
	printf("the key location:%d",key+1);
	getch();
}