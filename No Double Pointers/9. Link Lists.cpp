/**
* Author : SkyKOG
* Operation On Linked Lists
*
*
*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>

typedef struct node
{
	int id;
	char name[20];
	int sem;
	struct node *link;
}NODE;

NODE * addatbeg(struct node *);
void display(struct node *);
NODE *getnode();
NODE* append(struct node *);
NODE* addatpos(struct node *,int);
NODE* search(struct node *);
NODE* del(struct node *);
NODE* getdata(struct node *);

NODE *getnode()
 {
	 NODE *temp;
	 temp=(NODE *)malloc(sizeof(NODE));
	 return temp;
 }
 void main()
 {
	 NODE *p;
	 p=NULL;
	 int ch,ele,pos=0;
	 while(true)
	 {
		 system("cls");
		 printf("1. Insert At Front\n2. Display\n3. Exit\n4. Add At Back\n5. Add At Pos\n6. Search n Update\n7. Delete\n\nEnter Choice : ");
		 scanf("%d",&ch);
		 switch(ch)
		 {
		 case 1:printf("Enter Record To Insert : ");
			 
			 p=addatbeg(p);
			 break;
		 case 2:display(p);
			 break;
		 case 3:exit(0);
			 break;
		 case 4:printf("Enter Record To Insert : ");
			 
			 p=append(p);
			 break;
		 case 5: printf("Enter Position To Insert At : ");
			 scanf("%d",&pos);
			 p=addatpos(p,pos);
			 break;
		 case 6:search(&p);
			 break;
		 case 7:p=del(p);
			 break;
		 default:printf("Invalid Selection");
		 }
		 getch();
	 }
 }
NODE* addatbeg(struct node *q)
 {
	 struct node *temp;
	 temp=getnode();
	 temp=getdata(temp);
	 temp->link=q;
	 q=temp;
	 return q;
 }
void display(struct node *q)
{
	if(q==NULL)
	{
		printf("Empty List");
		return;
	}
	printf("ID\tName\tSem\n\n");
	while(q!=NULL)
	{
	
	printf("%d\t",q->id);
	
	printf("%s\t",q->name);
	
	printf("%d\n",q->sem);

	q=q->link;
	}
	printf("\n");
}
NODE * append(struct node *q)
{
	struct node *temp,*r;
	if(q==NULL)
	{
		q=addatbeg(q);
		return q;
	}

	else
	{
		temp=q;
		while(temp->link !=NULL)
			temp=temp->link;
		r=getnode();
		r=getdata(r);
		r->link=NULL;
		temp->link=r;
	}
	return q;
}
NODE* addatpos(struct node *q,int pos)
{
	struct node *temp,*r;
	int i;
	if(pos==0)
	{
		q=addatbeg(q);
		return q;
	}
	temp=q;
	for(i=1;i<pos;i++)
	{
		temp=temp->link;
		if(temp==NULL)
		{
			printf("There Are less Than %d Elements In List",pos);
			return q;
		}
	}
	r=getnode();
	r=getdata(r);
	r->link=temp->link;
	temp->link=r;
	return q;
}

NODE *search(struct node *q)
{
	int ele,found=0,ch;
	printf("Enter ID To Search Upon : ");
	scanf("%d",&ele);
	struct node *temp;
	temp=q;
	while(temp!=NULL)
	{
		if(temp->id==ele)
		{
			found=1;
			printf("Found");
			printf("\nUpdate ?? : ");
			scanf("%d",&ch);
			if(ch==1)
			{
				printf("Enter New Data : ");
				temp=getdata(temp);
				return q;
			}			
			return q;
		}
		temp=temp->link;
		
	}
	printf("Element Not in List");
	return q;
}

void del(struct node *q)
{
	struct node *temp,*prev;
	temp=q;int ele;
	printf("Enter ID To Delete : ");
	scanf("%d",&ele);
	while(temp!=NULL)
	{
		if(temp->id==ele)
		{
			if(temp==q)
			{
				q=temp->link;
			}
			else
			{
				prev->link=temp->link;
			}
			free(temp);
			printf("Item Deleted");
			return q;
		}
		else
		{
			prev=temp;
			temp=temp->link;
		}
	}
	
	printf("Element Not Found In List");
	return q;
}
NODE* getdata(struct node *q)
{
	printf("\nEnter Student ID : ");
	scanf("%d",q->id);
	printf("Enter Name : ");
	scanf("%s",q->name);
	printf("Enter Sem : ");
	scanf("%d",q->sem);
	return q;
}