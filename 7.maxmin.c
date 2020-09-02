#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void maxmin(int *,int);
struct test {
	int input[20],n,output1,output2;
} testDB[4] = {{{1,2,3,4},4,1,4},
				{{2,2,2,2},4,2,2},
				{{-1,1},2,-1,1},
				{{4},1,4,4},
            };
void testCases()
{
	int i,j,c;
	for( i=0; i<4; i++) 
	{
		maxmin(testDB[i].input,testDB[i].n);
		if(testDB[i].input[testDB[i].n]==testDB[i].output1&&testDB[i].input[testDB[i].n+1]==testDB[i].output2) 
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
void maxmin(int *a,int n)
{
	int i,min,max;
	min=25000;
	max=-25000;
	for(i=0;i<n;i++)
	{
		if(min>a[i])
			min=a[i];
		if(max<a[i])
			max=a[i];
	}
	a[n]=min;
	a[n+1]=max;
	a[n+2]='\0';
}