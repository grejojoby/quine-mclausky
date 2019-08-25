#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int decToBin(int);
int totalSizeCalc();
void minTermsDectoBin();
int calcNoOfOnes(int[]);
void displayBinArray();



int i,j,l,k,c,noOfVariables=0,maxBit=0,noOfMinTerms=0;
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
	printf("%d",maxBit);
	for(i=0;i<maxBit;i++)
	{	

		if(inp == (-1) || inp>=(maxBit-1))
		{
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
void minTermsDectoBin()
{	 printf("entered dec to bin");
int temp;
    for(i=0;i<noOfVariables;i++)
    {
	for(j=0;j<4;j++)
	{
        	
        	for(k=0;k<noOfMinTerms;k++)
  		{
			for(l=noOfMinTerms-1;l>=0;l--)
			{
				temp=minTermsDec[k];
				minTermsBin[k][l]=temp%2;
				temp=temp/2;
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
void display()
{
	for(j=0;j<noOfMinTerms;j++)
		{
			printf("%d\n",minTermsDec[j]);
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
