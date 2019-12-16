typedef struct{
	int *a;
	int front,rear;
	int capacity;
	int size;
}Queue;


void initQueue(Queue *q,int cap){
	q->front=q->rear=-1;
	q->capacity=cap;
	q->a=(int *)malloc(sizeof(int)*cap);
	q->size=0;
}

int isEmpty(Queue *q){
	if(q->size==0)
		return 1;
	return 0;
}

int isFull(Queue *q){
	if(q->size==q->capacity)
		return 1;
	return 0;

}

void enQueue(Queue *q,int x){
	if(isFull(q))
		printf("\nQueue is Full! Cannot Enqueue any further!\n");
	else{
		q->rear=(q->rear+1)%q->capacity;
		q->a[q->rear]=x;
		q->size++;	
	}

	if(q->front==-1)
		q->front=0;

	
}

int deQueue(Queue *q){
	int pop;
	pop= q->a[q->front];
	if(q->rear==q->front){
		q->front=q->front=-1;
	}
	else
		q->front=(q->front+1)%q->capacity;
	
	q->size--;
	
	
	return pop;
}

void displayQueue(Queue *q){
	int i=0;
	int ptr=q->front;
	if(isEmpty(q))
		printf("\nQueue is Empty!");
	else{
		printf("\nQueue Elements:\n\t");
		while(i<q->size){
			printf("%d ",q->a[ptr]);		
			i++;
			ptr=(ptr+1)%q->capacity;
		}
	}
}
