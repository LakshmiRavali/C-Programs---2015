#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int merge(int *,int *,int,int);
struct test {
	int m,n;
	int a[20],b[20];
	int output[20];
} testDB[9] = {{3,3,{1,3,5},{2,4,6},{1,2,3,4,5,6}},
				{2,5,{1,100},{3,4,8,89,90},{1,3,4,8,89,90,100}},
				{3,3,{1,3,5},{2,3,6},{1,2,3,3,5,6}},
				{2,4,{-1,6},{-2,0,3,9},{-2,-1,0,3,6,9}},
				{3,4,{2,3,4},{3,4,5,6},{2,3,3,4,4,5,6}},
				{2,5,{1,100},{3,30,40,60,80},{1,3,30,40,60,80,100}},
				{0,5,{0},{1,2,3,4,5},{1,2,3,4,5}},
				{4,0,{1,2,3,4},{0},{1,2,3,4}},
				{5,3,{6,8,99,899,900},{0,899,1000},{0,6,8,99,899,899,900,1000}},
            };
void testCases()
{
	int i,j,c=0;
	for( i=0; i<9; i++) 
	{
		merge(testDB[i].a,testDB[i].b,testDB[i].m,testDB[i].n);
		for(j=0;j<testDB[i].n;j++)
		if(testDB[i].b[j]!=testDB[i].output[j]) 
			c=1;
		if(c==0)
			printf("PASSED\n"); 
		else 
			printf("FAILED\n");
	}
	
}
void main()
{
	testCases();
	getch();
}
int merge(int *a,int *b,int m,int n)
{
	int i=0,p=m-1,q=n-1,j=0,k=m+n-1;
	if(n<=0)
	{
		for(i=0;i<m;i++)
			b[i]=a[i];
	}
	else
	{
		while(k>=0&&p>=0&&q>=0)
	{
		if(a[p]>b[q])
		{
			b[k]=a[p];
			p--;
			k--;
		}
		else if(a[p]<b[q])
		{
			b[k]=b[q];
			q--;
			k--;
		}
		else
		{
			b[k]=a[p];
			b[k-1]=b[q];
			k=k-2;
			p--;
			q--;
		}
	}
	}
	while(p>=0)
	{
		b[k]=a[p];
		k--;
		p--;
	}
	while(q>=0)
	{
		b[k]=b[q];
		k--;
		q--;
	}
	return k;
}