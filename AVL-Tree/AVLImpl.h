int height(struct avl *D){
	if(D==NULL)
		return 0;
	else
		return D->height;
}

int maxi(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}

void display(struct avl *D,int spacing){
	if(D!=NULL){	
		int i=0;
	
		printf("\n");
		while(i<spacing){
			printf("\t");
			i++;
		}
		printf("%s",D->n.word);
       		display(D->left,spacing+1);
		display(D->right,spacing+1);
	}
}

struct avl *SRL(struct avl *k2){
	struct avl *k1;
	k1=(struct avl *)malloc(sizeof(struct avl));
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2->height=maxi(height(k2->left),height(k2->right))+1;
	k1->height=maxi(height(k1->left),k2->height)+1;


	return k1;
}

struct avl *SRR(struct avl *k2){
	struct avl *k1;
	k1=(struct avl *)malloc(sizeof(struct avl));
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;

	k2->height=maxi(height(k2->left),height(k2->right))+1;
	k1->height=maxi(height(k1->right),k2->height)+1;


	return k1;
}

struct avl *DRL(struct avl *k3){ 
    //rotate between k1 and k2
	k3->left=SRR(k3->left);

	//rotate between k3 and k2
	return SRL(k3);
}


struct avl *DRR(struct avl *k3){ 
    //rotate between k1 and k2
	k3->right=SRL(k3->right);

	//rotate between k3 and k2
	return SRR(k3);
}

struct avl *insert(struct avl *D, node x){
	int hdiff;

	if(D==NULL){
		D=(struct avl *)malloc(sizeof(struct avl));
		D->n=x;
		D->height=0;
		D->left=NULL;
		D->right=NULL;
	}

	else if(strcmp(D->n.word,x.word)<0){
		D->right=insert(D->right,x);
		hdiff=abs(height(D->left)-height(D->right));
		if(hdiff==2){
			if(strcmp(D->n.word,x.word)<0)
				D=SRR(D);
			
			else
				D=DRR(D);
		}
	}

	else if(strcmp(D->n.word,x.word)>0){
		D->left=insert(D->left,x);
		hdiff=abs(height(D->left)-height(D->right));
		if(hdiff==2){
			if(strcmp(D->n.word,x.word)>0)				
				D=SRL(D);
			
			else
				D=DRL(D);

		}

	}

	else{
		printf("\nWord already present in the database!");
	}

	D->height=maxi(height(D->left),height(D->right))+1;
	return D;
}

struct avl *search(struct avl *D, char name[]){
	if(D==NULL)
		return NULL;

	if(strcmp(D->n.word,name)==0)
		return D;	

	if(strcmp(D->n.word,name)<0)
		return search(D->right,name);
	else
		return search(D->left,name);

}
