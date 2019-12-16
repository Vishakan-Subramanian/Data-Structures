#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Stack.h"
#include "DFSIF.h"
#include "DFSImpl.h"


void main(){

	int cap,choice=4;
	char start[100],dest[100];
	cityADT *c;
	c=(cityADT*)malloc(sizeof(cityADT));

	printf("\n\t\tCity Maps Using Depth First Search");

	while(choice!=0){
		printf("\n\n\t\tMAIN MENU\n\t1 - Add A Connection\n\t2 - Display All Existing Connections\n\t3 - Depth First Search\n\t4 - Initialise Map\n\t5 - Are 2 Cities Connected?\n\t0 - Exit\n\n\tEnter your choice -> ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1 :
				printf("\nEnter the City Names: ");
				printf("\n\tStarting Point: ");
				scanf("%s",start);
				printf("\tDestination Point: ");
				scanf("%s",dest);
				create(c,start,dest);
				break;

			case 2 :
				display(c);
				break;

			case 3 :
				printf("\n\nDepth First Search Traversal:\n");
				clearVisits(c);
				while(unvisited(c)+1)
					DFSTraverse(c,unvisited(c));
				PathPrinter(c,0,min(c->cur_state,c->city_count-1));
				break;

			case 4:
				printf("\nEnter the Total No. Of Cities in the Map : ");
				scanf("%d",&cap);
				c = initADT(c,cap);
				break;

			case 5:	
					printf("\nEnter the Starting Point: ");
					scanf("%s",start);
					printf("\nEnter the Ending Point: ");
					scanf("%s",dest);
					clearVisits(c);
					int val=DFSPath(c,start,dest);
					if(val==1){
						int begin=findCity(c,start);
						int end=findCity(c,dest);
						printf("\n%s is connected with %s.",start,dest);
						printf("\nPath:\n");
						PathPrinter(c,begin,end);
					}
					else
						printf("\n%s is not connected with %s.",start,dest);

					break;

			case 0:
				printf("\n\t\tThank You!");
				break;

			default:
				printf("\n\tInvalid Option!");
				break;
		}
	}
}



/*
OUTPUT:
vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/Graphs/DFS$ gcc DFSAppl.c -o d
vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/Graphs/DFS$ ./d

		City Maps Using Depth First Search

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Depth First Search
	4 - Initialise Map
	5 - Are 2 Cities Connected?
	0 - Exit

	Enter your choice -> 4

Enter the Total No. Of Cities in the Map : 5


		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Depth First Search
	4 - Initialise Map
	5 - Are 2 Cities Connected?
	0 - Exit

	Enter your choice -> 1

Enter the City Names: 
	Starting Point: A
	Destination Point: B

A is now connected with B.

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Depth First Search
	4 - Initialise Map
	5 - Are 2 Cities Connected?
	0 - Exit

	Enter your choice -> 1

Enter the City Names: 
	Starting Point: B
	Destination Point: C

B is now connected with C.

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Depth First Search
	4 - Initialise Map
	5 - Are 2 Cities Connected?
	0 - Exit

	Enter your choice -> 1

Enter the City Names: 
	Starting Point: C
	Destination Point: D

C is now connected with D.

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Depth First Search
	4 - Initialise Map
	5 - Are 2 Cities Connected?
	0 - Exit

	Enter your choice -> 1

Enter the City Names: 
	Starting Point: D
	Destination Point: E

D is now connected with E.

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Depth First Search
	4 - Initialise Map
	5 - Are 2 Cities Connected?
	0 - Exit

	Enter your choice -> 1

Enter the City Names: 
	Starting Point: A
	Destination Point: C

A is now connected with C.

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Depth First Search
	4 - Initialise Map
	5 - Are 2 Cities Connected?
	0 - Exit

	Enter your choice -> 1

Enter the City Names: 
	Starting Point: C
	Destination Point: B

C is now connected with B.

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Depth First Search
	4 - Initialise Map
	5 - Are 2 Cities Connected?
	0 - Exit

	Enter your choice -> 2

A is connected to:
  B  C
B is connected to:
  C
C is connected to:
  B  D
D is connected to:
  E
E is connected to:


		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Depth First Search
	4 - Initialise Map
	5 - Are 2 Cities Connected?
	0 - Exit

	Enter your choice -> 3


Depth First Search Traversal:
	A	B	C	D	E

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Depth First Search
	4 - Initialise Map
	5 - Are 2 Cities Connected?
	0 - Exit

	Enter your choice -> 5

Enter the Starting Point: A

Enter the Ending Point: E

A is connected with E.
Path:
	A	B	C	D	E

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Depth First Search
	4 - Initialise Map
	5 - Are 2 Cities Connected?
	0 - Exit

	Enter your choice -> 5

Enter the Starting Point: E

Enter the Ending Point: A

E is not connected with A.

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Depth First Search
	4 - Initialise Map
	5 - Are 2 Cities Connected?
	0 - Exit

	Enter your choice -> 0

		Thank You!(base) 
*/
