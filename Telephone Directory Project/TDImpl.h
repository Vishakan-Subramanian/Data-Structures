void initHT(HashTable *H){
	int i;
	for(i=0;i<100000;i++){
		H->list[i]=(struct node *)malloc(sizeof(struct node));
		H->list[i]->next=NULL;
	}
}

record getRecord(){
	record r;
	printf("\nEnter Person's Name: ");
	scanf(" %[^\n]",r.name);
	printf("\nEnter Person's Phone Number: ");
	scanf("%ld",&r.phone);
	printf("\nEnter Person's Address: ");
	scanf(" %[^\n]",r.addr);
	printf("\nEnter Person's PIN Code: ");
	scanf("%d",&r.pin);
	return r;
	
}

long hash(char name[]){
	int len = strlen(name);
	int i=0;
	long hash=0;
	while(i<len){
		hash = hash + (3*i*name[i]);
		i++;
	}
	return hash;
}

int fileWriter(record r){
	FILE *f;
	int chk=0;
	f= fopen("directory.dat","a");
	if(f==NULL){
		fclose(f);
		return 0;
	}
	else{
		chk = fwrite(&r,sizeof(r),1,f);
	}
	fclose(f);
	if(chk!=0)
		return 1;
	else
		return 0;
}

void insertRecord(HashTable *H, record r,int flag){
	struct node *temp,*i;
	long key;
	temp=(struct node *)malloc(sizeof(struct node));
	i=(struct node *)malloc(sizeof(struct node));
	temp->r=r;
	temp->next=NULL;

	key=hash(r.name);
	//printf("%ld",key);
	if(key>100000){
		key=key/723;		//Avoiding Hash Value Overflow
	}

	i=H->list[key];
	if(i==NULL){		//Inserting at First Node, if Node is Empty
		H->list[key]=temp;
	}
	else{
		while(i->next!=NULL){		//conflict resolution
			i=i->next;		
		}
		i->next=temp;		//Inserting at End, if Node isn't Empty
	}
	if(flag)
		if(fileWriter(r))
			printf("\nRecord Written to Database Successfully.\n");

}


void databaseLoader(HashTable *H){
	FILE *f;
	record r;
	f = fopen("directory.dat","r");
	if(f==NULL){
		fclose(f);
	}
	else{
		while(fread(&r,sizeof(r),1,f)){
			//printf("%s %d %ld %s",r.name,r.pin,r.phone,r.addr);
			insertRecord(H,r,0);
		}
		fclose(f);
	}

}

void displayHT(HashTable *H){
	struct node *i;
	i=(struct node *)malloc(sizeof(struct node));
	long key=0;
	printf("\nHash Table: ");
	while(key<100000){			//Traversing each bucket one by one
		i=H->list[key]->next;
		if(i!=NULL)
			printf("\n\n");
		while(i!=NULL){
			printf("%s",i->r.name);
			i=i->next;
			if(i!=NULL)
				printf("--->");
		}
		key++;
	}
}

record searchRecord(HashTable *H, char name[]){
	int key=hash(name);
	int flag=-1;
	struct node *i;
	record r;
	r.phone=-1;
	i=(struct node *)malloc(sizeof(struct node));
	i=H->list[key]->next;		//Starting from Next of first, since
	while(i!=NULL){				//thats where we start storing initially
		if(strcmp(i->r.name,name)==0){
			printf("\nName: %s\nPhone Number: %ld\nAddress: %s\nPIN Code: %d\n",i->r.name,i->r.phone,i->r.addr,i->r.pin);
			r=i->r;
			flag++;
		}
		i=i->next;
	}
	if(flag==-1)
		printf("\nThe were no records with the Name: %s.\n",name);
	return r;
}

int deleteRecord(HashTable *H, char name[]){
	int key=hash(name);
	int flag=0;
	struct node *i,*j;
	record r;
	i=(struct node *)malloc(sizeof(struct node));
	j=(struct node *)malloc(sizeof(struct node));
	i=H->list[key];
	j=i->next;
	while(j!=NULL){
		flag=0;
		if(strcmp(j->r.name,name)==0){
			i->next=j->next;
			flag++;
		}
		if(!flag)
			i=j;
		j=j->next;
	}
	if(flag==0){
		printf("\nThere were no records with the Name: %s.\n",name);
		return 0;
	}
	else{
		FILE *f1,*f2;
		f1=fopen("temp.dat","w");
		f2=fopen("directory.dat","r");
		while(fread(&r,sizeof(r),1,f2)){
			if(strcmp(r.name,name)!=0)
				fwrite(&r,sizeof(r),1,f1);
		}
		fclose(f1);
		fclose(f2);
		remove("directory.dat");
		rename("temp.dat","directory.dat");
		printf("\nRecord Deletion was Successful.\n");
		return 1;
	}

}


void updateRecord(HashTable *H, char name[]){
	record r;
	if(deleteRecord(H,name)){
		printf("\nEnter New Record Details:\n");
		r=getRecord();
		insertRecord(H,r,1);
	}
}

void swap(record *a, record *b){
    record r= *a;
    *a = *b;
    *b = r;
}

void quicksort(record rec[], int l, int r){
    if (l >= r){		// Base case: No need to sort arrays of length <= 1
        return;
    }

    char pivot_name[40];
    strcpy(pivot_name,rec[r].name);		// Choose pivot to be the last element in the subarray

    // Index indicating the "split" between elements smaller than pivot and 
    // elements greater than pivot
    int count = l;

    for(int i=l;i<=r;i++){
        // If an element less than or equal to the pivot is found...
        if (strcmp(rec[i].name,pivot_name)<=0){
            // Then swap arr[cnt] and arr[i] so that the smaller element arr[i] 
            // is to the left of all elements greater than pivot
            swap(&rec[count], &rec[i]);     
            count++;		 // Make sure to increment count so we can keep track of what to swap arr[i] with
        }
    }
    
    // NOTE: count is currently at one plus the pivot's index 
    // (Hence, the cnt-2 when recursively sorting the left side of pivot)
    quicksort(rec, l, count-2); // Recursively sort the left side of pivot
    quicksort(rec, count, r);   // Recursively sort the right side of pivot
}

void displayDB(){
	FILE *f;
	record r;
	f=fopen("directory.dat","r");
	if(f==NULL)
		fclose(f);
	else{
		printf("\n%-20s%-10s\t%-30s\t%-10s","Name","Phone","Address","PIN Code");
		printf("\n-----------------------------------------------------------------------------\n");
		while(fread(&r,sizeof(r),1,f)){
			printf("\n%-20s%ld\t%-30s\t%d",r.name,r.phone,r.addr,r.pin);
		}
		printf("\n-----------------------------------------------------------------------------\n");
		fclose(f);
	}

}

void sortedDisplay(){
	FILE *f;
	f=fopen("directory.dat","r");
	if(f==NULL)
		fclose(f);
	else{
		int i=0,j=0;
		record rec[10000],r;
		//rec = (record *)malloc(sizeof(record)*100000);
		while(fread(&r,sizeof(r),1,f)){
			rec[i++]=r;
		}
		fclose(f);
		quicksort(rec,0,i-1);
		printf("\n%-20s%-10s\t%-30s\t%-10s","Name","Phone","Address","PIN Code");
		printf("\n-----------------------------------------------------------------------------\n");
		while(j<i){
			printf("\n%-20s%ld\t%-30s\t%d",rec[j].name,rec[j].phone,rec[j].addr,rec[j].pin);
			j++;
		}
		printf("\n-----------------------------------------------------------------------------\n");
	}
}

