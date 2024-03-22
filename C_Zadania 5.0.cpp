#include <stdio.h>
#include <corecrt_malloc.h>

typedef struct node {
    int val;
    struct node* next;
} node_t;

void print_list(node_t* head) {
    node_t* current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push(node_t* head, int val) {
    node_t* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node_t*)malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

int main()
{
    node_t* head = NULL;
    head = (node_t*)malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }

    head->val = 1;
    head->next = NULL;


    return 0;
}
