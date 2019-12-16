#include<stdio.h>
#include<stdlib.h>
#include "CircularQ.h"

void main(){
	int c=0,x,size=0;
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	

	printf("\n\t\t\tLINEAR QUEUE\n");
	do{
		printf("\nEnter a choice:\n1 to Enqueue\n2 to Dequeue\n3 to Display\n4 to Initialize Queue Size\n0 to Exit\n\t->");
		scanf("%d",&c);

		switch(c){
			case 1:
				printf("\nEnter an element: ");
				scanf("%d",&x);
				enQueue(q,x);
				break;
			case 2:
				if(!isEmpty(q))
					printf("\nThe dequeued element : %d",deQueue(q));
				else
					printf("\nQueue is Empty! Cannot Dequeue any further!\n");
				break;
			case 3:
				displayQueue(q);
				break;
			case 4:
				printf("\nEnter the size of queue: ");
				scanf("%d",&size);
				initQueue(q,size);
				break; 
			case 0:
				break;
			default:
				printf("\nInvalid Option!");
		}

	}while(c!=0);
}


/*

OUTPUT FOR LINEAR QUEUE:

exam62@jtl-16:~/DSLAB$ gcc QueueApp.c -o q
exam62@jtl-16:~/DSLAB$ ./q

			LINEAR QUEUE

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
0 to Exit
	->1

Enter an element: 1

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
0 to Exit
	->1

Enter an element: 2

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
0 to Exit
	->1

Enter an element: 3

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
0 to Exit
	->1

Enter an element: 4

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
0 to Exit
	->3

Queue Elements:
	1 2 3 4 
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
0 to Exit
	->2

The dequeued element : 1
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
0 to Exit
	->2

The dequeued element : 2
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
0 to Exit
	->2

The dequeued element : 3
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
0 to Exit
	->2

The dequeued element : 4
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
0 to Exit
	->2

Queue is Empty! Cannot Dequeue any further!

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
0 to Exit
	->3

Queue Elements:
	
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
0 to Exit
	->0

*/


/*

OUTPUT FOR CIRCULAR QUEUE:
exam62@jtl-16:~/DSLAB$ gcc QueueApp.c -o q
exam62@jtl-16:~/DSLAB$ ./q

			LINEAR QUEUE

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->4

Enter the size of queue: 3 

Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->1

Enter an element: 1
FRONT: 0, REAR: 0
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->1

Enter an element: 2
FRONT: 0, REAR: 1
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->1

Enter an element: 3
FRONT: 0, REAR: 2
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->3

Queue Elements:
	1 2 3 
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->2
FRONT: 1, REAR: 2
The dequeued element : 1
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->3

Queue Elements:
	2 3 
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->1

Enter an element: 4
FRONT: 1, REAR: 0
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->3

Queue Elements:
	2 3 4 
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->2
FRONT: 2, REAR: 0
The dequeued element : 2
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->3

Queue Elements:
	3 4 
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->1

Enter an element: 5
FRONT: 2, REAR: 1
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->3

Queue Elements:
	3 4 5 
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->2
FRONT: 0, REAR: 1
The dequeued element : 3
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->3

Queue Elements:
	4 5 
Enter a choice:
1 to Enqueue
2 to Dequeue
3 to Display
4 to Initialize Queue Size
0 to Exit
	->0

*/
