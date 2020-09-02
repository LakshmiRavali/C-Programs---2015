#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void sort01(int *,int);
struct test {
	int n;
	int input1[20];
	int output[20];
} testDB[5] = {{5,{1,0,1,0,1},{0,0,1,1,1}},
			    {4,{1,0,0,0},{0,0,0,1}},
				{6,{1,1,1,1,0,0},{0,0,1,1,1,1}},
				{3,{1,1,0},{0,1,1}},
				{3,{0,1,0},{0,0,1}},
            };
void testCases()
{
	int i,j,c=0;
	for( i=0; i<5; i++) 
	{
		sort01(testDB[i].input1,testDB[i].n);
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
void sort01(int *a,int n)
{
	int *p,*q,t;
	p=&a[0];
	q=&a[n-1];
	while(p<q)
	{
		if(*p>*q)
		{
			t=*p;
			*p=*q;
			*q=t;
			p++;
		}
		else if(*p<*q)
			q--;
		else
		{
			if(*p==0)
			p++;
			else
			q--;
		}
	}
}