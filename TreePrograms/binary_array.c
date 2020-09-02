//Find if there is a path between given two indexes.


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)




void comparision(int **a,int *p, int *q, int n)
{
	if (*q != (n - 1))
	{
		if (a[*p - 1][*q] == 1)
		{
			*p = *p - 1;
		}
		else if (a[*p][*q + 1] == 1)
		{
			*q = *q + 1;
		}
	}
	if (*q != 0)
	{
		if (a[*p][*q - 1] == 1)
		{
			*q = *q - 1;
		}
	}
}

void main()
{
	int **a,m,n,i,j,p,q,r,s,c=0;
	printf("Enter size of matrix:");
	scanf("%d%d", &m, &n);
	a = (int **)malloc(sizeof(int *)*m*n);
	for (i = 0; i < m; i++)
	{
		a[i] = (int *)malloc(sizeof(int)*n);
	}
	printf("Enter elements in the matrix");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("Enter indexes:");
	scanf("%d%d%d%d", &p, &q, &r, &s);
	if (p < m && r < m && q < n && s < n && a[p][q] != 0 && a[r][s] != 0)
	{
		while (p != r||q != s)
		{
			if (p != 0)
			{
				comparision(a,&p, &q, n);
			}
			else if (p != m - 1)
			{
				comparision(a, &p, &q, n);
			}
			else
			{
				printf("There is no path");
				c = 1;
				break;
			}

		}
		if (c == 0)
			printf("Some path is exists");
	}
	else
		printf("There is no path");
	_getch();

}