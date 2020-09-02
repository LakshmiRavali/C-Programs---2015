//Find the max height for a given parent array

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct test
{
	int input[20], l, output;
}testDB[4] = {
		{ { 1,-1,1,1,3,4 }, 6,  3 },
		{ { -1 }, 1,  0 },
		{ { -1,0,0,0 }, 4,  1 },
		{ { -1,0,1,2 }, 4,  3 }
};

void dynamic_allocation(int *a, int *b, int l)
{
	int i = 0;
	for (i = 0; i<l; i++)
		a[i] = b[i];
	a[i] = '\0';
}


void max_height(int *input, int len, int i,int *output)
{
	if (output[i] != -1)
		return;
	if (input[i] == -1)
	{
		output[i] = 0;
		return;
	}
	if (output[input[i]]==-1)
	{
		max_height(input, len, input[i], output);
	}
	output[i] = output[input[i]] + 1;
}

int find_max(int *output,int l)
{
	int max = 0,i;
	for (i = 0; i < l; i++)
	{
		if (max < output[i])
			max = output[i];
	}
	return max;
}


void testCases()
{
	int i = 0, *input, *output,j=0,max;
	for (i = 0; i<4; i++)
	{
		output = (int *)malloc(sizeof(int)*testDB[i].l);
		for (j = 0; j < testDB[i].l; j++)
			output[j] = -1;
		input = (int *)malloc(sizeof(int)*testDB[i].l);
		dynamic_allocation(input, testDB[i].input, testDB[i].l);
		for (j = 0; j < testDB[i].l; j++)
			max_height(input, testDB[i].l,j,output);
		max=find_max(output,testDB[i].l);
		if (max == testDB[i].output)
			printf("passed\n");
		else
			printf("Failed\n");
		
	}
}

void main()
{
	testCases();
	getch();
}