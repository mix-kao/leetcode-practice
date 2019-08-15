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

static char student_name_data[5][10] = {"abc", "def", "ghi", "jkl", "mno"};

int main(void) {
    node s1 = {"Mary", 10000, 100};
    node s2 = {"Jonb", 10001, 100};
    node* head = &s1;
    s1.next = &s2;
    s2.next = NULL;
    
    int student_num = sizeof(student_name_data)/sizeof(student_name_data[0]);
    printf("%ld, %ld \n", sizeof(student_name_data), sizeof(student_name_data[0]));
    for(int i=0; i<student_num; i++) {
        addNode(head, student_name_data[i]);
    }
    while(head) {
        printf("node name = %s, num = %d, score = %d\n", head->name, head->num, head->score);
        head = head->next;
    }
    
    return 0;
}
