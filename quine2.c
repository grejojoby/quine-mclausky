#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int decToBin(int);
int totalSizeCalc();
void minTermsDectoBin();
int calcNoOfOnes(int[]);
void displayBinArray();



int i,j,c,noOfVariables=0,maxBit=0,noOfMinTerms=0;
int minTermsDec[15],minTermsBin[15][4],noOfOnes[15];

int totalSizeCalc()
{
    for (i = 0; i < noOfVariables; i++)
    {
        maxBit += pow(2,i);
    }
    return maxBit+1;
}

void inputMinTerms()
{
	printf("Enter the minterms to be minimized: \n");
	int inp=0;    
	for(i=0;i<maxBit;i++)
	{
		if(inp==-1 || inp>=maxBit-1)
		{
			return;
		}
		else
		{
			scanf("%d",&inp);
			minTermsDec[i] = inp;
			noOfMinTerms++;	
		}
	printf("Loop");
	}
}
void minTermsDectoBin()
{
    for(i=0;i<noOfVariables;i++)
    {
	for(j=0;j<4;j++)
	{
        	
        	for(i=0;i<noOfMinTerms;i++)
  		{
			for(j=noOfMinTerms-1;j>=0;j--)
			{
				int temp=minTermsDec[i];
				minTermsBin[i][j]=temp%2;
				temp/=2;
			}
			
  		}
	}
	noOfOnes[i]=calcNoOfOnes(minTermsBin[i]);    
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
	printf("%d",maxBit);
    inputMinTerms();
    minTermsDectoBin();
	displayBinArray();
    

    return 0;
}
