#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char m[2][3][3] = {{"aBa", "E", "E"},{"n", "bB", "E"}}, ip[100],stack[100];
	int size[2][3] = {3,1,1,1,2,1};
	int p,q,r,i,j,n,k,row,col;
	printf("Input the string:\n");
	scanf("%s", ip);
	strcat(ip, "$");
	n=strlen(ip);
	stack[0]='$';
	stack[1]='A';
	i=1;
	j=0;
	printf("PARSING TABLE\n");
	for(p=0;p<2;p++)
	{
		for(q=0;q<3;q++)
		{
			for(r=0;r<3;r++)
			{
				printf("%c", m[p][q][r]);
			}
			printf("\t");
		}
		printf("\n");
	}
	printf("\nstack\tinput\n");
	for(k=0;k<=i;k++)
		printf("%c", stack[k]);
	printf("\t");
	for(k=j;k<=n;k++)
		printf("%c", ip[k]);
	printf("\n");
	while((stack[i]!='$')&&(ip[j]!='$'))
	{
		if(stack[i] == ip[j])
		{
			i--;
			j++;
			//printf("\nstack\tinput\n");
			for(k=0;k<=i;k++)
				printf("%c", stack[k]);
			printf("\t");
			for(k=j;k<=n;k++)
				printf("%c", ip[k]);
			printf("\n");
		}
		switch(stack[i])
		{
			case 'A':row=0;break;
			case 'B':row=1;break;
			default:
				if((stack[i]=='$') && (ip[j]=='$'))
					printf("Successfull parsing\n");
				else
					printf("Parsing failed\n");
				exit(0);
		}
		switch(ip[j])
		{
			case 'a':col=0;break;
			case 'b':col=1;break;
			case 'c':col=2;break;
		}
		if(m[row][col][0]==ip[j])
		{
			for(k=size[row][col]-1;k>=0;k--)
			{
				stack[i]=m[row][col][k];
				i++;
			}
			i--;
		}
		if(m[row][col][0]=='E')
		{
			if(i>0)
			{
				printf("Error\n");
				exit(0);
			}
		}
		if(m[row][col][0]=='n')
		{
			i--;
		}
		//printf("\nstack\tinput\n");
		for(k=0;k<=i;k++)
			printf("%c", stack[k]);
		printf("\t");
		for(k=j;k<=n;k++)
			printf("%c", ip[k]);
		printf("\n");
	}
}














