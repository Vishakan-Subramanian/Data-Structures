#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "TDIf.h"
#include "TDImpl.h"

void main(){
	int opt=1;
	HashTable *H=(HashTable *)malloc(sizeof(HashTable));
	int size;
	initHT(H);
	record r;
	char name[40];
	databaseLoader(H);


	while(opt!=0){
		printf("\n-----------------------------------------------------------------------------");
		printf("\n\n\t\tTELEPHONE DIRECTORY USING HASH TABLE\n");
		printf("\n-----------------------------------------------------------------------------\n");
		printf("\nEnter A Choice:\n\t1 to Insert A Record\n\t2 to Display Hash Table\n\t3 to Search a Record based on Name\n\t4 to Display Database\n\t5 to Delete A Record\n\t6 to Update A Record\n\t7 to Display Sorted Database\n\t0 to Quit\n\tYour Choice -> ");
		scanf("%d",&opt);
		printf("\n-----------------------------------------------------------------------------\n");
		switch(opt){
			case 1:
					r=getRecord();
					insertRecord(H,r,1);
					break;
			case 2:
					displayHT(H);
					break;
			case 3:
					printf("\nEnter the Name of Record to be Searched:");
					scanf(" %[^\n]",name);
					searchRecord(H,name);
					break;
			case 4:
					displayDB();
					break;
			case 5:
					printf("\nEnter the Name of Record to be Deleted:");
					scanf(" %[^\n]",name);
					deleteRecord(H,name);
					break;
			case 6:
					printf("\nEnter the Name of Record to be Updated:");
					scanf(" %[^\n]",name);
					updateRecord(H,name);
					break;
			case 7:
					sortedDisplay();
					break;

			case 0:
				printf("\n\t\t\tThank You!\n");
				printf("\n-----------------------------------------------------------------------------\n");
				break;
			default:
				printf("\n\t\tInvalid Option!\n");
				printf("\n-----------------------------------------------------------------------------\n");
				break;
		}
	}
}

/*
OUTPUT:

(base) vishakan@legion:~/Desktop/Semester III/Projects/Telephone Directory$ gcc TDAppl.c -o t
(base) vishakan@legion:~/Desktop/Semester III/Projects/Telephone Directory$ ./t

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 6

-----------------------------------------------------------------------------

Enter the Name of Record to be Updated:Yawar

There were no records with the Name: Yawar.

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 4

-----------------------------------------------------------------------------

Name                Phone     	Address                       	PIN Code  
-----------------------------------------------------------------------------

Sample              9000010000	New St.                       	500001
Sumail              5000400001	Quincy Street                 	400192
Avarice             2223377787	Slovenian Blvd.               	11120
Vishwaksenan        9877012234	SSN College                   	600004
Vikram              9000023330	Vadapalani                    	600091
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 5

-----------------------------------------------------------------------------

Enter the Name of Record to be Deleted:Yawar

There were no records with the Name: Yawar.

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 1

-----------------------------------------------------------------------------

Enter Person's Name: Yawar Hassan

Enter Person's Phone Number: 2001030012

Enter Person's Address: Sunset Blvd.

Enter Person's PIN Code: 34456

Record Written to Database Successfully.

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 1

-----------------------------------------------------------------------------

Enter Person's Name: Theeban

Enter Person's Phone Number: 1437143737

Enter Person's Address: Montreal Lane

Enter Person's PIN Code: 14371

Record Written to Database Successfully.

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 2

-----------------------------------------------------------------------------

Hash Table: 

Sumail

Sample

Vikram

Theeban

Avarice

Yawar Hassan

Vishwaksenan
-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 4

-----------------------------------------------------------------------------

Name                Phone     	Address                       	PIN Code  
-----------------------------------------------------------------------------

Sample              9000010000	New St.                       	500001
Sumail              5000400001	Quincy Street                 	400192
Avarice             2223377787	Slovenian Blvd.               	11120
Vishwaksenan        9877012234	SSN College                   	600004
Vikram              9000023330	Vadapalani                    	600091
Yawar Hassan        2001030012	Sunset Blvd.                  	34456
Theeban             1437143737	Montreal Lane                 	14371
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 7

-----------------------------------------------------------------------------

Name                Phone     	Address                       	PIN Code  
-----------------------------------------------------------------------------

Avarice             2223377787	Slovenian Blvd.               	11120
Sample              9000010000	New St.                       	500001
Sumail              5000400001	Quincy Street                 	400192
Theeban             1437143737	Montreal Lane                 	14371
Vikram              9000023330	Vadapalani                    	600091
Vishwaksenan        9877012234	SSN College                   	600004
Yawar Hassan        2001030012	Sunset Blvd.                  	34456
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 3

-----------------------------------------------------------------------------

Enter the Name of Record to be Searched:Theeban

Name: Theeban
Phone Number: 1437143737
Address: Montreal Lane
PIN Code: 14371

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 1

-----------------------------------------------------------------------------

Enter Person's Name: Error

Enter Person's Phone Number: 1100000000

Enter Person's Address: N/A

Enter Person's PIN Code: 00000

Record Written to Database Successfully.

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 4

-----------------------------------------------------------------------------

Name                Phone     	Address                       	PIN Code  
-----------------------------------------------------------------------------

Sample              9000010000	New St.                       	500001
Sumail              5000400001	Quincy Street                 	400192
Avarice             2223377787	Slovenian Blvd.               	11120
Vishwaksenan        9877012234	SSN College                   	600004
Vikram              9000023330	Vadapalani                    	600091
Yawar Hassan        2001030012	Sunset Blvd.                  	34456
Theeban             1437143737	Montreal Lane                 	14371
Error               1100000000	N/A                           	0
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 6

-----------------------------------------------------------------------------

Enter the Name of Record to be Updated:Error

Record Deletion was Successful.

Enter New Record Details:

Enter Person's Name: Manta

Enter Person's Phone Number: 900010002

Enter Person's Address: Weebly St.

Enter Person's PIN Code: 49999 

Record Written to Database Successfully.

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 2

-----------------------------------------------------------------------------

Hash Table: 

Manta

Sumail

Sample

Vikram

Theeban

Avarice

Yawar Hassan

Vishwaksenan
-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 5

-----------------------------------------------------------------------------

Enter the Name of Record to be Deleted:Manta

Record Deletion was Successful.

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 2

-----------------------------------------------------------------------------

Hash Table: 

Sumail

Sample

Vikram

Theeban

Avarice

Yawar Hassan

Vishwaksenan
-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 4

-----------------------------------------------------------------------------

Name                Phone     	Address                       	PIN Code  
-----------------------------------------------------------------------------

Sample              9000010000	New St.                       	500001
Sumail              5000400001	Quincy Street                 	400192
Avarice             2223377787	Slovenian Blvd.               	11120
Vishwaksenan        9877012234	SSN College                   	600004
Vikram              9000023330	Vadapalani                    	600091
Yawar Hassan        2001030012	Sunset Blvd.                  	34456
Theeban             1437143737	Montreal Lane                 	14371
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------

		TELEPHONE DIRECTORY USING HASH TABLE

-----------------------------------------------------------------------------

Enter A Choice:
	1 to Insert A Record
	2 to Display Hash Table
	3 to Search an Element based on Name
	4 to Display Database
	5 to Delete A Record
	6 to Update A Record
	7 to Display Sorted Database
	0 to Quit
	Your Choice -> 0

-----------------------------------------------------------------------------

		Thank You!

-----------------------------------------------------------------------------

*/
