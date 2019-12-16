/*MAIN FUNCTION FOR POLYNOMIAL LIST ADT PROGRAM*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "PolyADTIF.h"
#include "PolyADTImpl.h"



void main(){
	printf("\n--------------------------------------------------------------------");
	printf("\n\t\tPolynomial Manipulation using List ADT");
	printf("\n--------------------------------------------------------------------");
	MainMenu();
}

void Insertion(int iopt,struct poly *p1){
	int e,c,ee,ec,flag;
				while(iopt!=0){
					printf("\n\n\t\t\tEnter Insert Type:");
					printf("\n\t\t1 To Insert At Front\n\t\t2 To Insert At End\n\t\t3 To Insert After An Existing Term\n\t\t0 To Finish Insertion and Go To Main Menu\n\n");
					scanf("%d",&iopt);
					switch(iopt){
						case 1:
							printf("\nEnter the co-efficient of term: ");
							scanf("%d",&c);
							printf("\nEnter the exponent of term: ");
							scanf("%d",&e);
							insertFront(p1,c,e);
							printf("\nInsertion Succesful.");
							break;
						case 2:
							printf("\nEnter the co-efficient of term: ");
							scanf("%d",&c);
							printf("\nEnter the exponent of term: ");
							scanf("%d",&e);
							insertEnd(p1,c,e);
							printf("\nInsertion Succesful.");
							break;
						case 3:
							printf("\nEnter the co-efficient of new term: ");
							scanf("%d",&c);
							printf("\nEnter the exponent of new term: ");
							scanf("%d",&e);
							printf("\nEnter the co-efficient of existing term: ");
							scanf("%d",&ec);
							printf("\nEnter the exponent of existing term: ");
							scanf("%d",&ee);
							flag=insertAfterTerm(p1,c,e,ec,ee);
							if(flag)
								printf("\nInsertion Succesful.");
							break;
						case 0:
							break;
						default:
							printf("\nInvalid Input.Try Again.");

					}
				}
}

void MainMenu(){
	struct poly *p1, *p2, *add, *mul;
	int opt=1,iopt=1;
	int x;
	while(opt!=0){
		printf("\n\n\t\t\tEnter A Choice\n\n\t1 Initialise a New Polynomial Expression\n\t2 Insert Into Current Expression\n\t3 To Display Current Expression\n\t4 To Find Degree of Current Expression\n\t5 To Evaluate Current Polynomial Expression\n\t6 To Simplify Polynomial Expression and Display\n\t7 To Add Another Polynomial with Existing One\n\t8 To Multiply Another Polynomial with Existing One\n\t0 To Exit The Program\n\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				p1=initPoly();
				printf("\nPolynomial Expression succesfully initialised.");
				break;

			case 2:
				Insertion(iopt,p1);
				break;

			case 3:
				showPoly(p1);
				break;

			case 4:
				printf("\n\nPolynomial is: ");
				showPoly(p1);
				polyDegree(p1);
				break;

			case 5:
				printf("\nEnter a value for x to evaluate: ");
				scanf("%d",&x);
				printf("\n\nPolynomial is: ");
				showPoly(p1);
				evaluatePoly(p1,x);
				break;

			case 6:
				simplifyPoly(p1);
				printf("\n\nPolynomial is: ");
				showPoly(p1);
				break;
			case 7:
				iopt=1;
				p2=initPoly();
				add=initPoly();
				printf("\nEnter values to second polynomial to continue.");
				Insertion(iopt,p2);
				add=addPoly(p1,p2);
				printf("\n\nPolynomial 1 is: ");
				showPoly(p1);
				printf("\n\nPolynomial 2 is: ");
				showPoly(p2);
				printf("\n\nThe result is: ");
				showPoly(add);
				break;
			case 8:
				iopt=1;
				p2=initPoly();
				mul=initPoly();
				printf("\nEnter values to second polynomial to continue.");
				Insertion(iopt,p2);
				mul=multiplyPoly(p1,p2);
				printf("\n\nPolynomial 1 is: ");
				showPoly(p1);
				printf("\n\nPolynomial 2 is: ");
				showPoly(p2);
				printf("\n\nThe result is: ");
				showPoly(mul);
				break;

			case 0:
				break;

			default:
				printf("\nInvalid Input.Try Again.");

		}
	}
}

/*
OUTPUT:
vishakan@vishakan-legion:~/Desktop/Data Structures/Polynomial$ gcc PolyADTMain.c -o pam -lm
vishakan@vishakan-legion:~/Desktop/Data Structures/Polynomial$ ./pam

--------------------------------------------------------------------
		Polynomial Manipulation using List ADT
--------------------------------------------------------------------

			Enter A Choice

	1 Initialise a New Polynomial Expression
	2 Insert Into Current Expression
	3 To Display Current Expression
	4 To Find Degree of Current Expression
	5 To Evaluate Current Polynomial Expression
	6 To Simplify Polynomial Expression and Display
	7 To Add Another Polynomial with Existing One
	8 To Multiply Another Polynomial with Existing One
	0 To Exit The Program

1

Polynomial Expression succesfully initialised.

			Enter A Choice

	1 Initialise a New Polynomial Expression
	2 Insert Into Current Expression
	3 To Display Current Expression
	4 To Find Degree of Current Expression
	5 To Evaluate Current Polynomial Expression
	6 To Simplify Polynomial Expression and Display
	7 To Add Another Polynomial with Existing One
	8 To Multiply Another Polynomial with Existing One
	0 To Exit The Program

2


			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

1

Enter the co-efficient of term: 3

Enter the exponent of term: 3

Insertion Succesful.

			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

2

Enter the co-efficient of term: 2

Enter the exponent of term: 2

Insertion Succesful.

			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

3

Enter the co-efficient of new term: 1

Enter the exponent of new term: 1

Enter the co-efficient of existing term: 2

Enter the exponent of existing term: 2

Insertion Succesful.

			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

0


			Enter A Choice

	1 Initialise a New Polynomial Expression
	2 Insert Into Current Expression
	3 To Display Current Expression
	4 To Find Degree of Current Expression
	5 To Evaluate Current Polynomial Expression
	6 To Simplify Polynomial Expression and Display
	7 To Add Another Polynomial with Existing One
	8 To Multiply Another Polynomial with Existing One
	0 To Exit The Program

2


			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

2

Enter the co-efficient of term: 3

Enter the exponent of term: 2

Insertion Succesful.

			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

0


			Enter A Choice

	1 Initialise a New Polynomial Expression
	2 Insert Into Current Expression
	3 To Display Current Expression
	4 To Find Degree of Current Expression
	5 To Evaluate Current Polynomial Expression
	6 To Simplify Polynomial Expression and Display
	7 To Add Another Polynomial with Existing One
	8 To Multiply Another Polynomial with Existing One
	0 To Exit The Program

3
3x^3 + 2x^2 + 1x^1 + 3x^2

			Enter A Choice

	1 Initialise a New Polynomial Expression
	2 Insert Into Current Expression
	3 To Display Current Expression
	4 To Find Degree of Current Expression
	5 To Evaluate Current Polynomial Expression
	6 To Simplify Polynomial Expression and Display
	7 To Add Another Polynomial with Existing One
	8 To Multiply Another Polynomial with Existing One
	0 To Exit The Program

4


Polynomial is: 3x^3 + 2x^2 + 1x^1 + 3x^2
The degree of the polynomial is : 3

			Enter A Choice

	1 Initialise a New Polynomial Expression
	2 Insert Into Current Expression
	3 To Display Current Expression
	4 To Find Degree of Current Expression
	5 To Evaluate Current Polynomial Expression
	6 To Simplify Polynomial Expression and Display
	7 To Add Another Polynomial with Existing One
	8 To Multiply Another Polynomial with Existing One
	0 To Exit The Program

5

Enter a value for x to evaluate: 1


Polynomial is: 3x^3 + 2x^2 + 1x^1 + 3x^2
The expression's value when x= 1 is 9

			Enter A Choice

	1 Initialise a New Polynomial Expression
	2 Insert Into Current Expression
	3 To Display Current Expression
	4 To Find Degree of Current Expression
	5 To Evaluate Current Polynomial Expression
	6 To Simplify Polynomial Expression and Display
	7 To Add Another Polynomial with Existing One
	8 To Multiply Another Polynomial with Existing One
	0 To Exit The Program

6


Polynomial is:
3x^3 + 5x^2 + 1x^1

			Enter A Choice

	1 Initialise a New Polynomial Expression
	2 Insert Into Current Expression
	3 To Display Current Expression
	4 To Find Degree of Current Expression
	5 To Evaluate Current Polynomial Expression
	6 To Simplify Polynomial Expression and Display
	7 To Add Another Polynomial with Existing One
	8 To Multiply Another Polynomial with Existing One
	0 To Exit The Program

7

Enter values to second polynomial to continue.

			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

1

Enter the co-efficient of term: 2

Enter the exponent of term: 2

Insertion Succesful.

			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

1

Enter the co-efficient of term: 3

Enter the exponent of term: 3

Insertion Succesful.

			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

0


Polynomial 1 is: 3x^3 + 5x^2 + 1x^1

Polynomial 2 is: 3x^3 + 2x^2

The result is: 1x^1 + 7x^2 + 6x^3

			Enter A Choice

	1 Initialise a New Polynomial Expression
	2 Insert Into Current Expression
	3 To Display Current Expression
	4 To Find Degree of Current Expression
	5 To Evaluate Current Polynomial Expression
	6 To Simplify Polynomial Expression and Display
	7 To Add Another Polynomial with Existing One
	8 To Multiply Another Polynomial with Existing One
	0 To Exit The Program

8

Enter values to second polynomial to continue.

			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

1

Enter the co-efficient of term: 4

Enter the exponent of term: 4

Insertion Succesful.

			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

1

Enter the co-efficient of term: 3

Enter the exponent of term: 3

Insertion Succesful.

			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

1

Enter the co-efficient of term: 5

Enter the exponent of term: 5

Insertion Succesful.

			Enter Insert Type:
		1 To Insert At Front
		2 To Insert At End
		3 To Insert After An Existing Term
		0 To Finish Insertion and Go To Main Menu

0


Polynomial 1 is: 3x^3 + 5x^2 + 1x^1

Polynomial 2 is: 5x^5 + 3x^3 + 4x^4

The result is: 19x^5 + 3x^4 + 34x^6 + 37x^7 + 15x^8

			Enter A Choice

	1 Initialise a New Polynomial Expression
	2 Insert Into Current Expression
	3 To Display Current Expression
	4 To Find Degree of Current Expression
	5 To Evaluate Current Polynomial Expression
	6 To Simplify Polynomial Expression and Display
	7 To Add Another Polynomial with Existing One
	8 To Multiply Another Polynomial with Existing One
	0 To Exit The Program

0
*/