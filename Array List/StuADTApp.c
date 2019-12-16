/* MAIN FUNCTION IMPLEMENTATION FOR STUDENT STACK APPLICATION */

#include<stdio.h>
#include<string.h>
#include "StuADTImpl.h"
#include "StuADTFunc.h"

void main() {
	ListADT l;
	initADT(&l);
	int ch;
	
	do{
		printf("\n---------------------------------------------------------------------\n");
		printf("\n\t\t\t\tMain Menu\n\n\t1-Add a Record in Front\n\t2-Add a Record in End\n\t3-Add a Record after a Particular Record\n\t4-Display All Records\n\t5-Display First Class Students\n\t6-Display Passed Students\n\t7-Search by Name\n\t8-Search by Register Number\n\t9-Delete a Record\n\t0-Quit the Application\n\nEnter your choice below : ");
		scanf("%d",&ch);
		mainMenu(&l,ch);	
				
	}while(ch);
	printf("\n\t\t\tThank You!\n");
	
}



/*
OUTPUT:

vishakan@vishakan-legion:~/Desktop/Data Structures/Student$ gcc StuADTApp.c -o a
vishakan@vishakan-legion:~/Desktop/Data Structures/Student$ ./a

---------------------------------------------------------------------

				Main Menu

	1-Add a Record in Front
	2-Add a Record in End
	3-Add a Record after a Particular Record
	4-Display All Records
	5-Display First Class Students
	6-Display Passed Students
	7-Search by Name
	8-Search by Register Number
	9-Delete a Record
	0-Quit the Application

Enter your choice below : 1

Enter Student Details :-
	Register Number: 1
	Name: A
	Marks:
	Subject 1: 100
	Subject 2: 100
	Subject 3: 100

---------------------------------------------------------------------

				Main Menu

	1-Add a Record in Front
	2-Add a Record in End
	3-Add a Record after a Particular Record
	4-Display All Records
	5-Display First Class Students
	6-Display Passed Students
	7-Search by Name
	8-Search by Register Number
	9-Delete a Record
	0-Quit the Application

Enter your choice below : 2

Enter Student Details :-
	Register Number: 2
	Name: B   
	Marks:
	Subject 1: 90
	Subject 2: 90
	Subject 3: 90

---------------------------------------------------------------------

				Main Menu

	1-Add a Record in Front
	2-Add a Record in End
	3-Add a Record after a Particular Record
	4-Display All Records
	5-Display First Class Students
	6-Display Passed Students
	7-Search by Name
	8-Search by Register Number
	9-Delete a Record
	0-Quit the Application

Enter your choice below : 3

Enter Student Details :-
	Register Number: 12
	Name: C
	Marks:
	Subject 1: 40
	Subject 2: 40
	Subject 3: 40

Enter Reg.Num. of Student after which record is to be inserted: 1

---------------------------------------------------------------------

				Main Menu

	1-Add a Record in Front
	2-Add a Record in End
	3-Add a Record after a Particular Record
	4-Display All Records
	5-Display First Class Students
	6-Display Passed Students
	7-Search by Name
	8-Search by Register Number
	9-Delete a Record
	0-Quit the Application

Enter your choice below : 4

---------------------------------------------------------------------
RegNo Name                      Sub1    Sub2    Sub3    Total   Grade
---------------------------------------------------------------------
    1 A                            100    100    100    300 O
   12 C                             40     40     40    120 D
    2 B                             90     90     90    270 O
---------------------------------------------------------------------

---------------------------------------------------------------------

				Main Menu

	1-Add a Record in Front
	2-Add a Record in End
	3-Add a Record after a Particular Record
	4-Display All Records
	5-Display First Class Students
	6-Display Passed Students
	7-Search by Name
	8-Search by Register Number
	9-Delete a Record
	0-Quit the Application

Enter your choice below : 5

---------------------------------------------------------------------
RegNo Name                      Sub1    Sub2    Sub3    Total   Grade
---------------------------------------------------------------------
    1 A                            100    100    100    300 O
    2 B                             90     90     90    270 O
---------------------------------------------------------------------

The no.of students who got first class: 2

---------------------------------------------------------------------

				Main Menu

	1-Add a Record in Front
	2-Add a Record in End
	3-Add a Record after a Particular Record
	4-Display All Records
	5-Display First Class Students
	6-Display Passed Students
	7-Search by Name
	8-Search by Register Number
	9-Delete a Record
	0-Quit the Application

Enter your choice below : 6

---------------------------------------------------------------------
RegNo Name                      Sub1    Sub2    Sub3    Total   Grade
---------------------------------------------------------------------
    1 A                            100    100    100    300 O
   12 C                             40     40     40    120 D
    2 B                             90     90     90    270 O
---------------------------------------------------------------------

---------------------------------------------------------------------

				Main Menu

	1-Add a Record in Front
	2-Add a Record in End
	3-Add a Record after a Particular Record
	4-Display All Records
	5-Display First Class Students
	6-Display Passed Students
	7-Search by Name
	8-Search by Register Number
	9-Delete a Record
	0-Quit the Application

Enter your choice below : 7
Enter Name to be searched : A

---------------------------------------------------------------------
RegNo Name                      Sub1    Sub2    Sub3    Total   Grade
---------------------------------------------------------------------
    1 A                            100    100    100    300 O
---------------------------------------------------------------------

---------------------------------------------------------------------

				Main Menu

	1-Add a Record in Front
	2-Add a Record in End
	3-Add a Record after a Particular Record
	4-Display All Records
	5-Display First Class Students
	6-Display Passed Students
	7-Search by Name
	8-Search by Register Number
	9-Delete a Record
	0-Quit the Application

Enter your choice below : 8
Enter Register Number to be searched : 2

---------------------------------------------------------------------
RegNo Name                      Sub1    Sub2    Sub3    Total   Grade
---------------------------------------------------------------------
    2 B                             90     90     90    270 O
---------------------------------------------------------------------

---------------------------------------------------------------------

				Main Menu

	1-Add a Record in Front
	2-Add a Record in End
	3-Add a Record after a Particular Record
	4-Display All Records
	5-Display First Class Students
	6-Display Passed Students
	7-Search by Name
	8-Search by Register Number
	9-Delete a Record
	0-Quit the Application

Enter your choice below : 9
Enter Student's Register Number : 12

---------------------------------------------------------------------
RegNo Name                      Sub1    Sub2    Sub3    Total   Grade
---------------------------------------------------------------------
   12 C                             40     40     40    120 D
---------------------------------------------------------------------

---------------------------------------------------------------------

				Main Menu

	1-Add a Record in Front
	2-Add a Record in End
	3-Add a Record after a Particular Record
	4-Display All Records
	5-Display First Class Students
	6-Display Passed Students
	7-Search by Name
	8-Search by Register Number
	9-Delete a Record
	0-Quit the Application

Enter your choice below : 0

			Thank You!

*/
