/* FUNCTIONS AND VARIABLES FOR STUDENT LIST IMPLEMENTATION PROGRAM */

#define limit 100


typedef struct{     //struct for student list ADT implementation
	int regno;
	char name[30];
	char resGrade;
	int total;
	int m1,m2,m3;

	}student;

typedef struct{
    student srec[limit];
    int size;       //maximum size of ListADT
}ListADT;



void displayRecord(student s){		//to display a single record
        printf("%5d %-25s %7d %7d %7d %7d \t%c\n",s.regno,s.name,s.m1,s.m2,s.m3,s.total,s.resGrade);
}


void displayAll(ListADT l){		//to display all records
	int i;
	if(l.size!=-1){
		printf("\n---------------------------------------------------------------------\n");
		printf("%5s %-25s %-7s %-7s %-7s %-7s %s\n","RegNo","Name","Sub1","Sub2","Sub3","Total","Grade");
		printf("---------------------------------------------------------------------\n");	
		for(i=0;i<l.size+1;i++)
			if(l.srec[i].regno!=0)
				displayRecord(l.srec[i]);
		printf("---------------------------------------------------------------------\n");
	}
	
	else
		printf("\nNo records to be shown.\n");
}



void initADT(ListADT *l){		//initialising an ADT with required values
    int i;
    l->size=-1;
}


void insertFront(ListADT *l,student s){  //to insert data into the list,in the front
	int i;
	
	if(l->size+1<limit)	{
		for(i=l->size+1;i>0;i--)
			l->srec[i]=l->srec[i-1] ;
		
		l->srec[0]=s;
		l->size++;
	}
	
	else
		printf("\nMaximum Array Size has been reached. Cannot insert further.") ;
} 
	


void insertEnd(ListADT *l,student s){     //to insert data behind existing data
	if(l->size+1<limit)	
		l->srec[++l->size]=s;
	
	else
		printf("\nMaximum Array Size has been reached. Cannot insert further.") ;
}

void insertRegNo(ListADT *l,student s,int RegNum){       //to insert data after a particular dataset
	int flag=0,i,j;
	if(l->size>=limit){
		printf("\nMaximum Array Size has been reached. Cannot insert further.");
	}

	else{
		for(i=0;i<l->size+1;i++) 
			if(RegNum==l->srec[i].regno){
				flag++;	 
				break;
				
			}
		
		for(j=l->size +1;j>i+1;j--)
			l->srec[j]=l->srec[j-1];	
		l->srec[i+1]=s;
		l->size+=1;
		
	}
	if(flag==0)
			printf("\nRegister Number was not Found. The record was not inserted.");
}

student searchRegNo(ListADT l,int RegNum){     //to search for a student based on register number
    int i,flag=0;
    student temp={0,"-",'F',0,0,0,0};		//temp record with default values so that some struct can be returned
    for(i=0;i<l.size+1;i++){
        if(l.srec[i].regno==RegNum){
            temp=l.srec[i];
            flag++;
            break;
        }
    }

    return temp;
}

ListADT searchName(ListADT l,char stuname[30]){        //to search for a student based on name
    int i,flag=0;
    ListADT temp;
    initADT(&temp);
    for(i=0;i<l.size+1;i++){
        if(strcmp(l.srec[i].name,stuname)==0){
            temp.srec[++temp.size]=l.srec[i];
            flag++;
        }
    }
    if(flag==0){
        printf("\nStudent was not found.");
    }
    return temp;
    
}

void deleteRecord(ListADT *l,int RegNum){        //to delete a record based on reigster number
    int i,flag=0,j=0;
    student temp;
    if(l->size!=-1){
		for(i=0;i<l->size+1;i++)
			if(l->srec[i].regno==RegNum){
				temp=l->srec[i];
				flag++;
				break;
			}
		if(flag!=0){
                for(j=i;j<l->size+1;j++)
                    l->srec[j]=l->srec[j+1];
                l->size--; 
                printf("\n---------------------------------------------------------------------\n");
                printf("%5s %-25s %-7s %-7s %-7s %-7s %s\n","RegNo","Name","Sub1","Sub2","Sub3","Total","Grade");
                printf("---------------------------------------------------------------------\n");
                displayRecord(temp);
                printf("---------------------------------------------------------------------\n");
	   }
    }
    else{
    	printf("The database is empty. Further deletion is not possible.");
    }
    if(flag==0)
        printf("\nStudent was not found.");
}

