typedef struct{
	int *a;
	int front,rear;
	int capacity;
}Queue;


void initQueue(Queue *q,int cap){
	q->front=0;		//not -1
	q->rear=-1;
	q->capacity=cap;
	q->a=(int *)malloc(sizeof(int)*cap);
}

int isEmpty(Queue *q){
	if(q->front>q->rear)
		return 1;
	return 0;
}

int isFull(Queue *q){
	if(q->rear==q->capacity-1)
		return 1;
	return 0;

}

void enQueue(Queue *q,int x){
	if(isFull(q))
		printf("\nQueue is Full! Cannot Enqueue any further!\n");
	else{
		q->a[++q->rear]=x;	
	}
}

int deQueue(Queue *q){
	return q->a[q->front++];

}

void displayQueue(Queue *q){
	int i;
	printf("\nQueue Elements:\n\t");
	for(i=q->front;i<=q->rear;i++){
		printf("%d ",q->a[i]);
	}
	
}