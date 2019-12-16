/*
1. Modify the circular queue to contain job number and the cpu burst time
2. Instantiate 2 circular queues Q1 and Q2 
3. Insert circular queue with the following contents 
(J1,2), (J2,4), (J3,8), (J4,5), (J5,2), (J6,7), (J7,4), (J8,3) (J9,6) & (J10,6)
4. Insert the job into the circular queue whichever is empty. If it is not empty, insert the job into the queue whichever is having minimum average time
5. Display the jobs waiting in both the queues along with their cpu burst time.

*/

#include<stdio.h>
#include<stdlib.h>
#include "QueueIFV2.h"
#include "CircularQV2.h"


void main(){
	int c=0,qch,size=0;
	Job x;
	Queue *q1,*q2;
	q1=(Queue *)malloc(sizeof(Queue));
	q2=(Queue *)malloc(sizeof(Queue));
	

	printf("\n\t\t\tJOB SCHEDULING\n");
	do{
		printf("\nEnter a choice:\n1 to Enqueue\n2 to Dequeue\n3 to Display\n4 to Initialize Queue Size\n0 to Exit\n\t->");
		scanf("%d",&c);

		switch(c){
			case 1:
				printf("\nEnter Job Name: ");
				scanf("%s",x.name);
				printf("\nEnter Job CPU Time: ");
				scanf("%d",&x.time);
				scheduleQueue(q1,q2,x);
				break;
			case 2:
				printf("\nEnter Queue Name to Dequeue: ");
				scanf("%d",&qch);
				if(qch==1){
					if(!isEmpty(q1)){
						x=deQueue(q1);
						printf("\nThe Dequeued Job Name : %s and Job Time: %d",x.name,x.time);
					}
					else
						printf("\nQueue is Empty! Cannot Dequeue any further!\n");
				}

				else if(qch==2){
					if(!isEmpty(q2)){
						x=deQueue(q2);
						printf("\nThe Dequeued Job Name : %s and Job Time: %d",x.name,x.time);
					}
					else
						printf("\nQueue is Empty! Cannot Dequeue any further!\n");
				}

				else
					printf("\nInvalid Queue choice.");
			
				break;
			case 3:
				printf("\nEnter Queue Name to Display: ");
				scanf("%d",&qch);
				if(qch==1){
					displayQueue(q1);
				}
				else if(qch==2){
					displayQueue(q2);
				}
				else
					printf("\nInvalid Queue choice.");

				break;
			case 4:
				printf("\nEnter the size of Queue1: ");
				scanf("%d",&size);
				initQueue(q1,size);
				printf("\nEnter the size of Queue2: ");
				scanf("%d",&size);
				initQueue(q2,size);
				break; 
			case 0:
				break;
			default:
				printf("\nInvalid Option!");
		}

	}while(c!=0);

}


/*
OUTPUT:
exam62@jtl-16:~/DSLAB$ gcc QueueAppl.c -o q
exam62@jtl-16:~/DSLAB$ ./q

			JOB SCHEDULING

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->4

Enter the size of Queue1: 3

Enter the size of Queue2: 3

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->1

Enter Job Name: A

Enter Job CPU Time: 10

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->1

Enter Job Name: B

Enter Job CPU Time: 12

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->1

Enter Job Name: C

Enter Job CPU Time: 14

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->3

Enter Queue Name to Display: 1

Queue Elements:
	
Name: B CPU Time: 12
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->3

Enter Queue Name to Display: 2

Queue Elements:
	
Name: A CPU Time: 10
Name: C CPU Time: 14
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->2

Enter Queue Name to Dequeue: 2

The Dequeued Job Name : A and Job Time: 10
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->1

Enter Job Name: D

Enter Job CPU Time: 8

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->3

Enter Queue Name to Display: 2

Queue Elements:
	
Name: C CPU Time: 14
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->3

Enter Queue Name to Display: 1

Queue Elements:
	
Name: B CPU Time: 12
Name: D CPU Time: 8
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->1

Enter Job Name: E

Enter Job CPU Time: 7

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->3

Enter Queue Name to Display: 2

Queue Elements:
	
Name: C CPU Time: 14
Name: E CPU Time: 7
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->2

Enter Queue Name to Dequeue: 1

The Dequeued Job Name : B and Job Time: 12
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->2

Enter Queue Name to Dequeue: 1

The Dequeued Job Name : D and Job Time: 8
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->2

Enter Queue Name to Dequeue: 1

Queue is Empty! Cannot Dequeue any further!

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->2

Enter Queue Name to Dequeue: 2 

The Dequeued Job Name : C and Job Time: 14
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->2

Enter Queue Name to Dequeue: 2

The Dequeued Job Name : E and Job Time: 7
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->2

Enter Queue Name to Dequeue: 2

Queue is Empty! Cannot Dequeue any further!

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->0

*/
