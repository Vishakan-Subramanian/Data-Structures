typedef struct{
	char word[30];
	char mean[100];
}node;

struct avl{
	node n;
	int height;
	struct avl *left,*right;
};

int height(struct avl *D);
int maxi(int a,int b);
void display(struct avl *D,int spacing);
struct avl *SRL(struct avl *k2);
struct avl *SRR(struct avl *k2);
struct avl *DRL(struct avl *k3);
struct avl *DRR(struct avl *k3);
struct avl *insert(struct avl *D, node x);
struct avl *search(struct avl *D, char name[]);

