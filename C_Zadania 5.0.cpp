#include <stdio.h>
#include <corecrt_malloc.h>

typedef struct node {
    int val;
    struct node* next;
} node_t;

void print_list(node_t* head) 
{
    node_t* current = head;
    int licznik = 0;

    while (current != NULL) 
    {
        if (licznik % 10 == 0)
        {
            printf("\n");
            licznik = 0;
        }
        printf("%d\t", current->val);
        current = current->next;
        licznik++;
    }
    printf("\n");
    for (int i = 0; i < licznik * 7; i++)
    {
        printf("-");
    }
    printf("\n\n");
}

void push(node_t* head, int val) 
{
    node_t* current = head;
    while (current->next != NULL) 
    {
        current = current->next;
    }

    current->next = (node_t*)malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void add_first(node_t** head, int val)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t)); // nowy węzeł
    if (new_node == NULL) 
    {
        printf("Błąd alokacji pamięci!\n");
        return;
    }

    new_node->val = val; 
    new_node->next = *head; // Nowy węzeł wskazuje na obecny główny węzeł

    *head = new_node; // Ustawiamy nowy węzeł jako główny węzeł
}

void pop(node_t** head) // remove_first
{
    if (*head == NULL) 
    {
        printf("Lista jest pusta, nie ma elementu do usunięcia.\n");
        return;
    }

    node_t* pierwszy = *head; // wskaźnik do pierwszego elementu
    *head = (*head)->next; // Przesuwamy główny węzeł na kolejny element
    free(pierwszy); // Zwolnienie pamięci zaalokowanej dla poprzedniego pierwszego elementu
}

void remove_last(node_t** head)
{
    if (*head == NULL) 
    {
        printf("Lista jest pusta, nie ma elementu do usunięcia.\n");
        return;
    }

    // Jeśli lista ma tylko jeden element
    if ((*head)->next == NULL) 
    {
        free(*head);
        *head = NULL;
        return;
    }

    node_t* current = *head;
    node_t* previous = NULL;

    while (current->next != NULL) 
    {
        previous = current;
        current = current->next;
    }

    free(current); // Usuwamy ostatni element
    previous->next = NULL;
}

void remove_by_index(node_t** head, int index)
{
    node_t* current = *head;
    node_t* previous = NULL;
    int licznik = 0;

    while (current->next != NULL && licznik < index) 
    {
        previous = current;
        current = current->next;
        licznik++;
    }
    previous->next = current->next; //przypisanie poprzedniemu adresu NEXT dla następnego elementu
    free(current);
}

void remove_value(node_t** head, int value)
{
    node_t* current = *head;
    node_t* previous = NULL;
    if (current != NULL && current->val == value)
    {
        *head = current->next; // zmiana atrybutu head na drugi element
        free(current);
        return;
    }
    while (current != NULL)
    {
        if (current->val == value)
        {
            previous->next = current->next; //przypisanie poprzedniemu adresu NEXT dla następnego elementu
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void add_value_at_index(node_t** head, int value, int index)
{
    node_t* current = *head;
    node_t* previous = NULL;
    for (int i = 0; i < index; i++)
    {
        if (current == NULL)
        {
            printf("Nie mozna dodac wartosci na tym indeksie!");
        }
        previous = current;
        current = current->next;
    }
    if (current != NULL) // jeśli coś jest na tym indeksie
    {
        node_t* new_node = (node_t*)malloc(sizeof(node_t)); // nowy węzeł
        if (new_node == NULL)
        {
            printf("Błąd alokacji pamięci!\n");
            return;
        }

        new_node->val = value;
        new_node->next = current; // Nowy węzeł wskazuje na obecny główny węzeł
        previous->next = new_node;
    }
    else
    {
        node_t* new_node = (node_t*)malloc(sizeof(node_t)); // nowy węzeł
        if (new_node == NULL)
        {
            printf("Błąd alokacji pamięci!\n");
            return;
        }
        new_node->val = value;
        new_node->next = NULL;
        previous->next = new_node;
    }
}


int main()
{
    node_t* head = NULL;
    head = (node_t*)malloc(sizeof(node_t));
    if (head == NULL) 
    {
        return 1;
    }

    head->val = 1;
    head->next = NULL;

    printf("-----Twoja lista-----\n");
    push(head, 1); push(head, 16);
    push(head, 4); push(head, 7); push(head, 2); push(head, 13); //dodanie kilku elementów
    print_list(head); // wyświetlenie listy

    printf("-----Dodanie elementow na poczatku-----\n");
    add_first(&head, 88); // dodanie elementu na początek listy
    add_first(&head, 17);
    print_list(head);

    printf("-----Usuniecie pierwszego elementu-----\n");
    pop(&head); // usunięcie elementu na pierwszym miejscu
    print_list(head);

    printf("-----Usuniecie ostatniego elementu-----\n");
    remove_last(&head); // usunięcie elementu na pierwszym miejscu
    print_list(head);

    printf("-----Usuniecie 3-ego elementu-----\n");
    remove_by_index(&head, 2); // usunięcie elementu na pierwszym miejscu
    print_list(head);

    printf("-----Usuniecie wartosci 7-----\n");
    remove_value(&head, 7); // usunięcie elementu na pierwszym miejscu
    print_list(head);

    printf("-----Dodanie wartosci 99 na miejscu 5-----\n");
    add_value_at_index(&head, 99, 4); // usunięcie elementu na pierwszym miejscu
    print_list(head);

    return 0;
}
