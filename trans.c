#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int compare(int **,int **,int);
void transpse(int *);
void dynamic1(int **,int,int **);
void testCases();
void swap(int,int);
struct test {
	int input1[20][20];
	int l;
	int output[20][20];
} testDB[10]={{{{1,2,3},{4,5,6},{7,8,9}},3,{{1,4,7},{2,5,8},{3,6,9}}},
{{1},1,{1}},
{{{98,99},{45,46}},2,{{98,45},{99,46}}},
{{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}},4,{{1,5,9,13},{2,10,11,14},{3,7,11,15},{4,8,12,16}}},
{{{1,0},{0,1}},2,{{1,0},{0,1}}},
{{{-1,0},{-1,0}},2,{{-1,-1},{0,0}}},
{{{-1,2,4},{2,4,6},{4,4,4}},3,{{-1,2,4},{2,4,6},{4,6,4}}},
{{{0,0},{-1,-1}},2,{{0,-1},{0,-1}}},
};
void dynamic1(int **a,int i,int input1[20][20])
{
	int j=0,k=0;
		for(j=0;j<testDB[i].l;j++)
			for(k=0;k<testDB[i].l;k++)
			a[j][k]=input1[j][k];
}
void testCases()
{
	int **a,**b;
	int i,c=1,j=0;
	for(i=0;i<8;i++)
	{
		a=(int **)malloc(sizeof(int *)*(testDB[i].l*testDB[i].l));
		for(j=0;j<testDB[i].l;j++)
			a[j]=(int *)malloc(sizeof(int)*testDB[i].l);
		dynamic1(a,i,testDB[i].input1);
		transpse(a,testDB[i].l);
		b=(int **)malloc(sizeof(int *)*(testDB[i].l*testDB[i].l));
		for(j=0;j<testDB[i].l;j++)
			b[j]=(int *)malloc(sizeof(int)*testDB[i].l);
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
	for(j=0;j<testDB[i].l;j++)
		for(k=0;k<testDB[i].l;k++)
			if(a[j][k]!=b[j][k])
				c=1;
	return c;
}
void main()
{
	testCases();
	getch();
}
void transpse(int **a,int n)
{
	int i=0,j=0,temp;
	if(n>1)
	{
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(i==j)
				continue;
			else
			{
				temp=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=temp;
			}
		}
	}
}