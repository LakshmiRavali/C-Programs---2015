#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void mul2(int *,int,int*);
struct test {
	int n;
	int a[20],b[20];
	int output[20];
} testDB[5] = {{5,{1,2,3,4,5},{0},{120,60,40,30,24}},
				{4,{1,0,0,1},{0},{0,0,0,0}},
				{4,{0,1,2,3},{0},{6,0,0,0}},
				{3,{-2,3,4},{0},{12,-8,-6}},
				{5,{-3,-1,2,3,4},{0},{-24,-72,36,24,18}},
            };
void testCases()
{
	int i,j,c=0;
	for( i=0; i<5; i++) 
	{
		mul2(testDB[i].a,testDB[i].n,testDB[i].b);
		for(j=0;j<testDB[i].n;j++)
		{
		if(testDB[i].b[j]!=testDB[i].output[j]) 
			c=1;
		}
		if(c==0)
			printf("PASSED\n"); 
		else 
			printf("FAILED\n");
		c=0;
	}
	
}
void main()
{
	testCases();
	getch();
}
void mul2(int *a,int n,int *b)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
		b[i]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				continue;
			b[i]=b[i]*a[j];
		}
	}
}