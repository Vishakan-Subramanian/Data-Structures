typedef struct{
	long phone;
	char name[40];
	char addr[100];
	int pin;
}record;

struct node{
	record r;
	struct node *next;
};

typedef struct{
	struct node *list[100000];
}HashTable;

void initHT(HashTable *H);
record getRecord();
long hash(char name[]);
int fileWriter(record r);
void insertRecord(HashTable *H, record r,int flag);
void databaseLoader(HashTable *H);
void displayHT(HashTable *H);
record searchRecord(HashTable *H, char name[]);
int deleteRecord(HashTable *H, char name[]);
void updateRecord(HashTable *H, char name[]);
void swap(record *a, record *b);
void quicksort(record rec[], int l, int r);
void displayDB();
void sortedDisplay();


