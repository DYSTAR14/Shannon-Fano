#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct shan
{
	char sym[10];
	float fre[10];
	int arr[10][10];
	int con[10];		
}s; 

float addfirst(int f,int n)
{
	float sum=0;
	for (int i = f; i <=n; i++)
	{
		sum=sum + s.fre[i];
	}
	return sum;
}
float addlast(int n, int l)
{
	float sum=0;
	for (int i=n; i<=l;i++)
	{
		sum=sum + s.fre[i];
	}
	return sum;
}
int shannoncode(int f,int n,int count)
{
	int num;
	float diff=9999;
	float a,b,c;
	if (f==n || (f+1)==n || f>=n)
	{
		if (f==n || f>=n)
		{
			count-=1;
			s.arr[f][count]=0;
			s.con[f]=count;
			return 0;
		}
		else if ((f+1)==n)
		{
			s.arr[f][count]=0;
			s.arr[n][count]=1;
			s.con[f]=count;
			s.con[n]=count;			
		}
		return 0;	
	}
	else
	{	
		for (int i = f; i <=n; i++)
		{
			a=addfirst(f,i);
			b=addlast(i+1,n);		
			c=fabs(a-b);
			if(diff<=c)		
			{
				num=i-1;
				break;
			}
			diff=c;	
		}
		for (int i = f; i <=num; i++)
		{
				s.arr[i][count]=0;
		}	
		for (int i =num+1; i <=n; i++)
		{
		
			s.arr[i][count]=1;
		}
		count+=1;	
		shannoncode(f,num,count);
		shannoncode(num+1,n,count);	
	}	
}

void main()
{
	int n,f,c;
	float sum1=0;	
	printf("********Shannon**********\n");
	printf("Enter number of element\n");
	scanf("%d",&n);
	printf("Enter number of frequency and symbol \n");
	for (int i = 0; i < n; i++)
	{
		scanf("%f %c",&s.fre[i],&s.sym[i]);
	}
	for (int i = 0; i <n; i++)
	{
		sum1=sum1 + s.fre[i];
	}	
	if (sum1==1)
	{	
		char tsym;
		float tfre;
		for (int i = 0; i < n-1;i++)
		{
			for (int j = i+1; j <n ; j++)
			{
				if (s.fre[i]<s.fre[j])
				{
					tfre=s.fre[i];
					s.fre[i]=s.fre[j];
					s.fre[j]=tfre;

					tsym=s.sym[i];
					s.sym[i]=s.sym[j];
					s.sym[j]=tsym;
				}
			}
		}
		printf("\n");
		for (int i = 0; i < n; i++)
		{
			printf("%c  :  %f\n",s.sym[i],s.fre[i]);
		}	
		shannoncode(0,n-1,0);
		printf("\nSymbol\tProbability\tCode\n");
		for (int i = 0; i < n;i++)
		{ 
		    printf("  %c\t %f\t",s.sym[i],s.fre[i]);
			for (int j = 0; j <=s.con[i] ; j++)
			{
				printf("%d ",s.arr[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Invalid INPUT\n");
	}	
}
//Example
//0.22 a 0.30 b 0.05 c 0.15 d 0.28 e                                    ==5
//0.25 a 0.25 b 0.125 c 0.125 d 0.0625 e 0.0625 f 0.0625 g 0.0625 h     ==8
//0.30 a 0.25 b 0.15 c 0.12 d 0.08 e 0.10 f                             ==6
//6 a 4 b 2 c 1 d 1 e 1 f                                               ==6
//1 a 1 b 1 c 1 d 1 e                                                   ==5