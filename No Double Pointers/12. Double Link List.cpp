#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <windows.h>

struct node 
{
	int item;
	struct node *l;
	struct node *r;
}NODE;

NODE *getnode()
{
	struct node *temp;
	temp=(NODE *)malloc(sizeof(NODE));
	return temp;
}

NODE* addatbeg(NODE*,int);
NODE* del(NODE*);
NODE* addleft(NODE*,int,int);
void display(NODE*);

void main()
{
	struct node *p;
	p=NULL;
	int ele,ch,status=0,key=0;
	while(true)
	{
		system("cls");
		printf("1. Insert At Front\n2. Insert to Left\n3. Delete Node\n4. Display\n5. Exit\n\nEnter Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("Enter Element To Insert : ");
			scanf("%d",&ele);
			p=addatbeg(p,ele);
			break;
		case 2:printf("Enter Element To Insert : ");
			scanf("%d",&ele);
			printf("Enter Key To Search On : ");
			scanf("%d",&key);
			p=addleft(p,ele,key);
			break;
		case 3:p=del(p);
			break;
		case 4:display(p);
			break;
		case 5:exit(0);
			break;
		default:printf("Invalid Selection");
		}
		getch();
	}
}

NODE* addatbeg(struct node *q,int ele)
{
	NODE *temp,*r;
	temp=getnode();
	temp->item=ele;
	temp->l=NULL;
	temp->r=NULL;
	if(q==NULL)
	{
		q=temp;
		return q;
	}
	temp->r=q;
	(q)->l=temp;
	(q)=temp;
	return q;
}

NODE* addleft(struct node *q,int ele,int key)
{
	NODE *r,*temp;
	int flag=0;
	temp=getnode();
	r=q;
	if(r==NULL)
	{
		printf("Empty List");
		return;
	}
	if((q)->item==key)
	{
		q=addatbeg(q,ele);
		return q;
	}
	while(r->r!=NULL)
	{
		if(r->item==key)
		{
			temp->item=ele;
			temp->r=r;
			temp->l=r->l;
			r->l->r=temp;
			r->l=temp;
			flag=1;
		}
		r=r->r;
	}
	if((r->r==NULL)&&(r->item==key))
	{
		temp->item=ele;
		temp->r=r;
		temp->l=r->l;
		r->l->r=temp;
		r->l=temp;
		return q;
	}

	if(!flag)
		printf("Key Not Found In List");
	return q;
}
NODE* del(struct node *q)
{
	int ele,del;
	printf("Enter Element To Delete : ");
	scanf("%d",&ele);
	struct node *temp;
	temp=q;
	if(temp==NULL)
	{
		printf("List Is Empty");
		return q;
	}

	if(temp->item==ele)
	{
		(q)=(q)->r;
		free(temp);
		printf("Element Deleted");
		return q;
	}
	while(temp->r!=NULL)
	{
		if(temp->item==ele)
		{
			temp->l->r=temp->r;
			temp->r->l=temp->l;
			free(temp);
			printf("Element Deleted");
			return q;
		}
		temp=temp->r;
	}
	if((temp->r==NULL)&&(temp->item==ele))
	{
		temp->l->r=NULL;
		free(temp);
		printf("Element Deleted");
		return q;
	}
	printf("Element Not in List");
	return q;
}

void display(struct node *q)
{
	struct node *r;
	r=q;
	if(r==NULL)
	{
		printf("List Is Empty");
		return;
	}
	while(r!=NULL)
	{
		printf("%d ",r->item);
		r=r->r;
	}
	printf("\n");
}
	



