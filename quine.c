#include<stdio.h>
#include<stdlib.h>

int inputMain();
int decimalToBinary(int );
int firstStage();
void printGrps();

int input;

int counter=0;//count the no of ones
int counter2=0,c1=0,c2=0,c3=0,c4=0; //check if the each bit is same

struct node
{
	int bin1;
	int bin2;
	int bin3;
	int bin4;
	int counter;
	struct node *link;	
}*ptr,*p1=NULL,*p2=NULL,*p3=NULL,*p4=NULL,*p=NULL;


struct groups
{
	int bin1;
	int bin2;
	int bin3;
	int bin4;
	int counter;

}g1,g2,g3,g4;

struct node* create_node(struct node *start)
{
start=(struct node*)malloc(sizeof(struct node));
start->bin1=0;
start->bin2=0;
start->bin3=0;
start->bin4=0;
start->counter=0;
start->link=NULL;
return start;
}



struct node *insert_first(struct node *start)
{

if(start==NULL)
{
start=create_node(start);
}
else 
{
ptr=start;
start=create_node(start);
start->link=ptr;
}
return start;
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



int firstStage(struct node *ptr)
{	
		if(ptr->counter==1)
		{	printf("entered the  %d\n\n",p->counter);
			p1=insert_first(p1);
			p1->bin1=ptr->bin1;
			p1->bin2=ptr->bin2;
			p1->bin3=ptr->bin3;
			p1->bin4=ptr->bin4;
			p1->counter=ptr->counter;
			c1++;
		}
		else if(ptr->counter==2)
		{	printf("entered the  if %d\n\n",p->counter);
			p2=insert_first(p2);
			p2->bin1=p->bin1;
			p2->bin2=p->bin2;
			p2->bin3=p->bin3;
			p2->bin4=p->bin4;
			p2->counter=p->counter;
			c2++;
		}
		else if(ptr->counter==3)
		{	printf("entered the  if %d\n\n",p->counter);
			p3=insert_first(p3);
			p3->bin1=p->bin1;
			p3->bin2=p->bin2;
			p3->bin3=p->bin3;
			p3->bin4=p->bin4;
			p3->counter=p->counter;
			c3++;
		}
		else if(ptr->counter==4)
		{	printf("entered the  if %d\n\n",p->counter);
			p4=insert_first(p4);
			p4->bin1=p->bin1;
			p4->bin2=p->bin2;
			p4->bin3=p->bin3;
			p4->bin4=p->bin4;
			p4->counter=p->counter;
			c4++;
		}				
		
	
	

}

void printGrps()
{
	printf("\ngroup of 1s\n");
	display(p1);
	printf("\ngroup of 2s\n");
	display(p2);
	printf("\ngroup of 3s\n");
	display(p3);
	printf("\ngroup of 4s\n");
	display(p4);

}




int inputMain(int i)
{		
		int a;
		printf("enter the minterms %d",i);
		scanf("%d",&input);
		p=insert_first(p);
		a=decimalToBinary(input);
		p->counter=counter;
		p->bin4=a%10;
		a=a/10;
		p->bin3=a%10;
		a=a/10;
		p->bin2=a%10;
		a=a/10;
		p->bin1=a%10;

	

}

void display(struct node *ptr)
{

while(ptr!=NULL)
{
printf("%d\t%d\t%d\t%d\t%d\n",ptr->bin1,ptr->bin2,ptr->bin3,ptr->bin4,ptr->counter);
ptr=ptr->link;
}
}



int main()
{	
		int i;
		for(i=1;i<=4;i++)
		{
		inputMain(i);
		printf("\n");
		firstStage(p);

		}
		printGrps();
		printf("%d %d %d %d",c1,c2,c3,c4);

		
		

}
