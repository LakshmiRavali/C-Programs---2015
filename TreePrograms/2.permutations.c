//Find the all permutations for a given number 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void swap(char *a,char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int compare(char *a,char *b)
{
	int i=0;
	while(a[i]!='\0'||b[i]!='\0')
	{
		if(a[i]!=b[i])
			return 0;
		i++;
	}
	return 1;
}
void permutation(int n,char *a,int i,char *b)
{
	if(i==(n-1))
		i=0;
	else if(compare(a,b)==1)
		return;
	else
	{
		b[n-1]=n+48;
		b[n]='\0';
		puts(a);
		swap(&a[i],&a[i+1]);
		permutation(n,a,i+1,b);
		permutation(n,a,0,b);
	}

}
void main()
{
	int n,i=1;
	char *a,*b;
	a=(char *)malloc(sizeof(char));
	b=(char *)malloc(sizeof(char));
	printf("enter number:");
	scanf("%d",&n);
	while(i<=n)
	{
		a[i-1]=i+48;
		if(i!=n)
			b[i-1]=a[i-1];
		i++;
	}
	a[i-1]='\0';
	b[i-1]='\0';
	permutation(n,a,0,b);
	getch();
}