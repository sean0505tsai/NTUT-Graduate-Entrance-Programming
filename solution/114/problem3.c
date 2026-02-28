#include<stdio.h>
#include<stdlib.h>
typedef struct node_s{          /* 3-1: struct */
    int coef;
    int exp;
    struct node_s* next;
}node_t;

typedef node_t * nodep_t;

int count(int num){
    int sum = 0;
    while(num>0){
        sum += num%10;       /* 3-2: %10 */
        num = num/10;
    }
    return sum;
}

nodep_t makeNode(int coef, int exp){
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));    /* 3-3: sizeof(node_t) */
    newNode->next = NULL;
    newNode->coef = coef;
    newNode->exp = exp;
    return newNode;         // 修正: 增加 return newNode，否則會出現錯誤: Illegal instruction (core dumped)
}

void print(nodep_t x){
    while (x!=NULL){
        if(x->coef>0) printf("+");
        if(x->exp==0) printf("%d", x->coef);
        else if(x->exp==1) printf("%dx", x->coef);
        else printf("%dx^%d", x->coef, x->exp);
        x = x->next;
    }
    printf("\n");
}

nodep_t addNode(nodep_t root, nodep_t newNode){
    nodep_t current = root;
    if(current==NULL) return newNode;
    while(current->next!=NULL)
        current = current->next;
    current->next = newNode;         /* 3-4: newNode */
    return root;
}

nodep_t add(nodep_t x, nodep_t y){
    nodep_t root = NULL, newNode = NULL, current = NULL;
    while((x!=NULL) && (y!=NULL)){
        if(x->exp == y->exp){
            newNode = makeNode(x->coef + y->coef, x->exp);    /* 3-5: x->coef + y->coef */
            x = x->next, y = y->next;
        }
        else if(x->exp > y->exp){
            newNode = makeNode(x->coef, x->exp);
            x = x->next;                         /* 3-6: x = x->next */
        }
        else{
            newNode = makeNode(y->coef, y->exp);    /* 3-7: y->coef */
            y = y->next;
        }
        root = addNode(root, newNode);         /* 3-8: root */
    }
    return root;        // 修正: 增加 return root，否則會出現錯誤: Illegal instruction (core dumped)
}

nodep_t make_polynomial(nodep_t root, int data[], int n){
    for(int i=0; i<=n; i++)
        if(data[i]!=0) root = addNode(root, makeNode(data[i], n-i));    /* 3-9: != */
    return root;
}

int main(){
    nodep_t x = NULL, y = NULL, root = NULL, z = NULL;
    int data_x[] = {2, 0, 3, -4, 5};                // 2x^4 + 0x^3 + 3x^2 - 4x + 5
    int data_y[] = {1, 0, 0, 2, 0, 1};             // 1x^5 + 0x^4 + 0x^3 + 2x^2 + 0x + 1
    x = make_polynomial(x, data_x, 4);
    y = make_polynomial(y, data_y, 5);
    print(x);                                      // Output: +2x^4+3x^2-4x+5
    print(y);                                      // Output: +1x^5+2x^2+1
    z = add(x, y);
    print(z);                                      // Output: +1x^5+2x^4+5x^2-4x+6
    printf("%d, %d\n", count(98765), count(1357));    // Output: 35, 16
    return 0;
}