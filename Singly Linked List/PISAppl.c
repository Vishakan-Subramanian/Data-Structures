/*APPLICATION FOR STUDENT INFORMATION SYSTEM*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "PISImpl.h"
//#include "PISIf.h"


person input(person p,struct node *list);

void main(){
	int i=1,x=0,j=1,epin;
	struct node *list,*senior;
	person p;
	ratio *r;
	r = (ratio *)malloc(sizeof(ratio));
	char reqcity[30];

	list=initNode();
	senior=initNode();
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\t\t\tPerson Information System\n");
	printf("\n--------------------------------------------------------------------------------\n");
	while(i!=0){
		printf("\n\t\tEnter a choice:\n\t\t1 to Insert\n\t\t2 to Display\n\t\t3 to Sort Based on Age\n\t\t4 to Display Male-Female Ratio\n\t\t5 to List Senior Citizens\n\t\t6 to Locate Persons based on City\n\t\t0 to Exit\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				j=1;
				while(j!=0){
					printf("\n\t\tEnter a choice:\n\t\t1 to Insert at Front\n\t\t2 to Insert at End\n\t\t3 to Insert After PIN\n\t\t0 to Go Back to Main Menu\n");
					scanf("%d",&j);
					switch(j){
						case 1:
							p=input(p,list);
							insertFront(list,p);
							break;
						case 2:
							p=input(p,list);
							insertEnd(list,p);
							break;
						case 3:
							printf("\nEnter the PIN after which you wish to insert record: ");
							scanf("%d",&epin);
							p=input(p,list);
							insertAfterPIN(list,p,epin);
							break;
						case 0:
							 break;
						default:
							printf("\nInvalid choice.");
					}
				}
				break;
			case 2:
				displayInfo(list);
				break;

			case 3:
				sortList(list);
				displayInfo(list);
				break;

			case 4:
				r=adultPerson(list,r);
				simpleRatio(r);
				break;

			case 5:
				senior=seniorPerson(list);
				if(senior->right!=NULL)
					displayInfo(senior);
				else
					printf("\nNo senior citizens found!\n");
				break;

			case 6:
				printf("\nEnter City to Search: ");
				scanf("%s",reqcity);
				locatePerson(list,reqcity);
				break;

			case 0:
				break;

			default:
				printf("\nInvalid Option.");
				break;
		}
	}

}

person input(person p,struct node *list){		//to accept input from the user and generate PIN number
	printf("\nEnter the Record Information: ");
	printf("\nName: ");
	scanf("%s",p.name);
	printf("\nAge: ");
	scanf("%d",&p.age);
	printf("\nSex (M/F) : ");
	scanf(" %c",&p.sex);
	printf("\nStreet Address: ");
	scanf("%s",p.street);
	printf("\nCity Address: ");
	scanf("%s",p.city);
	p.pin=randomPIN(list);
	return p;
}


/*
OUTPUT:

(base) vishakan@vishakan-legion:~/Desktop/Semester III/Lab/Data Structures/Person$ gcc PISAPPL.c -o p
(base) vishakan@vishakan-legion:~/Desktop/Semester III/Lab/Data Structures/Person$ ./p

--------------------------------------------------------------------------------

			Person Information System

--------------------------------------------------------------------------------

		Enter a choice:
		1 to Insert
		2 to Display
		3 to Sort Based on Age
		4 to Display Male-Female Ratio
		5 to List Senior Citizens
		6 to Locate Persons based on City
		0 to Exit
1

		Enter a choice:
		1 to Insert at Front
		2 to Insert at End
		3 to Insert After PIN
		0 to Go Back to Main Menu

1

Enter the Record Information: 
Name: Mike

Age: 25

Sex (M/F) : M

Street Address: Ronald  

City Address: Berkeley

		Enter a choice:
		1 to Insert at Front
		2 to Insert at End
		3 to Insert After PIN
		0 to Go Back to Main Menu

1

Enter the Record Information: 
Name: Aaron

Age: 35

Sex (M/F) : M

Street Address: Timber

City Address: NewYork

		Enter a choice:
		1 to Insert at Front
		2 to Insert at End
		3 to Insert After PIN
		0 to Go Back to Main Menu

2

Enter the Record Information: 
Name: Yasha

Age: 33

Sex (M/F) : F

Street Address: Iota

City Address: Fukushima

		Enter a choice:
		1 to Insert at Front
		2 to Insert at End
		3 to Insert After PIN
		0 to Go Back to Main Menu

1

Enter the Record Information: 
Name: Miranda

Age: 22

Sex (M/F) : F

Street Address: Tiller

City Address: California

		Enter a choice:
		1 to Insert at Front
		2 to Insert at End
		3 to Insert After PIN
		0 to Go Back to Main Menu

0

		Enter a choice:
		1 to Insert
		2 to Display
		3 to Sort Based on Age
		4 to Display Male-Female Ratio
		5 to List Senior Citizens
		6 to Locate Persons based on City
		0 to Exit
2

Records while moving forward are: 
Record 1
PIN: 777
Name: Miranda
Age: 22
Sex: F
Street Address: Tiller
City Address: California

Record 2
PIN: 938
Name: Aaron
Age: 35
Sex: M
Street Address: Timber
City Address: NewYork

Record 3
PIN: 65
Name: Mike
Age: 25
Sex: M
Street Address: Ronald
City Address: Berkeley

Record 4
PIN: 200
Name: Yasha
Age: 33
Sex: F
Street Address: Iota
City Address: Fukushima

Records while moving backward are: 
Record 4
PIN: 200
Name: Yasha
Age: 33
Sex: F
Street Address: Iota
City Address: Fukushima

Record 3
PIN: 65
Name: Mike
Age: 25
Sex: M
Street Address: Ronald
City Address: Berkeley

Record 2
PIN: 938
Name: Aaron
Age: 35
Sex: M
Street Address: Timber
City Address: NewYork

Record 1
PIN: 777
Name: Miranda
Age: 22
Sex: F
Street Address: Tiller
City Address: California

Enter a choice:
1 to Insert
2 to Display
3 to Sort Based on Age
4 to Display Male-Female Ratio
5 to List Senior Citizens
6 to Locate Persons based on City
0 to Exit
1

Enter a choice:
1 to Insert at Front
2 to Insert at End
3 to Insert After PIN
0 to Go Back to Main Menu
3

Enter the PIN after which you wish to insert record: 777

Enter the Record Information: 
Name: Rolando

Age: 37

Sex (M/F) : M

Street Address: Fig

City Address: Berkshire

Enter a choice:
1 to Insert at Front
2 to Insert at End
3 to Insert After PIN
0 to Go Back to Main Menu
0

		Enter a choice:
		1 to Insert
		2 to Display
		3 to Sort Based on Age
		4 to Display Male-Female Ratio
		5 to List Senior Citizens
		6 to Locate Persons based on City
		0 to Exit
2

Records while moving forward are: 
Record 1
PIN: 777
Name: Miranda
Age: 22
Sex: F
Street Address: Tiller
City Address: California

Record 2
PIN: 182
Name: Rolando
Age: 37
Sex: M
Street Address: Fig
City Address: Berkshire

Record 3
PIN: 938
Name: Aaron
Age: 35
Sex: M
Street Address: Timber
City Address: NewYork

Record 4
PIN: 65
Name: Mike
Age: 25
Sex: M
Street Address: Ronald
City Address: Berkeley

Record 5
PIN: 200
Name: Yasha
Age: 33
Sex: F
Street Address: Iota
City Address: Fukushima

Records while moving backward are: 
Record 5
PIN: 200
Name: Yasha
Age: 33
Sex: F
Street Address: Iota
City Address: Fukushima

Record 4
PIN: 65
Name: Mike
Age: 25
Sex: M
Street Address: Ronald
City Address: Berkeley

Record 3
PIN: 938
Name: Aaron
Age: 35
Sex: M
Street Address: Timber
City Address: NewYork

Record 2
PIN: 182
Name: Rolando
Age: 37
Sex: M
Street Address: Fig
City Address: Berkshire

Record 1
PIN: 777
Name: Miranda
Age: 22
Sex: F
Street Address: Tiller
City Address: California

		Enter a choice:
		1 to Insert
		2 to Display
		3 to Sort Based on Age
		4 to Display Male-Female Ratio
		5 to List Senior Citizens
		6 to Locate Persons based on City
		0 to Exit
3

Records while moving forward are: 
Record 1
PIN: 777
Name: Miranda
Age: 22
Sex: F
Street Address: Tiller
City Address: California

Record 2
PIN: 65
Name: Mike
Age: 25
Sex: M
Street Address: Ronald
City Address: Berkeley

Record 3
PIN: 200
Name: Yasha
Age: 33
Sex: F
Street Address: Iota
City Address: Fukushima

Record 4
PIN: 938
Name: Aaron
Age: 35
Sex: M
Street Address: Timber
City Address: NewYork

Record 5
PIN: 182
Name: Rolando
Age: 37
Sex: M
Street Address: Fig
City Address: Berkshire

Records while moving backward are: 
Record 5
PIN: 182
Name: Rolando
Age: 37
Sex: M
Street Address: Fig
City Address: Berkshire

Record 4
PIN: 938
Name: Aaron
Age: 35
Sex: M
Street Address: Timber
City Address: NewYork

Record 3
PIN: 200
Name: Yasha
Age: 33
Sex: F
Street Address: Iota
City Address: Fukushima

Record 2
PIN: 65
Name: Mike
Age: 25
Sex: M
Street Address: Ronald
City Address: Berkeley

Record 1
PIN: 777
Name: Miranda
Age: 22
Sex: F
Street Address: Tiller
City Address: California

		Enter a choice:
		1 to Insert
		2 to Display
		3 to Sort Based on Age
		4 to Display Male-Female Ratio
		5 to List Senior Citizens
		6 to Locate Persons based on City
		0 to Exit
4

The number of Males: 3 and the number of Females: 2.
The Ratio is: 3 : 2

		Enter a choice:
		1 to Insert
		2 to Display
		3 to Sort Based on Age
		4 to Display Male-Female Ratio
		5 to List Senior Citizens
		6 to Locate Persons based on City
		0 to Exit
5

No senior citizens found!

		Enter a choice:
		1 to Insert
		2 to Display
		3 to Sort Based on Age
		4 to Display Male-Female Ratio
		5 to List Senior Citizens
		6 to Locate Persons based on City
		0 to Exit
6

Enter City to Search: California

PIN: 777
Name: Miranda
Age: 22
Sex: F
Street Address: Tiller
City Address: California

		Enter a choice:
		1 to Insert
		2 to Display
		3 to Sort Based on Age
		4 to Display Male-Female Ratio
		5 to List Senior Citizens
		6 to Locate Persons based on City
		0 to Exit
0

*/