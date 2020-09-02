//case in sensitive
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
char* alphanum(char *,char *);
struct test {
	char input1[50],input2[50],output[50];
} testDB[14] = {{"rAma","mara","rAma"},
				{"marse","raMa","mar"},
                {"abca","aebfc","abc"},
				{"aaaabbb","aab","aab"},
				{"rama","maars","rama"},
				{"ravali","ravali","ravali"},
				{"","",""},
				{"raVali","ilavar","raVali"},
{"AbCdE","aBcDe","AbCdE"},
};
void testCases()
{
	int i,j=0;
	char *c;
	for( i=0; i<9; i++)	
	{
		c=alphanum(testDB[i].input1,testDB[i].input2);
		if(strcmp(c,testDB[i].output)==0)
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
char* alphanum(char *a,char *b)
{
	int *c,*d,i=0,j=0,k=0;
	char *e;
	c=(int *)malloc((sizeof(int)*26));
	d=(int *)malloc((sizeof(int)*26));
	for(i=0;i<27;i++)
	{
		c[i]=0;
		d[i]=0;
	}
	i=0;
	while(a[i]!='\0'||b[i]!='\0')
	{
		if(a[i]>='A'&&a[i]<='Z')
			j=(int)a[i]-64;
		else if(a[i]>='a'&&a[i]<='z')
			j=(int)a[i]-96;
		if(a[i]!='\0')
		c[j]++;
		if(b[i]>='A'&&b[i]<='Z')
			k=(int)b[i]-64;
		else if(b[i]>='a'&&b[i]<='z')
			k=(int)b[i]-96;
		if(b[i]!='\0')
		d[k]++;
		i++;
	}
	i=1;
	j=1;
	while(i<27)
	{
		if(c[i]<=d[i]&&c[i]!=0&&d[i]!=0)
		d[i]=c[i];
		else if(d[i]<=c[i]&&c[i]!=0&&d[i]!=0)
		c[i]=d[i];
		if(c[i]==d[i]&&c[i]!=0&&d[i]!=0)
		{
			c[j]=i;
			j++;
		}
		i++;
		
	}
	c[j]='\0';
	e=(char *)malloc((sizeof(int)*j));
	j=0;
	i=0;
	k=0;
	while(a[i]!='\0')
	{
		k++;
		if(a[i]==(char)c[k]+96&&d[c[k]]!=0||a[i]==(char)c[k]+64)
		{
			d[c[k]]--;
			e[j]=a[i];
			j++;
			i++;
			k=0;
		}
		else if(c[k]=='\0')
		{
			i++;
			k=0;
		}
	}
	e[j]='\0';
	if(j==0)
		return "";
	else 
	return e;
}