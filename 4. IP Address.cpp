#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
typedef union
{
	unsigned char address[4];
	unsigned long number;
}IP;
void main()
{
	int i;
	IP addr; 
	char *split;
	char *ipaddr="153.18.8.105";
	//clrscr();
	split=strtok(ipaddr,".");
	addr.address[3]=strtol(split,(char **)NULL,10);
	for(i=2;i>=0;i--)
	{
		split=strtok(NULL,".");
		addr.address[i]=strtol(split,(char **)NULL,10);
	}
	printf("IP Address Given is %d.%d.%d.%d\n",addr.address[0],addr.address[1],addr.address[2],addr.address[3]);
	printf("The Binary Adddress : %lu\n",addr.number);
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