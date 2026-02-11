#include<stdio.h>
#include<stdlib.h>
#define NUM_OF_QUIZ 3

typedef struct Student{
    char id[10];
    char name[30];
    float grade;
    int quizs[NUM_OF_QUIZ];
}STUDENT;

float calculate_grade_as_quiz_average(__________ student){  /* Problem 3-1 */
    float sum=0;
    for(int i=0; i<NUM_OF_QUIZ; i++){
        sum=sum+__________;                                 /* Problem 3-2 */
    }
    return (float)sum/NUM_OF_QUIZ;
}

void descending_sort_by_grade(STUDENT students[], int numOfStudents){
    STUDENT tempStudent;
    int i, j;
    for(i=0; i<numOfStudents; i++)
        for(j=0; j<__________; j++)                           /* Problem 3-3 */
            if(students[j].grade<__________){                 /* Problem 3-4 */
                tempStudent=students[j+1];
                students[j+1]=students[j];
                students[j]=tempStudent;
            }
}

int main(void){
    int numOfStudents;
    STUDENT students[]={{"t011", "John", 0.0, {80, 85, 70}},
                        {"t020", "Eric", 0.0, {90, 95, 80}},
                        {"t022", "Mary", 0.0, {90, 95, 90}},
                        {"t003", "Apple", 0.0, {90, 85, 80}}};

    numOfStudents=sizeof(__________)/sizeof(students[0]);              /* Problem 3-5 */
    for(int i=0; i<numOfStudents; i++){
        students[i].grade=calculate_grade_as_quiz_average(__________);  /* Problem 3-6 */
    }

    descending_sort_by_grade(students, numOfStudents);

    for(int i=0; i<numOfStudents; i++){
        printf("%s\t%s\t%.2f", students[i].id, students[i].name, students[i].grade);
        for(int j=0; j<NUM_OF_QUIZ; j++){
            printf("\t%d", __________);                                      /* Problem 3-7 */
        printf("\n");
        }
    }
    return 0;
}