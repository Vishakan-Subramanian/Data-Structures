/*FUNCTION PROTOTYPES FOR PERSON INFORMATION SYSTEM*/

struct node *initNode();
void insertFront(struct node *list,person ps);
void insertEnd(struct node *list, person ps);
void insertAfterPIN(struct node *list, person ps, int epin);
void displayRec(struct node *r)
void displayInfo(struct node *list);
void sortList(struct node *list);
ratio *adultPerson(struct node *list,ratio *r);
void simpleRatio(ratio *r);
struct node *seniorPerson(struct node *list);
void locatePerson(struct node *list, char s[]);
int randomPIN(struct node *list);
