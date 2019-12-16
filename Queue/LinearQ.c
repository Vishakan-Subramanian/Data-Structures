#include<stdio.h>
#include<stdlib.h>
#include "LinearQ.h"

void main()
{
  Queue q;
  int c,pop;

  printf("\n\t\t\tLINEAR QUEUE\n");
  do{
    printf("\n\t\tEnter 0 to Initialize Queue\n\t\tEnter 1 to Enqueue\n\t\tEnter 2 to Dequeue\n\t\ttEnter 3 to Display Queue\n\t\tEnter 4 to Exit Application\n");
    printf("Enter your choice: ");
    scanf("%d",&c);
    switch(c){
    	case 0:
    		printf("\nEnter the length of queue: ");
    		scanf("%d",&q.length);
    		initQueue(q);
    		break;
    		
		case 1:
			printf("Enter the valued to be Queued: ");
			int k;
			scanf("%d",&k);
			enQueue(q,k);
			break;
     
		case 2:
			pop=deQueue(q);
			printf("\nThe de-queued element was: %d",pop);
			break;

		case 3:
			displayQueue(q);
			break;

		case 4:
			printf("\n\t\t\tThank You!\n");
			break;

		default:
			printf("\nInvalid choice.\n");
			break;
	}

  }while(c!=4);
}