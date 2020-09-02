#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
char *index(char *,char*);
struct test {
	char a[50],b[50],c[50];
} testDB[10] = {{"ravali","hai","a"},
{"aabbcc","aabbcc","aabbcc"},
				{"abcabc","abc","abc"},
                {"@@rava","@raava","@ava"},
				{"lemma","lemma-1","lemma"},
{"abc","def",""},
{"Rama","ravAli","Raa"},
{"*/*/*/","/*/**/*","*/"},
{"aaaaaaaaaa","aaaaaaaaaa","aaaaaaaaaa"},
            };
void testCases()
{
	int i;
	char *r;
	for( i=0; i<10; i++) 
	{
		r=index(testDB[i].a,testDB[i].b);
		if(strcmp(r,testDB[i].c)==0)
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
char *index(char *a,char *b)
{
	char *c;
	int i=0,j=0,k=10;
	c=(char *)malloc((sizeof(int)*10));
	while(a[i]!='\0'&&b[i]!='\0')
	{
		if(j>=k)
		{
			k=k+10;
			realloc(c,k);
		}
		if(a[i]==b[i])
		{
			c[j]=a[i];
			j++;
		}
		else
		{
			if(a[i]>'A'&&a[i]<'z'&&b[i]>'A'&&b[i]<'z')
			{
				if(a[i]==b[i]-32||b[i]==a[i]-32||a[i]==b[i]+32||b[i]==a[i]+32)
				{
					c[j]=a[i];
					j++;
				}
			}
		}
		i++;
	}
	c[j]='\0';
	return c;
}