#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)


struct test
{
	int input[20], l, i,j;
}testDB[5] = {
		{ { 1,2,3,-10,12,15,-20,4,-30,100 }, 10, 9,9 },
		{ { 1,2,3,4,5 }, 5, 0,4 },
		{ { -1, 0, 0, 0 }, 4, 1,1 },
		{ { 0, 0, 0 }, 3, 0, 0 },
};

void dynamic_allocation(int *a, int *b, int l)
{
	int i = 0;
	for (i = 0; i<l; i++)
		a[i] = b[i];
	a[i] = '\0';
}


void max_sum(int *input,int *j,int *k,int l)
{
	int i = 0, *sum,max=0,value=0,temp,flag=1;
	sum = (int *)calloc(sizeof(int),l);
	sum[0] = input[0];
	for (i = 1; i<l; i++)
	{
		if (sum[i - 1] + input[i]>0)
			sum[i] = sum[i - 1] + input[i];
		if (input[i]!=0||input[0]!=0)
			flag = 0;
	}
	if (flag != 1)
	{
		for (i = 0; i < l; i++)
		{
			if (sum[i] < 0)
			{
				if (max < value)
				{
					max = value;
					value = 0;
					*j = temp;
					*k = i;
				}
				else if (max == value)
				{
					*j = i + 1;
					*k = i + 1;
				}
			}
			else
			{
				if (i == 0 || sum[i - 1] == 0)
					temp = i;
				value = value + sum[i];
			}

		}
		if (max < value)
		{
			max = value;
			value = 0;
			*j = temp;
			*k = i;
			(*k)--;
		}
	}
	else
	{
		*j = 0;
		*k = 0;
	}

}


void testCases()
{
	int i = 0, *input,  j = 0,k=0, max;
	for (i = 0; i<5; i++)
	{
		input = (int *)malloc(sizeof(int)*testDB[i].l);
		dynamic_allocation(input, testDB[i].input, testDB[i].l);
		max_sum(input,&j,&k,testDB[i].l);
		if (j==testDB[i].i&&k==testDB[i].j)
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