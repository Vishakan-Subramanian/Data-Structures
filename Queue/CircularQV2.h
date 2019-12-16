

void initQueue(Queue *q,int cap){
	q->front=q->rear=-1;
	q->capacity=cap;
	q->j=(Job *)malloc(sizeof(Job)*cap);
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

void enQueue(Queue *q,Job x){
	if(isFull(q))
		printf("\nQueue is Full! Cannot Enqueue any further!\n");
	else{
		q->rear=(q->rear+1)%q->capacity;
		q->j[q->rear]=x;
		q->size++;	
	}

	if(q->front==-1)
		q->front=0;

	
}

Job deQueue(Queue *q){
	Job pop;
	pop= q->j[q->front];
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
			printf("\nName: %s CPU Time: %d",q->j[ptr].name,q->j[ptr].time);		
			i++;
			ptr=(ptr+1)%q->capacity;
		}
	}
}


int waitingTime(Queue *q){
	int tottime=0;
	int i=0;
	int ptr=q->front;
	
	if(!isEmpty(q)){
		while(i<q->size){
			tottime+=q->j[ptr].time;
			ptr=(ptr+1)%q->capacity;
			i++;
		}
	}

	return tottime;
	
}

void scheduleQueue(Queue *q1, Queue *q2, Job j){
	if(waitingTime(q1)<waitingTime(q2))
		enQueue(q1,j);
	else
		enQueue(q2,j);
}
