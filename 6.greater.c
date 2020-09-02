#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int greater(int *,int,int);
struct test {
	int input[20],n,num,output;
} testDB[6] = {{{1,2,3,4},4,2,2},
				{{1,2,4,5},4,3,2},
				{{1,2,3,4},4,4,0},
				{{1,2,2,2,3},5,2,1},
				{{1,2,3,4},4,5,0},
				{{1,2,3,4},4,1,3},
            };
void testCases()
{
	int i,j,c;
	for( i=0; i<6; i++) 
	{
		c=greater(testDB[i].input,testDB[i].n,testDB[i].num);
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
int greater(int *a,int n,int num)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if(num<a[i])
			break;
	}
	return n-i;
}