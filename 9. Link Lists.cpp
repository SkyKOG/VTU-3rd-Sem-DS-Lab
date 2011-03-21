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

struct node
{
	int id;
	char name[20];
	int sem;
	struct node *link;
};

void addatbeg(struct node **);
void display(struct node *);
struct node *getnode();
void append(struct node **);
void addatpos(struct node **,int);
void search(struct node **);
void del(struct node **);
void getdata(struct node *);

 struct node *getnode()
 {
	 struct node *temp;
	 temp=(struct node *)malloc(sizeof(struct node));
	 return temp;
 }
 void main()
 {
	 struct node *p;
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
			 
			 addatbeg(&p);
			 break;
		 case 2:display(p);
			 break;
		 case 3:exit(0);
			 break;
		 case 4:printf("Enter Record To Insert : ");
			 
			 append(&p);
			 break;
		 case 5: printf("Enter Position To Insert At : ");
			 scanf("%d",&pos);
			 addatpos(&p,pos);
			 break;
		 case 6:search(&p);
			 break;
		 case 7:del(&p);
			 break;
		 default:printf("Invalid Selection");
		 }
		 getch();
	 }
 }
 void addatbeg(struct node **q)
 {
	 struct node *temp;
	 temp=getnode();
	 getdata(temp);
	 temp->link=*q;
	 *q=temp;
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
void append(struct node **q)
{
	struct node *temp,*r;
	if(*q==NULL)
	{
		addatbeg(q);
		return;
	}

	else
	{
		temp=*q;
		while(temp->link !=NULL)
			temp=temp->link;
		r=getnode();
		getdata(r);
		r->link=NULL;
		temp->link=r;
	}
}
void addatpos(struct node **q,int pos)
{
	struct node *temp,*r;
	int i;
	if(pos==0)
	{
		addatbeg(q);
		return;
	}
	temp=*q;
	for(i=1;i<pos;i++)
	{
		temp=temp->link;
		if(temp==NULL)
		{
			printf("There Are less Than %d Elements In List",pos);
			return;
		}
	}
	r=getnode();
	getdata(r);
	r->link=temp->link;
	temp->link=r;
}

void search(struct node **q)
{
	int ele,found=0,ch;
	printf("Enter ID To Search Upon : ");
	scanf("%d",&ele);
	struct node *temp;
	temp=*q;
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
				getdata(temp);
				return;
			}			
			return;
		}
		temp=temp->link;
	}
	printf("Element Not in List");
}

void del(struct node **q)
{
	struct node *temp,*prev;
	temp=*q;int ele;
	printf("Enter ID To Delete : ");
	scanf("%d",&ele);
	while(temp!=NULL)
	{
		if(temp->id==ele)
		{
			if(temp==*q)
			{
				*q=temp->link;
			}
			else
			{
				prev->link=temp->link;
			}
			free(temp);
			printf("Item Deleted");
			return;
		}
		else
		{
			prev=temp;
			temp=temp->link;
		}
	}
	
	printf("Element Not Found In List");
	
}
void getdata(struct node *q)
{
	printf("\nEnter Student ID : ");
	scanf("%d",&q->id);
	printf("Enter Name : ");
	scanf("%s",q->name);
	printf("Enter Sem : ");
	scanf("%d",&q->sem);
}



/*
License
=======
    Copyright (C) 2011 SkyKOG

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/