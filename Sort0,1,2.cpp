#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void fun(int *,int);
struct test {
	int n;
	int input1[20];
	int output[20];
} testDB[5] = {{5,{2,1,0,0,1},{0,0,1,1,2}},
			    {4,{0,2,2,1},{0,1,2,2}},
				{6,{2,2,0,1,1,1},{0,1,1,1,2,2}},
				{3,{1,1,0},{0,1,1}},
				{3,{2,1,0},{0,1,2}},
            };
void testCases()
{
	int i,j,c=0;
	for( i=0; i<5; i++) 
	{
		fun(testDB[i].input1,testDB[i].n);
		for(j=0;j<testDB[i].n;j++)
		if(testDB[i].input1[j]!=testDB[i].output[j]) 
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
void fun(int *a,int n)
{
	int i=0,*p,*q,t;
	p=&a[0];
	q=&a[n-1];
	while(i<n)
	{
		if(p==q)
		{
			p++;
			q=&a[n-1];
			i++;
		}
		else if(*p>*q)
		{
			t=*p;
			*p=*q;
			*q=t;
		}
		else
			q--;
	}
}