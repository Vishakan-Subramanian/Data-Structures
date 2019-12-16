typedef struct{
	char name[30];
	char role[10];
	float rr;
}playerInfo;

struct playerProfile{
	playerInfo p;
	struct playerProfile *left,*right;
};

struct playerProfile *insert(struct playerProfile *P, playerInfo x);
void display(struct playerProfile *P,int spacing);
struct playerProfile *search(struct playerProfile *P, char name[]);
struct playerProfile *findmin(struct playerProfile *P);
struct playerProfile *removePlayer(struct playerProfile *P,char name[]);
void inorder(struct playerProfile *P);
void preorder(struct playerProfile *P);
void postorder(struct playerProfile *P);

