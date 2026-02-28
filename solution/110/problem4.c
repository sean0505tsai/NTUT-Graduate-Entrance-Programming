#include<stdio.h>
#include<stdlib.h>
typedef struct Node { int data; struct Node* next; } NODE;

int showTop(NODE* top){
    return top->data;
}

void pushStack(_____ top, int data){               // Problem 4-1
    NODE* node;
    
    node = (_____) malloc(sizeof(NODE));          // Problem 4-2
    if(node == NULL){
        printf("Memory allocation failure!\n");
        exit(1);
    }
    node->data = data;
    node->next = *top;
    *top = node;
}

void showStack(NODE* top){
    NODE* node = *top;
    while(node != NULL){
        printf("%d ", node->data);
        node = __________;                     // Problem 4-3
    }
    printf("\n");
}