#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "AVLIF.h"
#include "AVLImpl.h"

void main(){
	int opt=1;
	node n;
	struct avl *D,*t;
	char name[30];
	t=(struct avl *)malloc(sizeof(struct avl));
	D=NULL;
	printf("\n\n\t\tDICTIONARY MANAGEMENT SYSTEM\n\n");
	
	while(opt!=0){
		printf("\n\n\t\t\tEnter Options:\n");
		printf("\t1 to Insert\n\t2 to Display\n\t3 to Search\n\t0 to Exit\n\t");
		scanf("%d",&opt);	
		switch(opt){
			case 1:
				printf("\nEnter Word: ");
				scanf("%s",n.word);
				printf("\nEnter Meaning: ");
				scanf(" %[^\n]",n.mean);
				D=insert(D,n);
				break;
			case 2:
				//if(P->p.name==NULL)
					//printf("\nProfile Tree is Empty!");
				//else
					display(D,0);
				break;
			case 3:
				printf("\nEnter Name to Search for: ");
				scanf("%s",t->n.word);
				t=search(D,t->n.word);
				if(t==NULL)
					printf("\nPlayer Not Found!");
				else
					printf("\nWord Details:\n\tWord: %s\n\tMeaning: %s\n\n",t->n.word,t->n.mean);
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
(base) vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/AVL Tree$ gcc AVLAppl.c -o a -lm
(base) vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/AVL Tree$ ./a


		DICTIONARY MANAGEMENT SYSTEM



			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	0 to Exit
	1

Enter Word: Boat

Enter Meaning: A water transport vehicle


			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	0 to Exit
	1

Enter Word: Car

Enter Meaning: A road transport vehicle


			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	0 to Exit
	1

Enter Word: Zebra

Enter Meaning: An animal

			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	0 to Exit
	1

Enter Word: Duck

Enter Meaning: A water bird


			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	0 to Exit
	1

Enter Word: Water

Enter Meaning: An essential liquid

			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	0 to Exit
	1

Enter Word: Book

Enter Meaning: Collection of information


			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	0 to Exit
	1

Enter Word: Computer

Enter Meaning: A multipurpose device

			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	0 to Exit
	1

Enter Word: Pendant

Enter Meaning: An ornament

			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	0 to Exit
	1

Enter Word: Pillow

Enter Meaning: A sleeping accessory


			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	0 to Exit
	2

Duck
	Car
		Boat
			Book
		Computer
	Water
		Pendant
			Pillow
		Zebra

			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	0 to Exit
	3

Enter Name to Search for: Pillow

Word Details:
	Word: Pillow
	Meaning: A sleeping accessory



			Enter Options:
	1 to Insert
	2 to Display
	3 to Search
	0 to Exit
	0


			THANK YOU!


*/
