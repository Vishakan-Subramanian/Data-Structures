/*FUNCTION IMPLEMENTATIONS FOR STUDENT INFORMATION SYSTEM*/

typedef struct{
	int pin;
	char name[30];
	int age;
	char sex;
	char street[30];
	char city[30];
	
}person;

struct node{
	person p;
	struct node *left;
	struct node *right;
};

typedef struct{
	int mcount;
	int fcount;
}ratio;


struct node *initNode(){		//initialising new nodes
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}


void insertFront(struct node *list,person ps){		//to insert in front of the list
	struct node *temp,*ptr;

	temp=initNode();
	ptr=initNode();

	ptr=list->right;
	
	temp->p=ps;
	temp->right=list->right;
	list->right=temp;
	temp->left=list;	
	
	if(ptr!=NULL)
		ptr->left=temp;
		
}

void insertEnd(struct node *list, person ps){		//to insert at the end of list
	struct node *temp,*ptr;
	temp=initNode();
	ptr=initNode();

	ptr=list;
	temp->p=ps;

	while(ptr->right!=NULL)
		ptr=ptr->right;

	temp->right=ptr->right;
	ptr->right=temp;
	temp->left=ptr;
}

void insertAfterPIN(struct node *list, person ps, int epin){		//to insert after a given PIN number
	int flag=0;
	struct node *temp,*ptr,*next;
	temp=initNode();
	ptr=initNode();
	next=initNode();
	ptr=list->right;
	temp->p=ps;

	while(ptr->right!=NULL){
		if(ptr->p.pin==epin){
			(ptr->right)->left=temp;
			temp->right=ptr->right;
			temp->left=ptr;
			ptr->right=temp;
			flag++;
			break;
		}
		ptr=ptr->right;
	}
	if(flag==0)
		printf("\nThe PIN number was not found in the database.\nRecord was not inserted.");
}

void displayRec(struct node *r){		//to display a single record
	printf("\nPIN: %d\nName: %s\nAge: %d\nSex: %c\nStreet Address: %s\nCity Address: %s\n",r->p.pin,r->p.name,r->p.age,r->p.sex,r->p.street,r->p.city);
}

void displayInfo(struct node *list){		//to display selected list's records, forwards and backwards
	struct node *i,*temp;
	int c=1;
	i=initNode();
	temp=initNode();

	i=list->right;
	printf("\nNumbers while moving forward are: ");
	while(i->right!=NULL){
		printf("\nRecord %d",c);
		displayRec(i);
		i=i->right;
		c++;		

	}

	printf("\nRecord %d",c);
	displayRec(i);

	printf("\nNumbers while moving backward are: ");
	while(i->left!=NULL){
		printf("\nRecord %d",c);
		displayRec(i);
		i=i->left;
		c--;
	}
}

void sortList(struct node *list){		//to sort the existing list records by ascending order of age
	struct node *i,*j;
	person p1,p2,temp;
	i=initNode();
	j=initNode();
	i=list->right;
	
	while(i!=NULL){
		j=i->right;
		while(j!=NULL){
			p1=i->p;p2=j->p;
			if(p1.age > p2.age){
				temp=p1;
				p1=p2;
				p2=temp;
				i->p=p1;
				j->p=p2;
				
			}
			j=j->right;
		}
		i=i->right;
	}
}

ratio *adultPerson(struct node *list,ratio *r){		//to count the no. of males and females in the existing records
		r->mcount=0;
		r->fcount=0;
		struct node *i;
		i=initNode();
		i=list->right;
		while(i!=NULL){
			if(i->p.sex=='M'||i->p.sex=='m')
				r->mcount++;
			if(i->p.sex=='F'||i->p.sex=='f')
				r->fcount++;
			i=i->right;
			
		}
		return r;
}

void simpleRatio(ratio *r){		//to simplify male:female ratio and print it
	int a,b,temp,a1,b1;
	if(r->mcount>=r->fcount){
		a=r->mcount;
		b=r->fcount;
		a1=a;
		b1=b;
	}
	else{
		a=r->fcount;
		b=r->mcount;
	}
	if(a!=0){
		while(b!=0){
			temp=b;
			b=a%b;
			a=temp;
		}
	 	a1=r->mcount/a;
	 	b1=r->fcount/a;
	}

	printf("\nThe number of Males: %d and the number of Females: %d.\nThe Ratio is: %d : %d\n",r->mcount,r->fcount,a1,b1);

}

struct node *seniorPerson(struct node *list){		//to list senior citizens in existing records
	struct node *senior, *i;
	i=initNode();
	senior=initNode();
	i=list->right;

	while(i->right!=NULL){
		if(i->p.age>=60)
			insertFront(senior, i->p);
		i=i->right;
	}

	return senior;

}

void locatePerson(struct node *list, char s[]){		//to locate a person based on city
	struct node *i;
	i=initNode();
	i=list->right;

	while(i->right!=NULL){
		if(strcmp(i->p.city,s)==0)
			displayRec(i);
		i=i->right;
	}
}

int randomPIN(struct node *list){		//to generate a random unique PIN number from 0-1000
	int rpin;
	struct node *i;
	i=initNode();
	i=list->right;
	generate:
	srand(time(0));
	rpin=rand()%1000;

	if(list->right!=NULL){
		while(i->right!=NULL){
			if(i->p.pin==rpin)
				goto generate;
			i=i->right;
		}
	}
	
	return rpin;
}
