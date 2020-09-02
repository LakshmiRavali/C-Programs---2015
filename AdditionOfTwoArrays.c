#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int fun(int *,int,int*,int,int*);
struct test {
	int m,n;
	int a[20],b[20],c[20],output[20];
} testDB[5] = {{5,4,{1,2,3,4,5},{1,2,3,4},{0},{1,3,5,7,9}},
				{4,4,{9,9,9,9},{9,9,9,9},{0},{1,9,9,9,8}},
				{1,3,{2},{7,8,9},{0},{7,9,1}},
				{3,3,{1,1,1},{7,7,7},{0},{8,8,8}},
            };
void testCases()
{
	int i,j=0,c1=0,p;
	for( i=0; i<5; i++) 
	{
		p=fun(testDB[i].a,testDB[i].m,testDB[i].b,testDB[i].n,testDB[i].c);
		j=0;
		while(p>=0)
		{
		if(testDB[i].c[p-1]!=testDB[i].output[j]) 
			c1=1;
		p--;
		j++;
		}
		if(c1==0)
			printf("PASSED\n"); 
		else 
			printf("FAILED\n");
		c1=0;
	}
	
}
void main()
{
	testCases();
	getch();
}
int fun(int *a,int m,int *b,int n,int *c)
{
	int i,j,k=0,d=0;
	for(i=m-1,j=n-1;i>=0&&j>=0;i--,j--)
	{
		//d=0;
		c[k]=d+a[i]+b[j];
		if(c[k]>=10)
		{
			d=1;
			c[k]=c[k]-10;
		}
		else
			d=0;
		k++;
	}
	if(i<0)
	{
		while(j>=0)
		{
			c[k]=d+b[j];
			if(c[k]>=10)
			{
				d=1;
				c[k]=c[k]-10;
			}
			else
				d=0;
			j--;
			k++;
		}
	}
	if(j<0)
	{
		while(i>=0)
		{
			c[k]=d+a[i];
			if(c[k]>=10)
			{
				d=1;
				c[k]=c[k]-10;
			}
			else
				d=0;
			i--;
			k++;
		}
	}
	if(d==1)
	{
		c[k]=1;
		k++;
	}
	return k;
}