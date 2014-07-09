
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct cpu
{
	int at,bt,tc,wt,tat,ch,pr;
	char name[20];
}p;

void sort(p a[20],int n)
{
	int i,j;
	p temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j].at>a[j+1].at)
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void display(p a[20],int n)
{
	int i;
	printf("\nName\tBT\tAT\tTC\tWT\tTAT");

	for(i=0;i<n;i++)
	{
		printf("\n%s\t%d\t%d\t%d\t%d\t%d",a[i].name,a[i].bt,a[i].at,a[i].tc,a[i].wt,a[i].tat);

	}
}

void fcfs(p a[20],int n)
{
	int i;
	sort(a,n);
	a[0].tc=a[0].bt+a[0].at;
	a[0].wt=0;
	a[0].tat=a[0].bt;
	for(i=1;i<n;i++)
	{
		a[i].tc=a[i-1].tc+a[i].bt;
		if(a[i-1].tc>a[i].at)
		a[i].wt=a[i-1].tc-a[i].at;
		else
		a[i].wt=0;
		a[i].tat=a[i].wt+a[i].bt;
	}
	display(a,n);
}



void priority(p a[20],int n)
{
	int i,j,k=0,cnt=n,min,tc=0;
	p res[20];
	for(i=0;i<n;i++)
	{
		printf("Enter Priority for process %s",a[i].name);
		scanf("%d",&a[i].pr);
	}


	tc=a[0].at;
	for(i=1;i<n;i++)
	{
		if(tc>a[i].at)
		tc=a[i].at;
	}

	while(cnt>0)
	{
		min=32767;
		for(i=0;i<n;i++)
		{
			if(a[i].ch==0&&a[i].at<=tc)
			{
				if(min>a[i].pr)
				{
					min=a[i].pr;
					j=i;
				}
			}
		}
		res[k]=a[j];
		res[k].tc=res[k].bt+tc;
		res[k].wt=tc-res[k].at;
		res[k].tat=res[k].wt+res[k].bt;
		a[j].ch=1;
		cnt--;
		tc=tc+res[k].bt;
		k++;
	}
	display(res,n);
}



int main()
{
	int i,n,ch;
	p a[20];
	//clrscr();


		printf("\nEnter number of processes : ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("\nEnter name of process  : ");
			scanf("%s",a[i].name);
			printf("\nEnter burst time of process  : ");
			scanf("%d",&a[i].bt);
			printf("\nEnter arrival time of process  : ");
			scanf("%d",&a[i].at);
			a[i].ch=0;
		}
        do
        {


		printf("\n1:fcfs\n4.prioritiy\n6.exit");
		printf("\nEnter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
      			case 1:fcfs(a,n);
	     			break;
     			
			case 2:priority(a,n);
          			 break;
			


		}
	}while(ch!=6);
}
