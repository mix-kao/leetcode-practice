#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[10];
    int  num, score;
    struct student *next;
} node;


void addNode(node* head, char* name) {
    node* ptr = (node*) malloc(sizeof(node));
    if(!ptr) {printf("Error, memory allocate fail...\n"); exit(1);}
    strcpy(ptr->name, name);
    ptr->num = 10002;
    ptr->score = 66;
    ptr->next = NULL;
    while(head) {
        if(!head->next) {head->next = ptr; break;}
        head = head->next;
    }
}

void delNode(node* curr, char* name) {
    node* prev = curr;
    printf("1 delNode %s\n", name);
    while(curr) {
        printf("%s %s\n", curr->name, name);
        if(!strcmp(curr->name, name)) {
            printf("%s \n", curr->name);
            prev->next = curr->next;
            curr->next = NULL;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    free(curr);
    printf("2 delNode=====\n");
}

static char student_name_data[5][10] = {"abc", "def", "ghi", "jkl", "mno"};

int main(void) {
    node s1 = {"Mary", 10000, 100};
    node *s2 = (node*)malloc(sizeof(node));
    strcpy(s2->name, "Jonb"); s2->num = 10003;s2->score = 77;s2->next=NULL;
    node* head = &s1;
    node* top = head;
    s1.next = s2;
    
    int student_num = sizeof(student_name_data)/sizeof(student_name_data[0]);
    printf("%ld, %ld \n", sizeof(student_name_data), sizeof(student_name_data[0]));
    for(int i=0; i<student_num; i++) {
        addNode(head, student_name_data[i]);
    }
    while(top) {
        printf("node name = %s, num = %d, score = %d\n", top->name, top->num, top->score);
        top = top->next;
    }
    delNode(head, "mno");
    delNode(head, "abc");
    delNode(head, "Jonb");
    top = head;
    while(top) {
        printf("node name = %s, num = %d, score = %d\n", top->name, top->num, top->score);
        top = top->next;
    }
   
    return 0;
}
