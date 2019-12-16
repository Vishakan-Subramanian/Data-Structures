cityADT *initADT(cityADT *c, int size){
	int i,j;
	c=(cityADT *)malloc(sizeof(cityADT));
	c->city_count=size;
	for(i=0;i<=size;i++){
		for(j=0;j<=size;j++){
			//if(i==j)
			//	c->adj[i][j]=1;
			//else
				c->adj[i][j]=0;
		}
	}
	c->cur_state=-1;
	return c;
}

int min(int a,int b){
	return a<b?a:b;
}

int isFullState(cityADT *c){
	return c->city_count<c->cur_state;
}

int findCity(cityADT *c, char city[]){
	int i=0;
	for(i=0;i<=c->cur_state;i++){
		if(strcmp(c->cities[i],city)==0)
			return i;
	}
	strcpy(c->cities[++c->cur_state],city);		//assigning the city to the cur_state+1 if it does not exist
	return c->cur_state;						//used only while create routine is called
}

void create(cityADT *c, char start[], char dest[]){
	if(!isFullState(c)){
		int i=findCity(c,start);
		int j=findCity(c,dest);
		c->adj[i][j]=1;
		printf("\n%s is now connected with %s.",start,dest);
	}
	else{
		printf("\nData limit has been reached. No more additions can be made.");
	}
}

void visit(cityADT *c, int x){
	c->visited[x]=1;
}


int unvisited(cityADT *c){
	int i;
	int limit=min(c->city_count-1,c->cur_state);
	for(i=0;i<=limit;i++){
		if(c->visited[i]==0)
			return i;
	}
	return -1;
}

int connect(cityADT *c, char start[], char dest[]){
	int i,j,size;
	size=c->cur_state;
	i=findCity(c,start);
	j=findCity(c,dest);
	if(i>size||j>size)
		return 0;
	else
		return c->adj[i][j];
}

void display(cityADT *c){
	int i,j;
	int limit=min(c->city_count-1,c->cur_state);
	for(i=0;i<=limit;i++){
		printf("\n%s is connected to:\n",c->cities[i]);
		for(j=0;j<=limit;j++){
			if(connect(c,c->cities[i],c->cities[j]))
				printf("  %s",c->cities[j]);
		}
	}
}


void clearVisits(cityADT *c){
	int x;
	for(x=0;x<1000;x++){		//making all nodes to be not visited.
		c->visited[x]=0;
	}
	for(x=0;x<100;x++)
		c->pathway[x]=0;
}

void DFSTraverse(cityADT *c,int x){
	int y,z;
	int limit=min(c->city_count-1,c->cur_state);
	visit(c,x);
	c->pathway[x]=1;
	for(y=0;y<=limit;y++){
		if(c->adj[x][y]==1 && c->visited[y]==0){
			visit(c,y);	
			DFSTraverse(c,y);
		}
	}
}

int DFSPath(cityADT *c, char start[], char dest[]){
	int start_node=findCity(c,start);
	int end_node=findCity(c,dest);
	DFSTraverse(c,start_node);
	
	if(c->pathway[start_node]==c->pathway[end_node])
		return 1;
	else
		return 0;
}

void PathPrinter(cityADT *c,int start,int end){
	int y=0;
	int limit=min(c->city_count-1,c->cur_state);
	for(y=start;y<=end;y++)
		if(c->visited[y]==1)
			printf("\t%s",c->cities[y]);
}
