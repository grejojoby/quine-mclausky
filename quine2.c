#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int decToBin(int);
int totalSizeCalc();
void minTermsDectoBin();
int calcNoOfOnes(int[]);
void displayBinArray();



int i,j,l,k,c,noOfVariables=0,maxBit=0,noOfMinTerms=0;
int minTermsDec[16],minTermsBin[16][4],noOfOnes[16];

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
	printf("%d",maxBit);
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
		{	printf("Loop\t");
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
			
  			
			}
			
		noOfOnes[i]=calcNoOfOnes(minTermsBin[i]);
		
    }
}


void displayBinArray()
{
	for(i=0;i<noOfMinTerms;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",minTermsBin[i][j]);
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
	displayBinArray();	
    

    return 0;
}