void computeResult(ListADT *l){      //to compute the grade and total of existing student records
    int i=0;
    for(i=0;i<l->size+1;i++){
        l->srec[i].total=l->srec[i].m1+l->srec[i].m2+l->srec[i].m3;
        if(l->srec[i].total>=270)
            l->srec[i].resGrade='O';
        else if(l->srec[i].total>=240)
            l->srec[i].resGrade='A';
        else if(l->srec[i].total>=210)
            l->srec[i].resGrade='B';
        else if(l->srec[i].total>=180)
            l->srec[i].resGrade='C';
        else if(l->srec[i].total>=120)
            l->srec[i].resGrade='D';
        else
            l->srec[i].resGrade='F';
        
    }
}

ListADT listResult(ListADT l){        //to list the passed students
    int i=0;
    ListADT temp;
    initADT(&temp);
    for(i=0;i<l.size+1;i++){
        if(l.srec[i].m1>=40&&l.srec[i].m2>=40&&l.srec[i].m3>=40)
            temp.srec[++temp.size]=l.srec[i];
    }
    return temp;
}



int listClass(ListADT l){      //to list the first class passed students
    int i=0,count=0;
    ListADT temp;
    initADT(&temp);
    //temp.size=-1;
    for(i=0;i<=l.size+1;i++){
        if(l.srec[i].m1>=60&&l.srec[i].m2>=60&&l.srec[i].m3>=60)
            temp.srec[++temp.size]=l.srec[i];
    }
    displayAll(temp);
    return temp.size+1;
}


student readInput(ListADT *l){      //to read student details from the user
	student s;
    printf("\nEnter Student Details :-");
    askregno:
    printf("\n\tRegister Number: ");
    scanf("%d",&s.regno);
    if(s.regno<=0){
    	printf("\nInvalid Register Number. Enter only Positive Numbers.");
    	goto askregno;
    }

    printf("\tName: ");
    scanf(" %s",s.name);
    printf("\tMarks:\n\tSubject 1: ");
    scanf("%d",&s.m1);
    printf("\tSubject 2: ");
    scanf("%d",&s.m2);
    printf("\tSubject 3: ");
    scanf("%d",&s.m3);
    
    return s;
	
} 


void mainMenu(ListADT *l, int ch){		//to display a do...while based main menu screen
    int regnum;
    student s;
    
    switch(ch) {
            case 1:
                    s=readInput(l);
                    insertFront(l,s);
                    break;
            case 2:
                    s=readInput(l);
                    insertEnd(l,s); 
                    break;
            case 3:
                    s=readInput(l);
                    printf("\nEnter Reg.Num. of Student after which record is to be inserted: ");
                    scanf("%d",&regnum);
                    insertRegNo(l,s,regnum);
                    break;
            case 4:
                    computeResult(l);
                    displayAll(*l);
                    break;
            case 5:
                    computeResult(l);
                    printf("\nThe no.of students who got first class: %d\n",listClass(*l));
                    break;
            case 6:
                    computeResult(l);
                    displayAll(listResult(*l));
                    break;
            case 7:
                    computeResult(l);
                    char sname[50];
                    printf("Enter Name to be searched : ");
                    scanf("%s",sname);
                    displayAll(searchName(*l,sname));
                    break;

            case 8:
                    computeResult(l);
                    printf("Enter Register Number to be searched : ");
                    scanf("%d",&regnum);
                    s=searchRegNo(*l,regnum);
                    if(s.regno == 0)
                        printf("Student was not found.\n");
                    else{
                        printf("\n---------------------------------------------------------------------\n");
                        printf("%5s %-25s %-7s %-7s %-7s %-7s %s\n","RegNo","Name","Sub1","Sub2","Sub3","Total","Grade");
                        printf("---------------------------------------------------------------------\n"); 
                        displayRecord(s);
                        printf("---------------------------------------------------------------------\n");
                    }
                        break;

            case 9 :
                    printf("Enter Student's Register Number : "); 
                    scanf("%d",&regnum); 
                    deleteRecord(l,regnum);
                    break;
            }

}

