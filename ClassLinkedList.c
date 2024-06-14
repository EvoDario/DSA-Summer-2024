#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char fname[15];
    char lname[15];
    char MI;
} nameInfo;

typedef struct {
    nameInfo name;
    int ID;
    int age;
} studInfo;

typedef struct node {
    studInfo student;
    struct node *next;
} classList, *nodePtr;

void insertFrontList(nodePtr *head, studInfo stud);
void insertRearList(nodePtr *head, studInfo stud);
void displayList(nodePtr curr);

int main() {
    nodePtr newClass = NULL;
    studInfo newstud[] = {{{"Revo", "Magnusson", 'C'}, 19103225, 23}, {{"Lancelot", "Paxley", 'C'}, 19103235, 24}, {{"Guinevere", "Paxley", 'C'}, 192345, 23}};

    insertFrontList(&newClass, newstud[0]);
    insertFrontList(&newClass, newstud[1]);
    insertFrontList(&newClass, newstud[2]);
    insertRearList(&newClass, newstud[2]);
    insertRearList(&newClass, newstud[0]);

    displayList(newClass);

    return 0;
}

void insertFrontList(nodePtr *head, studInfo stud) {
    nodePtr temp = malloc(sizeof(classList));
    if (temp == NULL) {
        printf("Failed");
    }
    temp->student = stud;
    temp->next = *head;
    *head = temp;
}

void insertRearList(nodePtr *head, studInfo stud){
	
	nodePtr temp = malloc(sizeof(classList));
    if (temp == NULL) {
        printf("Failed");
    }
    temp->student = stud;
    temp->next = NULL;
    
	for(;(*head)->next!=NULL; head= &((*head)->next)){}
	
	(*head)->next = temp;
	
}

void displayList(nodePtr curr) {
    if (curr == NULL) {
        printf("Class is Empty\n");
    } else {
        for (; curr != NULL; curr = curr->next) {
            printf("%d %s, %s, %c\n", curr->student.ID, curr->student.name.fname, curr->student.name.lname, curr->student.name.MI);
        }
    }
}

