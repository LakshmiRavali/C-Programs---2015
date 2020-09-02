#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
char* adder(char *,char *);
struct test {
	char input1[50],input2[50];
	char output[50];
} testDB[5] = {{"123","123","246"},
				{"123","9","132"},
                {"999","1","1000"},
                {"345","127","472"},
{"999","","999"},
            };
void testCases()
{
	int i,c=0,j=0,k=0;
	char *r;
	for( i=0; i<5; i++) 
	{
		r=adder(testDB[i].input1,testDB[i].input2);
		while(r[j]!='\0')
			j++;
		j--;
		while(j>=0)
		{
		if(r[j]==testDB[i].output[k]) 
			c=1;
		j--;
		k++;
		}
		if(c==1)
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
char* adder(char *a,char *b)
{
	int k=5,i=0,j=0,l=0,x=0,y=0,z=0,p=0;
	char *c;
	c=(char *)malloc((sizeof(int)*5));
	while(a[i]!='\0'||b[j]!='\0')
	{
		if(a[i]!='\0')
			i++;
		if(b[j]!='\0')
			j++;
	}
	i--;
	j--;
	while(i>=0&&j>=0)
	{
		if(i>=k||j>=k)
		{
			k=k+5;
			realloc(c,k);
		}
		x=(int)a[i]-48;
		y=(int)b[j]-48;
		z=p+x+y;
		if(z>=10)
		{
			z=z-10;
			p=1;
		}
		else 
			p=0;
		c[l]=(char)z+48;
		l++;
		i--;
		j--;
	}
	if(i>=0)
	{
		while(i>=0)
		{
			if(i>=k)
			{
			k=k+5;
			realloc(c,k);
			}
			x=(int)a[i-1]-48;
			z=p+x;
			if(z>=10)
			{
				z=z-10;
				p=1;
			}
			else
				p=0;
			c[l]=(char)z+48;
			l++;
			i--;
		}
	}
	else if(j>=0)
	{
		while(j>=0)
		{
			if(j>=k)
			{
			k=k+5;
			realloc(c,k);
			}
			y=(int)a[j-1]-48;
			z=p+y;
			if(z>=10)
			{
				z=z-10;
				p=1;
			}
			else
				p=0;
			c[l]=(char)z+48;
			l++;
			j--;
		}
	}
	c[l]='\0';
	return c;
}