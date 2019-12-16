#include<stdio.h>
#include<stdlib.h>
#include "HashIF.h"
#include "HashImpl.h"

void main(){
	int opt=1;
	HashTable *H=(HashTable *)malloc(sizeof(HashTable));
	record r,res;


	while(opt!=0){
		printf("\n\n\tTELEPHONE DIRECTORY USING HASH TABLE\n");
		printf("\nEnter A Choice:\n\t1 to Insert Records\n\t2 to Display Recprds\n\t3 to Search an Element\n\t0 to Quit\n\tYour Choice -> ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter the element you wish to enter: ");
				scanf("%d",&x);
				insertElement(H,x);
				break;
			case 2:
					displayHT(H);
					break;
			case 3:
					printf("\nEnter the element you wish to search for: ");
					scanf("%d",&x);
					searchElement(H,x);
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
(base) vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/Hashing$ gcc HashAppl.c -o h
(base) vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/Hashing$ ./h

Enter Size of the Hash Table:  5


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 5


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 1


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 2


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 3


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 4


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 11


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 23


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 44


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 52


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 55


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 229


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 23


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 234


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 71


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 1

Enter the element you wish to enter: 294


	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 2

Hash Table: 

5--->55

1--->11--->71

2--->52

3--->23--->23

4--->44--->229--->234--->294

	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 3

Enter the element you wish to search for: 229

Element 229 was found at Index 2 in Bucket 4.

	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 3

Enter the element you wish to search for: 1000

Element 1000 was not found.

	HASH TABLE APPLICATION USING SEPARATE CHAINING

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search an Element
	0 to Quit
	Your Choice -> 0

		Thank You!
*/