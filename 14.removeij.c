#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int remov(int *,int,int,int);
struct test {
	int input[20],n,num1,num2,output[20];
} testDB[9] = {{{1,2,3,4,5},5,2,4,{1,5}},
				{{1,2,3,4,5},5,-1,-3,{1,2,3,4,5}},
				{{1,2,3,4,5},5,-3,3,{4,5}},
				{{1,2,3,4,5},5,3,-3,{4,5}},
				{{1,2,3,4,5},5,3,7,{1,2}},
				{{1,2,3,4,5},5,7,3,{1,2}},
				{{1,2,3,4,5},5,7,8,{1,2,3,4,5}},
				{{1,2,3,4,5},5,1,5,{0}},
            };
void testCases()
{
	int i,j,c=0,p;
	for( i=0; i<5; i++) 
	{
		p=remov(testDB[i].input,testDB[i].n,testDB[i].num1,testDB[i].num2);
		for(j=0;j<p;j++)
		if(testDB[i].input[j]!=testDB[i].output[j]) 
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
int remov(int *a,int n,int i1,int i2)
{
	int i=n,temp;
	if(i1>i2)
	{
		temp=i1;
		i1=i2;
		i2=temp;
	}
	if((i1<=0&&i2<=0)||(i1>=n&&i2>=n))
		i2=n;
	else if(i1<=0&&i2>=0)
		i=0;
	else if(i1>=0&&i2>=n)
		i=i1-1;
	else if(i1>=0&&i2<=n)
		i=i1-1;
	while(i2<n)
	{
		a[i]=a[i2];
		i++;
		i2++;
	}
	return i;
}