#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#define MAX 5
struct stack
{
	int item;
	struct stack *link;
}NODE;
int count;
NODE* push(struct stack *,int);
NODE* pop(struct stack *);
void display(struct stack *);
struct stack *getnode()
{
	struct stack *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	return temp;
}
void main()
{
	struct stack *p;
	p=NULL;count=0;
	int ch,ele,status=0;
	while(true)
	{
		system("cls");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("Enter Element To Push : ");
			scanf("%d",&ele);
			p=push(p,ele);
			break;
		case 2:p=pop(p);
			break;
		case 3:display(p);
			break;
		case 4:exit(0);
		}
		getch();
	}
}
NODE* push(struct stack *top,int ele)
{
	if(count==MAX)
	{
		printf("Stack Overflow");
		return;
	}
	NODE *temp;
	temp=getnode();
	temp->item=ele;
	temp->link=top;
	top=temp;
	count++;
	return top;
}
NODE* pop(struct stack *top)
{
	struct stack *temp;
	int del;
	if(top==NULL)
	{
		printf("Stack Underflow");
		return top;
	}
	temp=top;
	del=temp->item;
	top=(top)->link;
	free(temp);
	count--;
	printf("Element Deleted is %d",del);
	return top;	
}

void display(struct stack *top)
{
	if(top==NULL)
	{
		printf("Stack Empty");
		return;
	}
	struct stack *temp;
	temp=top;
	while(temp!=NULL)
	{
		printf("%d\n",temp->item);
		temp=temp->link;
	}
	printf("\n");
}
