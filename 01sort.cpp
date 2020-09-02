#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void sort(int *,int);
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
		sort(testDB[i].input1,testDB[i].n);
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
void sort(int *a,int n)
{
	int i=0,c0=0;
	for(i=0;i<n;i++)
		if(a[i]==0)
			c0++;
	for(i=0;i<c0;i++)
		a[i]=0;
	while(i<n)
	{
		a[i]=1;
		i++;
	}
}