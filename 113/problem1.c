#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int studentID;
    double GPA;
    /* Problem 1-1 */
} Student_t;

void printStudentInfo(Student_t *current) {
    while (current != NULL) {
        printf(" ID: %d, GPA: %.2f\n", current->studentID, current->GPA);
        current = current->next;
    }
}

Student_t* addStudent(Student_t* head, int studentID, double GPA) {
    Student_t* newStudent = (Student_t*)malloc(sizeof(Student_t));
    
    if ( /* Problem 1-2 */ ) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newStudent->studentID = studentID;
    newStudent->GPA = GPA;
    /* Problem 1-3 */;
    return newStudent;
}

void freeList(Student_t *head) {
    while (head != NULL) {
        /* Problem 1-4 */;
        free(current);
        head = head->next;
    }
}

void main() {
    /* Problem 1-5 */;
    head = addStudent(head, 112590001, 3.75);
    head = addStudent(head, 112590025, 3.80);
    head = addStudent(head, 112590011, 3.95);
    printStudentInfo(head);
    freeList(head);     // Free memory
}