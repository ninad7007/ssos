#include<stdio.h>
int n,nf;
int in[100];
int p[50];
int hit=0;
int i,j,k;

int pgfaultcnt=0;
void getdata()
{
	printf("\nenter length of page reference sequence:");
	scanf("%d",&n);
	printf("\nenter the page reference sequence:");
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	printf("\nenter no of frames:");
	scanf("%d",&nf);
}
void initialize()
{
	pgfaultcnt=0;
	for(i=0;i<nf;i++)
	p[i]=9999;
}
int isHit(int data)
{
	hit=0;
	for(j=0;j<nf;j++)
	{
		if(p[j]==data)
		{
			hit=1;
			break;
		}
	}
	return hit;
}

void dispPages()
{
	for(k=0;k<nf;k++)
	{
		if(p[k]!=9999)
		printf("%d",p[k]);
	}
}
void dispPgFaultCnt()
{
	printf("\ntotal no of page faults:%d",pgfaultcnt);
}
void fifo()
{
	int r=0,k=0;
	initialize();
	for(i=0;i<n;i++)
	{
		printf("\nFor %d:",in[i]);
		if(isHit(in[i])==0)
		{
			k=r%nf;
			p[k]=in[i];
			r++;
			


			pgfaultcnt++;
			dispPages();
		}
		else
		printf("No page fault");
	}
	dispPgFaultCnt();
}

void lru()
{
	initialize();
	int least[50];
	for(i=0;i<n;i++)
	{
		printf("\nFor %d:",in[i]);
		if(isHit(in[i])==0)
		{
			for(j=0;j<nf;j++)
			{
				int pg=p[j];
				int found=0;
				for(k=i-1;k>=0;k--)
				{

					if(pg==in[k])
					{
						least[j]=k;
						found=1;
						break;
					}
					else
					found=0;
				}
				if(!found)
				least[j]=-9999;
			}
			int min=9999;
			int repindex;
			for(j=0;j<nf;j++)
			{
				if(least[j]<min)
				{
					min=least[j];
					repindex=j;
				}
			}
			p[repindex]=in[i];
			pgfaultcnt++;
			dispPages();
		}
		else
			printf("NO page fault!");
		}
	dispPgFaultCnt();
}

int main()
{
	int choice;
	while(1)
	{
		printf("\nPage replacement algorithm\n1.enter data\n2.FIFO\n3.LRU\n4.Exit\nenter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				getdata();
				break;
			case 2:
				fifo();
				break;

			case 3:
				lru();
				break;

			default:
				return 0;
				break;
		}
	}
}









	























































			














































 
