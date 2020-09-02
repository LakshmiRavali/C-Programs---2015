//Find the maximum volume between the buildings.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)


int find_result(int *res, int k)
{
	int max = 0, i = 0, value = 0;
	while (i<k)
	{
		if (res[i] != 0)
		{
			value = value + res[i];
		}
		else
			if (max < value)
			{
			max = value;
			value = 0;
			}
		i++;
	}
	return max;
}


//Method1:
int find_volume(int *height, int len)
{
	int *max_right, max_left=0, i,*res,k=0;
	res = (int *)malloc(sizeof(int));
	max_right = (int *)calloc(sizeof(int), len);
	max_right[len - 1] = 0;
	for (i = len-2; i >=0; i--)
	{
		if (height[i + 1] > max_right[i + 1])
			max_right[i] = height[i + 1];
		else
			max_right[i] = max_right[i + 1];
	}
	for (i = 0; i < len; i++)
	{
		if (max_left < height[i])
			max_left = height[i];
		if (max_right[i] > max_left)
		{
						if (max_left > height[i])
							res[k] = max_left - height[i];
						else
							res[k] = 0;
						k++;
		}
		else
		{
						if (max_right[i] > height[i])
							res[k] = max_right[i] - height[i];
						else
							res[k] = 0;
						k++;
		}
	}
	i = find_result(res, k);
	return i;
}


//Method2:
int find_volume(int *height, int len)
{
	int i, j,*res,max_right=0,max_left=0,k=0,flag=0;
	res = (int *)malloc(sizeof(int));
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (flag == j&&flag!=len-1)
				max_right = 0;
			else if (height[j] > max_right)
			{
				max_right = height[j];
				flag = j;
			}
		}
		if (max_right > max_left)
		{
			if (max_left > height[i])
				res[k] = max_left - height[i];
			else
				res[k] = 0;
			k++;
		}
		else
		{
			if (max_right > height[i])
				res[k] = max_right - height[i];
			else
				res[k] = 0;
			k++;
		}
		if (max_left < height[i])
			max_left = height[i];
	}
	i = find_result(res,k);
	return i;
}


void main()
{
	int *height,len,i=0,res;
	printf("Enetr no of buildings");
	scanf("%d", &len);
	height = (int *)malloc(sizeof(int)*len);
	printf("Enter the building heights");
	for (i = 0; i < len; i++)
		scanf("%d", &height[i]);
	res = find_volume(height, len);
	printf("The volume:%d\n", res);
	_getch();
}