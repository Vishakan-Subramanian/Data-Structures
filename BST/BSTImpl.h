struct playerProfile *insert(struct playerProfile *P, playerInfo x){
	if(P==NULL){
		P=(struct playerProfile *)malloc(sizeof(struct playerProfile));
		P->left=NULL;
		P->right=NULL;		
		P->p=x;
	}
	
	else{
		
		if(strcmp(P->p.name,x.name)<0)
			P->right=insert(P->right,x);
		else
			P->left=insert(P->left,x);
	}
	return P;	
}

void display(struct playerProfile *P,int spacing){
	if(P!=NULL){	
		int i=0;
	
		printf("\n");
		while(i<spacing){
			printf("\t");
			i++;
		}
		printf("%s",P->p.name);
       		display(P->left,spacing+1);
		display(P->right,spacing+1);
	}

}

struct playerProfile *search(struct playerProfile *P, char name[]){
	if(P==NULL)
		return NULL;

	if(strcmp(P->p.name,name)==0)
		return P;	

	if(strcmp(P->p.name,name)<0)
		return search(P->right,name);
	else
		return search(P->left,name);

}

struct playerProfile *findmin(struct playerProfile *P){
	while(P->left!=NULL)
		return findmin(P->left);
	if(P->left==NULL)
		return P;
}

struct playerProfile *removePlayer(struct playerProfile *P,char name[]){
	struct playerProfile *t;
	t=(struct playerProfile *)malloc(sizeof(struct playerProfile));
	
	if(strcmp(P->p.name,name)<0)
		P->right=removePlayer(P->right,name);

	else if(strcmp(P->p.name,name)>0)
		P->left=removePlayer(P->left,name);
		

	else if(P->right!=NULL && P->left!=NULL){
		t=findmin(P->right);
		P->p=t->p;
		P->right=removePlayer(P->right,P->p.name);
	}
	
	else{
		if(P->right==NULL && P->left!=NULL){
			P=P->left;
		}
		else if(P->left==NULL && P->right!=NULL){
			P=P->right;
		}
		else{
			P=NULL;
		}
			
	}

	return P;
}

void inorder(struct playerProfile *P){
	if(P!=NULL){
		inorder(P->left);
		printf("\n%s",P->p.name);
		inorder(P->right);
	}
}

void preorder(struct playerProfile *P){
	if(P!=NULL){
		printf("\n%s",P->p.name);
		preorder(P->left);
		preorder(P->right);
	}
}

void postorder(struct playerProfile *P){
	if(P!=NULL){
		postorder(P->left);
		postorder(P->right);
		printf("\n%s",P->p.name);		
	}
}

