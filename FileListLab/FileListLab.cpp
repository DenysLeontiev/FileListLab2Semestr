#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#pragma warning(disable:4996)

#define MAX_LEN 100

typedef struct node {
    char data[MAX_LEN];
    struct node* next;
} Node;

Node* Push(Node* top, char* str) {
    Node* new_node = (Node*)malloc(sizeof(Node)); // malloc - dynamic memory allocation and is useful when you don't know the amount of memory needed during compile time
    int i = 0;
    while (str[i] != '\0') {
        new_node->data[i] = str[i];
        i++;
    }
    new_node->data[i] = '\0';
    //memcpy(new_node->data, str, strlen(str) + 1); Second Option to copy
    //strcpy(new_node->data, str);  Third option to copy
    new_node->next = top;
    return new_node;
}

Node* pop(Node* top) {
    if (top == NULL) {
        return NULL;
    }
    Node* temp = top;
    top = top->next;
    free(temp); // deallocates a block of memory previously allocated using calloc, malloc or realloc functions, making it available for further allocations
    return top;
}

void print_and_free_stack(Node* top) {
    //int count = 1;
    while (top != NULL) {
        printf(top->data);
        //printf("%d: %s\n", count, top->data);
        top = pop(top);
        //count++;
    }
}

int main() {
    FILE* fp;
    char filename[MAX_LEN];
    char buffer[MAX_LEN];
    Node* top = NULL;

    printf("Enter filename: "); // you can enter: firstFile.txt
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(buffer, MAX_LEN, fp) != NULL) {
        char* new_str = (char*)malloc(MAX_LEN * sizeof(char));
        sprintf(new_str, "%d: %s", top == NULL ? 1 : atoi(top->data) + 1, buffer);
        top = Push(top, new_str);
    }

    print_and_free_stack(top);

    fclose(fp);

    return 0;
}

