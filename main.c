/*
TODO

don't print if array empty - condition check before printing
parity check
parity table


*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int decToBin(int);
int totalSizeCalc();
void minTermsDectoBin();
int calcNoOfOnes(int[]);
void displayArray(int[][4], int);
void displayArray1(int[][5], int);
void displayArray2(int[][7], int);
void displayArray3(int[][9], int);
void displayArray4(int[][13], int);
//void displayArray5(int [][13],int);
int compare(int[][5], int[][5], int[][7], int, int);

int compare1(int[][7], int[][7], int[][9], int, int);
int compare2(int[][9], int[][9], int[][13], int, int);
//int compare3(int [][11],int [][11],int [][13],int,int);
int compareSame(int[][9], int);
int compareSame2(int[][13], int);
int compareSamefinal(int a[][5], int size);
//int compareSame3(int [][13], int);

void firstStage();
void display();
void printParityTable();
void parityInit();
int paritycheck2(int a[][7], int b[][7], int h[][7], int first, int, int second);
int paritycheck1(int a[][5], int b[][5], int h[][5], int first, int, int second);
int paritycheck3(int a[][9], int b[][9], int h[][9], int first, int, int second);

int parityCmp1(int a[][5], int b[][5], int size1, int size2);
int primeCheck();
int checkForSingle(int column);
int parityToEqt();

void displayFinal();

int i, j, l, k, c, noOfVariables = 0, maxBit = 0, noOfMinTerms = 0;
int minTermsDec[16], minTermsBin[16][5], noOfOnes[16];
int g0[14][5], g1[16][5], g2[16][5], g3[16][5], g4[16][5];
int h0[16][7], h1[16][7], h2[16][7], h3[16][7];
int i0[16][9], i1[16][9], i2[16][9];
int k0[16][13], k1[16][13];
//int l0[16][13];
int parityTable[20][24];
int gzero = 0, gone = 0, gtwo = 0, gthree = 0, gfour = 0;
int hzero = 0, hone = 0, htwo = 0, hthree = 0;
int izero = 0, ione = 0, itwo = 0;
//int jzero=0;
int kzero = 0, kone = 0;
int final[100][5];
int finalc = 0;

//int lzero=0;
int parityCnt = 0;

int parityToEqt()
{

	for (j = 0; j < 16; j++)
	{
		if (checkForSingle(j) != 100)
		{

			final[finalc][0] = parityTable[checkForSingle(j)][20];
			final[finalc][1] = parityTable[checkForSingle(j)][21];
			final[finalc][2] = parityTable[checkForSingle(j)][22];
			final[finalc][3] = parityTable[checkForSingle(j)][23];
			finalc++;
		}
	}
}

int compareSamefinal(int a[][5], int size)
{
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size;)
		{
			if ((a[j][0] == a[i][0]) && (a[j][1] == a[i][1]) && (a[j][2] == a[i][2]) && (a[j][3] == a[i][3]))
			{
				for (k = j; k < size; k++)
				{
					a[k][0] = a[k + 1][0];
					a[k][1] = a[k + 1][1];
					a[k][2] = a[k + 1][2];
					a[k][3] = a[k + 1][3];
				}
				size--;
			}
			else
			{
				j++;
			}
		}
	}
	return size;
}

int checkForSingle(int column)
{
	int patc = 0, temp121 = 0;
	for (i = 0; i < parityCnt; i++)
	{
		if (parityTable[i][column] == 999)
		{
			temp121 = i;
			patc++;
		}
	}
	if (patc == 1)
		return temp121;
	else
		return 100;
}

int paritycheck3(int a[][9], int b[][9], int h[][9], int first, int second, int third)
{
	int y = 0, t = 0;
	while (t != first)
	{
		int c = 0;
		for (i = 0; i < second; i++)
		{

			int flag = 0;
			for (j = 0; j < 4; j++)
			{
				if (a[t][j] != b[i][j])
				{
					flag++;
				}
			}
			if (flag == 1)
			{

				c++;
				y++;
			}
		}
		for (i = 0; i < third; i++)
		{

			int flag = 0;
			for (j = 0; j < 4; j++)
			{
				if (a[t][j] != h[i][j])
				{
					flag++;
				}
			}
			if (flag == 1)
			{

				c++;
				y++;
			}
		}
		if (c == 0)
		{

			parityTable[parityCnt][16] = a[t][4];
			parityTable[parityCnt][17] = a[t][5];
			parityTable[parityCnt][18] = a[t][6];
			parityTable[parityCnt][19] = a[t][7];

			parityTable[parityCnt][23] = a[t][3];
			parityTable[parityCnt][22] = a[t][2];
			parityTable[parityCnt][21] = a[t][1];
			parityTable[parityCnt][20] = a[t][0];

			parityTable[parityCnt][a[t][7]] = 999;
			parityTable[parityCnt][a[t][6]] = 999;
			parityTable[parityCnt][a[t][5]] = 999;
			parityTable[parityCnt][a[t][4]] = 999;
			parityCnt++;
		}

		t++;
	}
}

int paritycheck2(int a[][7], int b[][7], int h[][7], int first, int second, int third)
{
	int y = 0, t = 0;
	while (t != first)
	{
		int c = 0;
		for (i = 0; i < second; i++)
		{

			int flag = 0;
			for (j = 0; j < 4; j++)
			{
				if (a[t][j] != b[i][j])
				{
					flag++;
				}
			}
			if (flag == 1)
			{

				c++;
				y++;
			}
		}
		for (i = 0; i < third; i++)
		{

			int flag = 0;
			for (j = 0; j < 4; j++)
			{
				if (a[t][j] != h[i][j])
				{
					flag++;
				}
			}
			if (flag == 1)
			{

				c++;
				y++;
			}
		}
		if (c == 0)
		{
			parityTable[parityCnt][16] = a[t][4];
			parityTable[parityCnt][17] = a[t][5];

			parityTable[parityCnt][23] = a[t][3];
			parityTable[parityCnt][22] = a[t][2];
			parityTable[parityCnt][21] = a[t][1];
			parityTable[parityCnt][20] = a[t][0];

			parityTable[parityCnt][a[t][5]] = 999;
			parityTable[parityCnt][a[t][4]] = 999;
			parityCnt++;
		}

		t++;
	}
}

int paritycheck1(int a[][5], int b[][5], int h[][5], int first, int second, int third)
{
	int y = 0, t = 0;
	while (t != first)
	{
		int c = 0;
		for (i = 0; i < second; i++)
		{

			int flag = 0;
			for (j = 0; j < 4; j++)
			{
				if (a[t][j] != b[i][j])
				{
					flag++;
				}
			}
			if (flag == 1)
			{

				c++;
				y++;
			}
		}
		for (i = 0; i < third; i++)
		{

			int flag = 0;
			for (j = 0; j < 4; j++)
			{
				if (a[t][j] != h[i][j])
				{
					flag++;
				}
			}
			if (flag == 1)
			{

				c++;
				y++;
			}
		}
		if (c == 0)
		{

			parityTable[parityCnt][16] = a[t][4];
			parityTable[parityCnt][23] = a[t][3];
			parityTable[parityCnt][22] = a[t][2];
			parityTable[parityCnt][21] = a[t][1];
			parityTable[parityCnt][20] = a[t][0];
			parityTable[parityCnt][a[t][4]] = 999;
			parityCnt++;
		}

		t++;
	}
}

int totalSizeCalc()
{
	for (i = 0; i < noOfVariables; i++)
	{
		maxBit = maxBit + pow(2, i);
	}
	return maxBit + 1;
}

void inputMinTerms()
{
	printf("Enter the minterms to be minimized: \n");
	int inp = 0;
	for (i = 0; i < maxBit; i++)
	{

		if (inp >= (maxBit))
		{

			return;
		}
		if (inp == (-1))
		{
			noOfMinTerms--;
			return;
		}

		else
		{ //printf("enter minterm %d\t",i+1);
			scanf("%d", &inp);
			minTermsDec[i] = inp;
			noOfMinTerms++;
		}
	}
}

int calcNoOfOnes(int num[])
{
	int flag = 0;
	for (i = 0; i < maxBit; i++)
	{
		if (num[i] == 1)
			flag++;
	}
	return flag;
}

void minTermsDectoBin()
{
	int temp;
	for (i = 0; i <= noOfMinTerms; i++)
	{
		for (j = 0; j < noOfMinTerms; j++)
		{
			temp = minTermsDec[j];
			minTermsBin[j][4] = temp;
			for (l = 3; l >= 0; l--)
			{
				minTermsBin[j][l] = temp % 2;
				temp = temp / 2;
			}
			if (minTermsDec[j] == 1)
				noOfOnes[j] = 1;
			else
				noOfOnes[j] = calcNoOfOnes(minTermsBin[j]);
		}
	}
}

void firstStage()
{

	for (i = 0; i < noOfMinTerms; i++)
	{
		if (noOfOnes[i] == 0)
		{

			for (j = 0; j < 5; j++)
			{
				g0[gzero][j] = minTermsBin[i][j];
			}
			gzero++;
		}

		if (noOfOnes[i] == 1)
		{

			for (j = 0; j < 5; j++)
			{
				g1[gone][j] = minTermsBin[i][j];
			}
			gone++;
		}
		if (noOfOnes[i] == 2)
		{

			for (j = 0; j < 5; j++)
			{
				g2[gtwo][j] = minTermsBin[i][j];
			}
			gtwo++;
		}
		if (noOfOnes[i] == 3)
		{

			for (j = 0; j < 5; j++)
			{
				g3[gthree][j] = minTermsBin[i][j];
			}
			gthree++;
		}
		if (noOfOnes[i] == 4)
		{

			for (j = 0; j < 5; j++)
			{
				g4[gfour][j] = minTermsBin[i][j];
			}
			gfour++;
		}
	}
}
void display()
{
	for (j = 0; j < noOfMinTerms; j++)
	{
		printf("%d\t", noOfOnes[j]);
	}
}

void displayFinal()
{
	printf("finalc:%d\n", finalc);
	for (i = 0; i < finalc; i++)
	{
		for (j = 0; j < 4; j++)
		{

			printf("%d\t", final[i][j]);
		}
		printf("\n");
	}
}

void displayArray(int a[][4], int n)
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void displayArray1(int a[][5], int n)
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void displayArray2(int a[][7], int n)
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void displayArray3(int a[][9], int n)
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void displayArray4(int a[][13], int n)
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

int compare(int a[][5], int b[][5], int h[][7], int first, int second)
{
	int y = 0, t = 0;
	while (t < first)
	{
		int c = 0;
		for (i = 0; i < second; i++)
		{

			int flag = 0;
			for (j = 0; j < 4; j++)
			{
				if (a[t][j] == b[i][j])
				{
					h[y][j] = b[i][j];
				}
				else
				{
					h[y][j] = 9;
					flag++;
				}
			}
			if (flag == 1)
			{
				h[y][4] = a[t][4];
				h[y][5] = b[i][4];
				if (h[y][6] == 0)
					h[y][6] = 1;
				y++;
				c++;
			}
		}

		t++;
	}
	return y;
}

int compare1(int a[][7], int b[][7], int h[][9], int first, int second)
{
	int y = 0, t = 0;
	while (t != first)
	{
		int c = 0;
		for (i = 0; i < second; i++)
		{

			int flag = 0;
			for (j = 0; j < 4; j++)
			{
				if (a[t][j] == b[i][j])
				{
					h[y][j] = b[i][j];
				}
				else
				{
					flag++;
					h[y][j] = 9;
				}
			}
			if (flag == 1)
			{
				h[y][4] = a[t][4];
				h[y][5] = a[t][5];
				h[y][6] = b[i][4];
				h[y][7] = b[i][5];
				c++;
				y++;
			}
		}

		t++;
	}
	return y;
}

int compare2(int a[][9], int b[][9], int h[][13], int first, int second)
{
	int y = 0, t = 0;
	while (t != first)
	{
		for (i = 0; i < second; i++)
		{

			int flag = 0;
			for (j = 0; j < 4; j++)
			{
				if (a[t][j] == b[i][j])
				{
					h[y][j] = b[i][j];
				}
				else
				{
					flag++;
					h[y][j] = 9;
				}
			}
			if (flag == 1)
			{

				h[y][4] = a[t][4];
				h[y][5] = a[t][5];
				h[y][6] = a[t][6];
				h[y][7] = a[t][7];

				h[y][8] = b[i][4];
				h[y][9] = b[i][5];
				h[y][10] = b[i][6];
				h[y][11] = b[i][7];

				if (h[y][12] == 0)
					h[y][12] = 1;
				y++;
			}
		}
		t++;
	}
	return y;
}

int compareSame(int a[][9], int size)
{
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size;)
		{
			if ((a[j][0] == a[i][0]) && (a[j][1] == a[i][1]) && (a[j][2] == a[i][2]) && (a[j][3] == a[i][3]))
			{
				for (k = j; k < size; k++)
				{
					a[k][0] = a[k + 1][0];
					a[k][1] = a[k + 1][1];
					a[k][2] = a[k + 1][2];
					a[k][3] = a[k + 1][3];
					a[k][4] = a[k + 1][4];
					a[k][5] = a[k + 1][5];
					a[k][6] = a[k + 1][6];
					a[k][7] = a[k + 1][7];
					a[k][8] = a[k + 1][8];
				}
				size--;
			}
			else
			{
				j++;
			}
		}
	}
	return size;
}

int compareSame2(int a[][13], int size)
{
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size;)
		{
			if ((a[j][0] == a[i][0]) && (a[j][1] == a[i][1]) && (a[j][2] == a[i][2]) && (a[j][3] == a[i][3]))
			{
				for (k = j; k < size; k++)
				{
					a[k][0] = a[k + 1][0];
					a[k][1] = a[k + 1][1];
					a[k][2] = a[k + 1][2];
					a[k][3] = a[k + 1][3];
					a[k][4] = a[k + 1][4];
					a[k][5] = a[k + 1][5];
					a[k][6] = a[k + 1][6];
					a[k][7] = a[k + 1][7];
					a[k][8] = a[k + 1][8];
					a[k][9] = a[k + 1][9];
					a[k][10] = a[k + 1][10];
					a[k][11] = a[k + 1][11];
					a[k][12] = a[k + 1][12];
				}
				size--;
			}
			else
			{
				j++;
			}
		}
	}
	return size;
}

void parityInit()
{
	for (i = 0; i < 20; i++)
		for (j = 0; j < 24; j++)
			parityTable[i][j] = -1;
}

void printParityTable()
{
	printf("Parity cnt %d\n", parityCnt);
	for (i = 0; i < parityCnt; i++)
	{
	    printf("\n P%d : ",i+1);
		for (j = 16; j < 20; j++)
		{
            if(parityTable[i][j]==-1)
                continue;
			else
			{
			    printf(" %d ", parityTable[i][j]);
			    if(j!=19 && parityTable[i][j+1]!=-1)
                    printf(",");
			}
		}

		printf("\n");
	}
}

void eqnGenerator()
{
    printf("\n The Equation is : \t");
    for(i=0;i<finalc;i++)
    {
        if(i!=0)
            printf(" + ");
        for(j=0;j<4;j++)
        {

            if(j==0)
            {
                if(final[i][j]==0)
                    printf("A'");
                else if(final[i][j]==1)
                    printf("A");
            }
            else if(j==1)
            {
                if(final[i][j]==0)
                    printf("B'");
                else if(final[i][j]==1)
                    printf("B");
            }
            else if(j==2)
            {
                if(final[i][j]==0)
                    printf("C'");
                else if(final[i][j]==1)
                    printf("C");
            }
            else if(j==3)
            {
                if(final[i][j]==0)
                    printf("D'");
                else if(final[i][j]==1)
                    printf("D");
            }
        }

    }

}

int main()
{
	printf("Enter the number of variables to be Minimized: ");
	scanf("%d", &noOfVariables);
	maxBit = totalSizeCalc();
	parityInit();
	inputMinTerms();
	minTermsDectoBin();
	printf("\n\n  **STAGE 1**\n\n");
	firstStage();
	if (gzero != 0)
    {
        printf("\ngroup of 0s\n");
        displayArray1(g0, gzero);
    }
    if(gone!=0)
    {
        printf("\ngroup of 1s\n");
        displayArray1(g1, gone);
    }
    if(gtwo!=0)
    {
        printf("\ngroup of 2s\n");
        displayArray1(g2, gtwo);
    }
    if(gthree!=0)
    {
        printf("\ngroup of 3s\n");
        displayArray1(g3, gthree);
    }
    if(gfour!=0)
    {
        printf("\ngroup of 4s\n");
        displayArray1(g4, gfour);
    }

	printf("\n\n  **STAGE 2**\n\n");

	hzero = compare(g0, g1, h0, gzero, gone);
	if (hzero != 0)
	{
        printf("\n\nComparing Group 0 with 1:\n");
		displayArray2(h0, hzero);
	}

	hone = compare(g1, g2, h1, gone, gtwo);
	if (hone != 0)
	{
        printf("\n\nComparing Group 1 with 2:\n");
		displayArray2(h1, hone);
	}

	htwo = compare(g2, g3, h2, gtwo, gthree);
	if (htwo != 0)
	{
	    printf("\n\nComparing Group 2 with 3:\n");
		displayArray2(h2, htwo);
	}

	hthree = compare(g3, g4, h3, gthree, gfour);
	if (hthree != 0)
	{
        printf("\n\nComparing Group 3 with 4:\n");
		displayArray2(h3, hthree);
	}
	printf("\n\n    **STAGE 3**\n\n");
	izero = compare1(h0, h1, i0, hzero, hone);
	izero = compareSame(i0, izero);
	if (izero != 0)
	{
		printf("\n\nComparing Group 0 with 1:\n");
		displayArray3(i0, izero);
	}

	ione = compare1(h1, h2, i1, hone, htwo);
	ione = compareSame(i1, ione);
	if (ione != 0)
	{

		printf("\n\nComparing Group 1 with 2:\n");
		displayArray3(i1, ione);
	}

	itwo = compare1(h2, h3, i2, htwo, hthree);
	itwo = compareSame(i2, itwo);
	if (itwo != 0)
	{

		printf("\n\nComparing Group 2 with 3:\n");
		displayArray3(i2, itwo);
	}

	printf("\n\n Parity Check \n\n");
	paritycheck1(g0, g1, g1, gzero, gone, gone);
	paritycheck1(g1, g2, g0, gone, gtwo, gzero);
	paritycheck1(g2, g3, g1, gtwo, gthree, gone);
	paritycheck1(g3, g4, g2, gthree, gfour, gtwo);
	paritycheck1(g4, g3, g3, gfour, gthree, gthree);

	paritycheck2(h0, h1, h1, hzero, hone, hone);
	paritycheck2(h1, h0, h2, hone, hzero, htwo);
	paritycheck2(h2, h1, h3, htwo, hone, hthree);
	paritycheck2(h3, h2, h2, hthree, htwo, htwo);

	paritycheck3(i0, i1, i1, izero, ione, ione);
	paritycheck3(i1, i0, i2, ione, izero, itwo);
	paritycheck3(i2, i1, i1, itwo, ione, ione);

	parityToEqt();
	printParityTable();
	finalc = compareSamefinal(final, finalc);
	printf("\n");
	//displayFinal();
	eqnGenerator();
	printf("\n\n\t\tTHANK YOU FOR USING THIS SOFTWARE....\n\n \tMade By : \n\t\tGrejo Joby and Hayden Cordeiro\n\n");
	return 0;
}
