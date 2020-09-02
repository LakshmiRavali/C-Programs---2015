//Given a srted array and a key then find the pairs whose sum is equal to the given key

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct test
{
	int input[20],l,key,output[20];
}testDB[4]={
	{{1,2,3,4,5},5,70},
	{{-1,2,8,12,21,23,25},7,20,{-1,21,8,12}},
	{ { 1, 2, 2, 3, 5 }, 5, 5, {2,3} }
};

//Method1:O(n) solution
int *sum(int *a,int len,int key)
{
	int i=0,j=len-1,*b,k=0;
	b=(int *)malloc(sizeof(int));
	while(i<j)
	{
		if(a[i]+a[j]<key)
			i++;
		else if(a[i]+a[j]>key)
			j--;
		else 
		{
			if(a[i]!=a[i-1])
			{
				b[k++]=a[i];
				b[k++]=a[j];
			}
			i++;
			j--;
		}
	}
	b[k]='\0';
	return b;
}

//Method2:O(n^2) Solution
int *sum(int *a,int len,int key)
{
	int i,j,*b,k=0;
	b=(int *)malloc(sizeof(int));
	for(i=0;i<len;i++)
		for(j=i+1;j<len;j++)
		{
			if(a[i]+a[j]==key)
			{
				b[k++]=a[i];
				b[k++]=a[j];
			}
		}
	b[k]='\0';
	return b;
}

int binary_search(int *a,int i,int j,int key)
{
	int mid=(i+j)/2;
	if(i==j)
		return 0;
	if(a[mid]>key)
		binary_search(a,i,mid,key);
	else if(a[mid]<key)
		binary_search(a,mid+1,j,key);
	else 
		return 1;
}


//Method3:O(nlog(n)) solution
int *sum(int *a,int len,int key)
{
	int i,flag=0,*b,k=0;
	b=(int *)malloc(sizeof(int));
	for(i=0;i<len;i++)
	{
		flag=binary_search(a,i+1,len,key-a[i]);
		if(flag==1)
		{
			b[k++]=a[i];
			b[k++]=key-a[i];
		}
	}
	b[k]='\0';
	return b;
}

void dynamic_allocation(int *a,int *b,int l)
{
	int i=0;
	for(i=0;i<l;i++)
		a[i]=b[i];
}

int compare(int *a,int *b)
{
	int i=0;
	while(a[i]!='\0'||b[i]!='\0')
	{
		if(a[i]!=b[i])
			return 0;
		i++;
	}
	return 1;
}

void testCases()
{
	int i=0,*input,*output;
	for(i=0;i<3;i++)
	{
		input=(int *)malloc(sizeof(int)*testDB[i].l);
		dynamic_allocation(input,testDB[i].input,testDB[i].l);
		output=sum(input,testDB[i].l,testDB[i].key);
		if(compare(output,testDB[i].output)==1)
			printf("passed\n");
		else
			printf("failed\n");
	}
}

void main()
{
	testCases();
	getch();
}