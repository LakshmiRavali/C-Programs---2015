#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int counting(int *,int);
struct test {
	int input[20],n,output;
} testDB[5] = {{{1,2,3,4},4,0},
				{{-1,-2,-3,4,6,-8},6,3},
				{{-1,1,2,-2,-2,-3,9},7,3},
				{{-1,2,-3,4},4,1},
				{{-1,-2,-3,-4},4,4},
            };
void testCases()
{
	int i,j,c;
	for( i=0; i<5; i++) 
	{
		c=counting(testDB[i].input,testDB[i].n);
		if(c==testDB[i].output) 
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
int counting(int *a,int n)
{
	int i=0,j,c1=0,c2=0,v=0;
	for(j=0;j<n;j++)
	{
		v=0;
		if(a[j]<0)
		{
			i=j;
			c1++;
			v=1;
		}
		else
			c1=0;
		if(c2<=c1&&v==1)
			c2=c1;
	}
	return c2;
}