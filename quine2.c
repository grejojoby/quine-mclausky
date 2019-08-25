#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int decToBin(int);
int totalSizeCalc();
void minTermsDectoBin();
int calcNoOfOnes(int[]);
void displayArray(int [][4],int);



int i,j,l,k,c,noOfVariables=0,maxBit=0,noOfMinTerms=0;
int minTermsDec[16],minTermsBin[16][4],noOfOnes[16];
int g1[16][4],g2[16][4],g3[16][4],g4[16][4];
int gone=0,gtwo=0,gthree=0,gfour=0;

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


int main()
{
    printf("Enter the number of variables to be Minimized: ");
    scanf("%d",&noOfVariables);
    maxBit=totalSizeCalc();
	
    inputMinTerms();
 	minTermsDectoBin();
 	printf("\n the binary array:\n");
	displayArray(minTermsBin,noOfVariables);
	firstStage();
	printf("\ngroup of 1s\n");
	displayArray(g1,gone);
	printf("\ngroup of 2s\n");
	displayArray(g2,gtwo);
	printf("\ngroup of 3s\n");
	displayArray(g3,gthree);
	printf("\ngroup of 4s\n");
	displayArray(g4,gfour);
    return 0;
}
