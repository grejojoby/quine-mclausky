#include<stdio.h>
#include<stdlib.h>
#define size 100
int top=-1,counter,c1=0,c2=0,c3=0,c4=0,n;
char c;
char a[100],b[100];
int isfull();
int isempty();
void push(char);
char pop();
char priority(char);
int decimalToBinary(int);

struct quine
{
	int dec;
	int no_of_1s;
}q[100],q1[100],q2[100],q3[100],q4[100];


int isfull()
{
	if(a[top]==size-1)
		return 1;
	else
		return 0;

}
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void push(char c)
{
	if(isempty())
		a[++top]=c;
	else
		printf("stack overflow");
}
char pop()
{
	if(isempty())
		printf("stack underflow");
	else
		return (a[top--]);

}


int decimalToBinary(int decimalnum)
{
    int  binarynum = 0;
    int rem, temp = 1;
    counter=0;
   
    while (decimalnum!=0)
    {
        rem = decimalnum%2;

        if(rem==1)
        counter++;

        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem*temp;
        temp = temp * 10;
      
    }
  
    return binarynum;
}



int input()
{	
	int i,temp;
	printf("enter the no of minterms");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	
		scanf("%d",&temp);
		q[i].dec=decimalToBinary(temp);
		q[i].no_of_1s=counter;
	}
}
 int output()
 {int i;
 	for(i=0;i<n;i++)
	{	
		printf("%d %d\n",q[i].dec,q[i].no_of_1s);
	}

 }

 int group1()
 {
 int i;
 	for(i=0;i<n;i++)
	{	
		if(q[i].no_of_1s==1)
		{q1[c1]=q[i];
		c1++;
		}

		if(q[i].no_of_1s==2)
			
			{
				q2[c2]=q[i];
				c2++;
			}
		if(q[i].no_of_1s==3)
			{
				q3[c3]=q[i];
				c3++;
			}
		if(q[i].no_of_1s==4)
			{
				q4[c4]=q[i];
				c4++;
			}
	}
	for(i=0;i<c1;i++)
	{	
		printf("%d %d\n",q1[i].dec,q1[i].no_of_1s);
	}
		for(i=0;i<c2;i++)
	{	
		printf("%d %d\n",q2[i].dec,q2[i].no_of_1s);
	}
		for(i=0;i<c3;i++)
	{	
		printf("%d %d\n",q3[i].dec,q3[i].no_of_1s);
	}
		for(i=0;i<c4;i++)
	{	
		printf("%d %d\n",q4[i].dec,q4[i].no_of_1s);
	}
 }


int main()
{

input();
group1();
}