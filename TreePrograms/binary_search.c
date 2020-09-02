#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct test
{
	int input[20],l,key,output;
}testDB[4]={
	{{1,2,3,4,5},5,4,4},
	{{1,1,2,2,2,3,3},7,2,5},
	{{3,3,3,3,3,3},6,3,6},
	{{1,2,3,4},4,5,-1}
};

void dynamic_allocation(int *a,int *b,int l)
{
	int i=0;
	for(i=0;i<l;i++)
		a[i]=b[i];
}

//Iterative
int binary_search(int *a,int i,int j,int key)
{
	int mid;
	while(i<=j)
	{
		mid=(i+j)/2;
		if(a[mid]==key&&(mid==j-1||a[mid]<a[mid+1]))
			return mid;
		else
		{
			if(a[mid]>key)
				j=mid-1;
			else 
				i=mid+1;
		}
	}
	return -2;
}

//Method3
int binary_search(int *a,int i,int j,int key)
{
	int mid=(i+j)/2;
	if(i>j)
		return -2;
	if((mid==j-1&&a[mid]==key)||(a[mid]<a[mid+1]&&a[mid]==key))
		return mid;
	else
	{
		if(a[mid]>key)
			mid=binary_search(a,i,mid-1,key);
		else
			mid=binary_search(a,mid+1,j,key);
	}
	
}


//Method2
int binary_search(int *a,int i,int j,int key)
{
	int mid=(i+j)/2;
	if(i>j)
		return -1;
	if(a[mid]>key)
		mid=binary_search(a,i,mid-1,key);
	else if(a[mid]<key)
		mid=binary_search(a,mid+1,j,key);
	else
	{
		while(a[mid]==a[mid+1])
			mid++;
		return mid;
	}
}


//Method1:
int binary_search(int *a,int i,int j,int key)
{
	int mid=(i+j)/2;
	if(i>j)
		return -1;
	if(a[mid]>key)
		mid=binary_search(a,i,mid-1,key);
	else if(a[mid]<key)
		mid=binary_search(a,mid+1,j,key);
	else
	{
		if(a[mid]==a[mid+1])
			mid=binary_search(a,mid+1,j,key);
		return mid;
	}

}

void testCases()
{
	int i=0,*input,output;
	for(i=0;i<4;i++)
	{
		input=(int *)malloc(sizeof(int)*testDB[i].l);
		dynamic_allocation(input,testDB[i].input,testDB[i].l);
		output=binary_search(input,0,testDB[i].l,testDB[i].key);
		if(output+1==testDB[i].output)
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