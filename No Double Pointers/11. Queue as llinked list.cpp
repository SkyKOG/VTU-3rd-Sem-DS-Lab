#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>

#define MAX 5

int count=0;
typedef struct queue 
{
	int item;
	struct queue *link;
}NODE;

NODE* insert(NODE*,int);
NODE* del(NODE*);
void display(NODE*);

void main()
{
	NODE *p;
	p=NULL;
	int ch,ele;
	while(true)
	{
		system("cls");
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\nEnter Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("Enter Element To Insert : ");
			scanf("%d",&ele);
			p=insert(p,ele);
			break;
		case 2:p=del(p);
			break;
		case 3:display(p);
			break;
		case 4:exit(0);
			break;
		default:printf("Invalid Choice");
			break;
		}
		getch();
	}
}

NODE* insert(struct queue *q,int ele)
{
	if(count==MAX)
	{
		printf("Queue Overflow");
		return;
	}
	struct queue *temp;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->item=ele;
	if(q==NULL)
	{
		temp->link=NULL;
		q=temp;
		count++;
		return q;
	}
	temp->link=(q);
	(q)=temp;
	count++;
	return q;
}

void del(struct queue **q)
{
	if(count==0)
	{
		printf("Queue Underflow");
		return;
	}
	struct queue *temp;
	temp=q;
	if(temp->link==NULL)
	{
		printf("Element Deleted : %d",temp->item);
		q=NULL;
		free(temp);count--;
		return q;
	}
	struct queue *cur,*prev;
	prev=NULL;
	cur=q;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	printf("Item Deleted : %d",cur->item);
	prev->link=NULL;
	free(cur);count--;
	return q;
}

void display(struct queue *q)
{
	struct queue *temp;
	temp=q;
	if(temp==NULL)
	{
		printf("Empty Queue");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->item);
		temp=temp->link;
	}
}
