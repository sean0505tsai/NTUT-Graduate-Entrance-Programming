#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int studentID;
    double GPA;
    Student_t *next;  // 1-1: next
} Student_t;

void printStudentInfo(Student_t *current) {
    while (current != NULL) {
        printf(" ID: %d, GPA: %.2f\n", current->studentID, current->GPA);
        current = current->next;
    }
}

Student_t* addStudent(Student_t* head, int studentID, double GPA) {
    Student_t* newStudent = (Student_t*)malloc(sizeof(Student_t));
    
    if ( newStudent == NULL ) {     // 1-2: newStudent == NULL
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newStudent->studentID = studentID;
    newStudent->GPA = GPA;
    newStudent->next = head;  // 1-3: newStudent->next = head
    return newStudent;
}

void freeList(Student_t *head) {
    Student_t *current;
    while (head != NULL) {
        current = head;      // 1-4: current = head
        free(current);
        head = head->next;
    }
}

void main() {
    Student_t *head = NULL;      // 1-5: Student_t *head = NULL
    head = addStudent(head, 112590001, 3.75);
    head = addStudent(head, 112590025, 3.80);
    head = addStudent(head, 112590011, 3.95);
    printStudentInfo(head);
    freeList(head);     // Free memory
}