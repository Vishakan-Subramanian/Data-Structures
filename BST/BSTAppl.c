#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "BSTIF.h"
#include "BSTImpl.h"

void main(){
	int opt=1;
	playerInfo p;
	struct playerProfile *P,*t;
	char name[30];
	t=(struct playerProfile *)malloc(sizeof(struct playerProfile));
	P=NULL;
	printf("\n\n\t\tPLAYER PROFILE MANAGEMENT SYSTEM\n\n");
	
	while(opt!=0){
		printf("\n\n\t\t\tEnter Options:\n");
		printf("\t1 to Insert\n\t2 to Display\n\t3 to Search\n\t4 to Delete\n\t5 for Inorder\n\t6 for Preorder\n\t7 for Postorder\n\t0 to Exit\n\t");
		scanf("%d",&opt);	
		switch(opt){
			case 1:
				printf("\nEnter Name: ");
				scanf("%s",p.name);
				printf("\nEnter Role: ");
				scanf("%s",p.role);
				printf("\nEnter Average Run Rate: ");
				scanf("%f",&p.rr);
				P=insert(P,p);
				break;
			case 2:
				//if(P->p.name==NULL)
					//printf("\nProfile Tree is Empty!");
				//else
					display(P,0);
				break;
			case 3:
				printf("\nEnter Name to Search for: ");
				scanf("%s",t->p.name);
				t=search(P,t->p.name);
				if(t==NULL)
					printf("\nPlayer Not Found!");
				else
					printf("\nPlayer Details:\n\tName: %s\n\tRole: %s\n\tAvg. Run Rate: %.2f\n\n",t->p.name,t->p.role,t->p.rr);
				break;
			case 4:
				printf("\nEnter Name to Delete: ");
				scanf("%s",name);
				if(search(P,name)==NULL)
					printf("\nPlayer Not Found!");
				else
					P=removePlayer(P,name);
				break;
			case 5:
				inorder(P);
				break;
			case 6:
				preorder(P);
				break;
			case 7:
				postorder(P);
				break;
			case 0:
				printf("\n\n\t\t\tTHANK YOU!\n\n");
				break;
			default:
				printf("\nInvalid Option!");
		}

	}
}


/*
OUTPUT:

(base) vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/BST$ gcc Appl.c -o a -lm
(base) vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/BST$ ./a


		PLAYER PROFILE MANAGEMENT SYSTEM



			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	1

Enter Name: Dhoni

Enter Role: Wicketkeeper

Enter Average Run Rate: 6.75


			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	1

Enter Name: Kohli

Enter Role: Batsman

Enter Average Run Rate: 10


			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	1

Enter Name: Bumrah

Enter Role: Bowler

Enter Average Run Rate: 2.33


			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	1

Enter Name: Bhuvaneshwar

Enter Role: Bowler

Enter Average Run Rate: 2.13


			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	1

Enter Name: Hardik

Enter Role: Allrounder

Enter Average Run Rate: 7.89


			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	1

Enter Name: Rohit

Enter Role: Opener

Enter Average Run Rate: 18


			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	2

Dhoni
	Bumrah
		Bhuvaneshwar
	Kohli
		Hardik
		Rohit

			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	3

Enter Name to Search for: Rohit

Player Details:
	Name: Rohit
	Role: Opener
	Avg. Run Rate: 18.00



			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	5

Bhuvaneshwar
Bumrah
Dhoni
Hardik
Kohli
Rohit

			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	6

Dhoni
Bumrah
Bhuvaneshwar
Kohli
Hardik
Rohit

			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	7

Bhuvaneshwar
Bumrah
Hardik
Rohit
Kohli
Dhoni

			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	4

Enter Name to Delete: Dhoni 


			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	2

Hardik
	Bumrah
		Bhuvaneshwar
	Kohli
		Rohit

			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	4 to Delete
	5 for Inorder
	6 for Preorder
	7 for Postorder
	0 to Exit
	0


			THANK YOU!

*/
