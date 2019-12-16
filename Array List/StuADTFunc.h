/* FUNCTION PROTOTYPES */

void insertFront(ListADT *l,student s);
void insertEnd(ListADT *l,student s);
void insertRegNo(ListADT *l,student s,int RegNum);
student searchRegNo(ListADT l,int RegNum);
ListADT searchName(ListADT l,char stuname[30]);
void deleteRecord(ListADT *l,int RegNum);
void computeResult(ListADT *l);
ListADT listResult(ListADT l);
int listClass(ListADT l);
void displayRecord(student s);
void displayAll(ListADT l);
student readInput(ListADT *l);
void mainMenu(ListADT *l, int ch);

