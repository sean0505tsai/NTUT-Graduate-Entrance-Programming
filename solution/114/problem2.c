#include<stdio.h>
#include<stdlib.h>
#define SIZE 26
int comp(char* s, char* d){
    if((*s=='\0')&&(*d=='\0')) return 0;
    else if ((*s=='\0')||(*s<*d)) return -1;
    else if ((*d=='\0')||(*s>*d)) return 1;
    else return comp(s+1,d+1);
}

// To initialize the statistic table of alphabet letters - "alpha table".
void init_alpha_table(int* alpha_table){
    for(int i=0;i<SIZE;i++) alpha_table[i]=0;
}

// To convert the characters of string "buf" into lowercase
void lowercase(char* buf){
    for(int i=0;buf[i]!='\0';i++)
        if('A'<=buf[i] && buf[i]<='Z')       /* 2-1: 確認buf[i]是否為大寫字母 */
            buf[i] = 'a' + buf[i] - 'A';     /* 2-2: 將大寫字母轉換為小寫字母 */
}

// To count the number of characters c in the string "data".
int alpha_count(char data[], char c){
    int total = 0;
    for(int i=0; data[i]!='\0'; i++)
        if(data[i] == c) total+=1;          /* 2-3: 當data[i]等於c時，將total加1 */
    return total;
}

// Count the frequency of alphabet letters in the string "buf", and store in "alpha_table".
void count_Freq(char buf[], int alpha_table[]){
    for(int i=0; i<SIZE; i++){
        alpha_table[i] = alpha_count(buf, ('a'+ i));    /* 2-4: 將buf中各字母的出現次數存入alpha_table */
    }
}

// To get the value stored in the "alpha_table", the vlaue is the number of "specific_c".
int get_num_alpha_table(int* alpha_table, char specific_c){
    int index = specific_c - 'a';                        /* 2-5: 計算specific_c在alpha_table中的索引 */
    return alpha_table[index];
}

int main(void){
    int alpha_table[SIZE];
    char buf[] = "2024NtUtCsie";
    init_alpha_table(alpha_table);
    printf("%d\n", alpha_count(buf, '2'));                // Output: 2
    lowercase(buf);
    printf("%s\n", buf);                             // Output: 2024ntutcsie
    count_Freq(buf, alpha_table);
    printf("%d\n", get_num_alpha_table(alpha_table, 't'));  // Output: 2
    printf("%d\n", get_num_alpha_table(alpha_table, 'n'));  // Output: 1
    printf("%d\n", get_num_alpha_table(alpha_table, 'c'));  // Output: 1
    printf("%d\n", alpha_count("book_is_good", 'o'));       /* 2-6: 4 */
    printf("%d, %d\n", comp("FO", "FOO"), comp("FO", "FO"));  /* 2-7: -1, 0 */
    printf("%d, %d\n", comp("FOOD", "FOOAD"), comp("", ""));  /* 2-8: 1, 0 */
}