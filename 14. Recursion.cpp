#include <stdio.h>
#include <conio.h>
int search(int a[20],int key,int low,int high)
{
	int mid;
	mid=(low+high)/2;
	if(a[mid]==key)
		return mid;
	if(low>high)
		return -1;
	if(a[mid]>key)
		search(a,key,low,mid-1);
	else
		search(a,key,mid+1,high);
}
void main()
{
	int a[20],key,n,i,found=-1;
	printf("Enter Value Of n : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter Value To Search : ");
	scanf("%d",&key);
	found=search(a,key,0,n-1);
	if(found==-1)
		printf("Element Not Found In Array");
	else
		printf("The Element Was Found At pos : %d",found+1);
	getch();
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
