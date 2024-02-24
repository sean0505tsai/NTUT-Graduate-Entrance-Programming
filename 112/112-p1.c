#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node_t;
typedef node_t* nodep_t;

nodep_t createNode(int value){
    nodep_t p=(nodep_t) malloc(sizeof(node_t));
    p->data = value;
    p->left = p->right = NULL/*1-1*/;          /* Problem 1-1 */
    return p;
}
    
void build(nodep_t current, nodep_t newNode, int value){
    nodep_t parent;
    while(1){
        parent = current;
        if(value < parent->data){
            current = current->left;
            if(current == NULL){
                parent->left/*1-2*/ = newNode;      /* Problem 1-2 */
                return;
            }
        }
        else{
            current = current->right;
            if(current == NULL){
                parent->right/*1-3*/ = newNode;     /* Problem 1-3 */
                return;
            }
        }
    }
}

nodep_t insert(int value, nodep_t root){
    nodep_t current, parent, newNode;
    newNode = createNode(value);
    if(root == NULL){
        root = newNode;
    }
    else{
        parent = current = root/*1-4*/;        /* Problem 1-4 */
        build(current, newNode, value);
    }
    return root;
}

void inorder_traversal(nodep_t root){
    if(root != NULL){
        inorder_traversal(root->left/*1-5*/);        /* Problem 1-5 */
        printf("%d ", root->data);
        inorder_traversal(root->right/*1-6*/);        /* Problem 1-6 */
    }
}

int main(){
    nodep_t root = NULL;
    int array[] = {23, 12, 43, 21, 65, 3, 2};
    for(int i = 0; i < 7; i++){
        root = insert(array[i], root);
    }        
    inorder_traversal(root);
    return 0;
}
