//case sensitive
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int count(char *,int);
void dynamic(char *,int,char *);
int fun(char *,char *,int,int,int,int);
void testCases();
struct test {
	char input1[30],input2[20];
	int l1,l2,output;
} testDB[10]={{"she is good,she well","she",20,3,2},
{"ravali","ravali",6,6,1},
{"hai welcome","hai",11,7,1},
{"9999 erer 9999","99999",14,5,0},
{"** $$$$ ravali","ravali",14,6,1},
{"i am ravali","va",11,2,0},
{"i am ravali!this","this",16,4,1},
{"hello welcome","hai",13,3,0},
{"i am rlr","i am",8,4,1},
};
void dynamic(char *a,int i,char *input1)
{
	int j=0;
		while(input1[j]!='\0')
		{
			a[j]=input1[j];
			j++;
		}
		a[j]='\0';
}
void testCases()
{
	char *a,*b;
	int i,c=1,r=0;
	for(i=0;i<9;i++)
	{
		a=(char *)malloc(sizeof(int)*testDB[i].l1);
		dynamic(a,i,testDB[i].input1);
		b=(char *)malloc(sizeof(int)*testDB[i].l2);
		dynamic(b,i,testDB[i].input2);
		r=fun(testDB[i].input1,testDB[i].input2,0,0,0,0);
	if(r==testDB[i].output)
		printf("\npassed");
	else
		printf("\nfailed");
	//free(a);
	//free(b);
	}
}
void main()
{
	testCases();
	getch();
}
int count(char *a,int j)
{
	while(a[j]!=' '&&a[j]!='\0'&&a[j]!='.'&&a[j]!=','&&a[j]!='!')
		j++;
	j++;
	return j;
}
int fun(char *a,char *b,int i,int c,int j,int r)
{
	if(a[j]=='\0'&&b[i]=='\0'&&a[j-1]==b[i-1]&&r==0)
		return r+1;
	 if(a[j]=='\0')
		return r;
	if(a[j]==' '&&b[i]=='\0')
	{
		j=count(a,j);
		r=fun(a,b,i-c,c,j,r+1);
	}
	else if(b[i]==a[j])
	{
		r=fun(a,b,i+1,c+1,j+1,r);
	}
	else
	{
		j=count(a,j);
		r=fun(a,b,i,c,j,r);
	}
	return r;
}