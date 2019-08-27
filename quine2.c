#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int decToBin(int);
int totalSizeCalc();
void minTermsDectoBin();
int calcNoOfOnes(int[]);
void displayArray(int [][4],int);
int compare(int [][4],int [][4],int [][4],int,int);
void firstStage();
void display();



int i,j,l,k,c,noOfVariables=0,maxBit=0,noOfMinTerms=0;
int minTermsDec[16],minTermsBin[16][4],noOfOnes[16];
int g0[14][4],g1[16][4],g2[16][4],g3[16][4],g4[16][4];
int h0[16][4],h1[16][4],h2[16][4],h3[16][4];
int i0[16][4],i1[16][4],i2[16][4];
int gzero=0,gone=0,gtwo=0,gthree=0,gfour=0;
int hzero=0,hone=0,htwo=0,hthree=0;
int izero=0,ione=0,itwo=0;

int totalSizeCalc()
{
    for (i = 0; i < noOfVariables; i++)
    {
        maxBit =maxBit + pow(2,i);
    }
    return maxBit+1;
}

void inputMinTerms()
{
	printf("Enter the minterms to be minimized: \n");
	int inp=0;    
	for(i=0;i<maxBit;i++)
	{	

		if(inp>=(maxBit))
		{
			
			return;
		}
		if(inp == (-1))
		{
			noOfMinTerms--;
			return;
		}

		else
		{	printf("enter minterm %d\t",i+1);
			scanf("%d",&inp);
			minTermsDec[i] = inp;
			noOfMinTerms++;	
		}
		printf("\n");
	
	}
}


int calcNoOfOnes(int num[])
{
    int flag=0;
    for(i=0;i<maxBit;i++)
    {
	if(num[i]==1)
		flag++;
    }

    return flag;
}

void minTermsDectoBin()
{	 
int temp;
    for(i=0;i<=noOfMinTerms;i++)
    {
    	
			for(j=0;j<noOfMinTerms;j++)
			{
        		temp=minTermsDec[j];
				for(l=4-1;l>=0;l--)
				{
				minTermsBin[j][l]=temp%2;
				temp=temp/2;
				}
			noOfOnes[j]=calcNoOfOnes(minTermsBin[j]);
  			
			}
			
		
		
    }
}

void firstStage()
{
for(i=0;i<noOfMinTerms;i++)
{	
	if(noOfOnes[i]==0)
	{	

		for(j=0;j<4;j++)
		{
		g0[gzero][j]=minTermsBin[i][j];
		}
		gzero++;
	}

	if(noOfOnes[i]==1)
	{	

		for(j=0;j<4;j++)
		{
		g1[gone][j]=minTermsBin[i][j];
		}
		gone++;
	}
	if(noOfOnes[i]==2)
	{	

		for(j=0;j<4;j++)
		{
		g2[gtwo][j]=minTermsBin[i][j];
		}
		gtwo++;
	}
	if(noOfOnes[i]==3)
	{	

		for(j=0;j<4;j++)
		{
		g3[gthree][j]=minTermsBin[i][j];
		}
		gthree++;
	}
	if(noOfOnes[i]==4)
	{	

		for(j=0;j<4;j++)
		{
		g4[gfour][j]=minTermsBin[i][j];
		}
		gfour++;
	}

}
}
void display()
{
	for(j=0;j<noOfMinTerms;j++)
		{
			printf("%d\t",noOfOnes[j]);
		}
}

void displayArray(int a[][4],int n)
{	
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}

}

int compare(int a[][4],int b[][4],int h[][4],int first,int second)
{
	int y=0,t=0;
while(t!=first)
{
	for(i=0;i<second;i++)
	{

		int flag=0;
		for(j=0;j<4;j++)
		{
			if(a[t][j]==b[i][j])
			{
				h[y][j]=b[i][j];
			}
			else
			{
				flag++;
				h[y][j]=9;
			}
		}
		if(flag==1)
		{
			y++;
		}

	}
	t++;
}
	return y;
}

int main()
{
    printf("Enter the number of variables to be Minimized: ");
    scanf("%d",&noOfVariables);
    maxBit=totalSizeCalc();
	
    inputMinTerms();
 	minTermsDectoBin();
 	printf("\n\n  **STAGE 1**\n\n");
	firstStage();
	printf("\ngroup of 0s\n");
	displayArray(g0,gzero);
	printf("\ngroup of 1s\n");
	displayArray(g1,gone);
	printf("\ngroup of 2s\n");
	displayArray(g2,gtwo);
	printf("\ngroup of 3s\n");
	displayArray(g3,gthree);
	printf("\ngroup of 4s\n");
	displayArray(g4,gfour);
	printf("\n\n  **STAGE 2**\n\n");
	printf("\n\nComparing Group 0 with 1:\n");
	hzero = compare(g0,g1,h0,gzero,gone);
	displayArray(h0,hzero);
	printf("\n\nComparing Group 1 with 2:\n");
	hone = compare(g1,g2,h1,gone,gtwo);
	displayArray(h1,hone);
	printf("\n\nComparing Group 2 with 3:\n");
	htwo = compare(g2,g3,h2,gtwo,gthree);
	displayArray(h2,htwo);
	printf("\n\nComparing Group 3 with 4:\n");
	hthree = compare(g3,g4,h3,gthree,gfour);
	displayArray(h3,hthree);
	printf("\n\n    **STAGE 3**\n\n");
	printf("\n\nComparing Group 0 with 1:\n");
	izero = compare(h0,h1,i0,hzero,hone);
	displayArray(i0,izero);
	printf("\n\nComparing Group 1 with 2:\n");
	ione = compare(h1,h2,i1,hone,htwo);
	displayArray(i1,ione);
	printf("\n\nComparing Group 2 with 3:\n");
    itwo = compare(h2,h3,i2,htwo,hthree);
	displayArray(i2,itwo);
    return 0;
}

