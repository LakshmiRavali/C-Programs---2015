#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)
void next_value(int *counter, int n)
{
	int i = n-1,c=0;
	while (i >= 0)
	{
		if (counter[i] == 1&&c==0)
		{
			counter[i] = 0;
			c = 1;
		}
		else 
		{
			counter[i] = 1;
			c = 0;
		}
		i--;
	}
}
void main()
{
	int n,*counter,i=0,j=0;
	printf("enter number");
	scanf("%d", &n);
	counter = (int *)calloc(sizeof(int), n);
	while (i < pow(2, n))
	{
		for (j = 0; j < n; j++)
			printf("%d", counter[j]);
		printf("\n");
		next_value(counter, n);
		i++;
	}
	_getch();

}