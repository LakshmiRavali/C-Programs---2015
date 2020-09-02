#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int compare(int **,int **,int);
void zero(int *,int,int);
void dynamic1(int **,int,int **);
void testCases();
struct test {
	int input1[20][20];
	int m,n;
	int output[20][20];
} testDB[10]={{{{1,0,3},{4,5,6},{7,8,9}},3,3,{{0,0,0},{4,0,6},{7,0,9}}},
{{{98,99},{45,46}},2,2,{{98,99},{45,46}}},
{{{0,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}},4,4,{{0,0,0,0},{0,6,7,8},{0,10,11,12},{0,14,15,16}}},
{{{1,0},{1,1}},2,2,{{0,0},{1,0}}},
{{{1,0,1},{-1,1,2}},2,3,{{0,0,0},{-1,0,2}}},
{{{-1,2},{2,4},{4,0}},3,2,{{-1,0},{2,0},{0,0}}},
{{{0,1}},1,0,{{0,0}}},
{{{0},{1}},0,1,{{0,0}}},
};
void dynamic1(int **a,int i,int input1[20][20])
{
	int j=0,k=0;
		for(j=0;j<testDB[i].m;j++)
			for(k=0;k<testDB[i].n;k++)
			a[j][k]=input1[j][k];
}
void testCases()
{
	int **a,**b;
	int i,c=1,j=0;
	for(i=0;i<8;i++)
	{
		a=(int **)malloc(sizeof(int *)*(testDB[i].m*testDB[i].n));
		for(j=0;j<testDB[i].m;j++)
			a[j]=(int *)malloc(sizeof(int)*testDB[i].m);
		dynamic1(a,i,testDB[i].input1);
		zero(a,testDB[i].m,testDB[i].n);
		b=(int **)malloc(sizeof(int *)*(testDB[i].m*testDB[i].n));
		for(j=0;j<testDB[i].m;j++)
			b[j]=(int *)malloc(sizeof(int)*testDB[i].m);
		dynamic1(b,i,testDB[i].output);
	if(compare(a,b,i)==0)
		printf("\npassed");
	else
		printf("\nfailed");
	//free(a);
	//free(b);
	}
}
int compare(char **a,char **b,int i)
{
	int k=0,j=0,c=0;
	for(j=0;j<testDB[i].m;j++)
		for(k=0;k<testDB[i].n;k++)
			if(a[j][k]!=b[j][k])
				c=1;
	return c;
}
void main()
{
	testCases();
	getch();
}
void zero(int **a,int m,int n)
{
	int i=0,j=0,k=0,c=0;
	for(i=0;i<m&&c!=1;i++)
		for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
			{
				c=1;
				for(k=0;k<n;k++)
					a[i][k]=0;
				for(k=0;k<m;k++)
					a[k][j]=0;
				break;
			}
		}
}