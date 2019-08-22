#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int i,noOfMinTerms=0,maxBit=0;
int minTermsDec[15],minTermsBin[15],noOfOnes[15];

int totalSizeCalc()
{
    for (i = 0; i < noOfMinTerms; i++)
    {
        maxBit += pow(2,i);
    }
    return maxBit;
}
void inputMinTerms()
{
    printf("Enter the minterms to be minimized: \n");
    for (i=0;i<maxBit;i++)
    {
        scanf("%d",minTermsDec[i]);
    }
}
void minTermsDectoBin()
{
    for(int i=0;i<noOfMinTerms;i++)
    {
        minTermsBin[i]=decToBin(minTermsDec[i]);
        noOfOnes[i]=calcNoOfOnes(minTermsBin[i]);
    }
}

int calcNoOfOnes(int num)
{
    int flag=0,tempNum=num,rem=0;
    while(tempNum>0)
    {
        rem=tempNum%10;
        if(rem==1)
            flag++;
        tempNum/=10;
    }
    return flag;
}

int decToBin(int num)
{
    int binNo=0,z=1;
    for(int x=num;x>0;x=x/2)
    {
        binNo=binNo+(num%2)*z;
        z=z*10;
        num=num/2;
    }
    return binNo;
}

int main()
{
    printf("Enter the number of variables to be Minimized: ");
    scanf("%d",&noOfMinTerms);
    maxBit=totalSizeCalc();
    inputMinTerms();
    minTermsDectoBin();
    

    return 0;
}
