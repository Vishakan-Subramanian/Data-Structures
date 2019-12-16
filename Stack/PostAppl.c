/*APPLICATION FOR STACK BASED POSTFIX CONVERSION AND EVALUAITON */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include "Stack.h"
#include "PostIF.h"
#include "PostImpl.h"


void main(){
	Stack s;
	initStack(&s,100);

	char *infix,*postfix,ask;
	int value;

	infix=(char *)malloc(sizeof(char)*100);
	postfix=(char *)malloc(sizeof(char)*100);

	printf("\n\t\t\tINFIX TO POSTFIX CONVERSION\n");
	while(1){
		printf("\nEnter an INFIX expression: ");
		scanf("%s",infix);
		postfix=infixtoPostfix(infix,&s);
		printf("\nThe POSTFIX expression is: %s\n",postfix);
		value=evaluateExp(postfix,&s);
		printf("\nThe value of the POSTFIX expression is: %d\n",value);
		printf("\nDo you wish to continue? (Y/N) : ");
		scanf(" %c",&ask);
		if(ask=='Y'||ask=='y')
			continue;
		else if(ask=='N'||ask=='n')
			break;
		else{
			printf("Invalid Input!");
			break;
		}
	}
}


/*
OUTPUT:

(base) vishakan@vishakan-legion:~/Desktop/Semester III/Lab/Data Structures/Postfix-Stack$ gcc PostAppl.c -o p -lm
(base) vishakan@vishakan-legion:~/Desktop/Semester III/Lab/Data Structures/Postfix-Stack$ ./p

			INFIX TO POSTFIX CONVERSION

			INFIX TO POSTFIX CONVERSION

Enter an INFIX expression: 2*3-5+9/2^4-1+2

The POSTFIX expression is: 23*5-924^/+1-2+

The value of the POSTFIX expression is: 2

Do you wish to continue? (Y/N) : N

*/
