typedef struct{
	char name[20];
	int time;
}Job;

typedef struct{
	Job *j;
	int front,rear;
	int capacity;
	int size;
}Queue;

void initQueue(Queue *q,int cap);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enQueue(Queue *q,Job x);
Job deQueue(Queue *q);
void displayQueue(Queue *q);
int waitingTime(Queue *q);
void scheduleQueue(Queue *q1, Queue *q2, Job j);

