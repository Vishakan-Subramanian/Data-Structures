typedef struct{
	int city_count;
	int adj[100][100];
	char cities[100][30];
	int visited[10000];
	int cur_state;
	int pathway[100];
	
}cityADT;

cityADT *initADT(cityADT *c, int size);
int min(int a,int b);
int isFullState(cityADT *c);
int findCity(cityADT *c, char city[]);
void create(cityADT *c, char start[], char dest[]);
void visit(cityADT *c, int x);
int unvisited(cityADT *c);
void visit(cityADT *c, int x);
void display(cityADT *c);
void clearVisits(cityADT *c);
void DFSTraverse(cityADT *c,int x);
int DFSPath(cityADT *c, char start[], char dest[]);
void PathPrinter(cityADT *c,int start,int end);


