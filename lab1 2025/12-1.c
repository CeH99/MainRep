#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} Type_List;

Type_List* create_list() {
    Type_List *list = (Type_List*)malloc(sizeof(Type_List));
    list->head = NULL;
    return list;
}

void push(Type_List *list, void *data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void print_int_list(Type_List *list) {
    Node *current = list->head;
    while (current) {
        printf("%d -> ", *(int*)(current->data));
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(Type_List *list) {
    Node *current = list->head;
    while (current) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    Type_List *list = create_list();
    int a = 10, b = 20, c = 30;

    push(list, &a);
    push(list, &b);
    push(list, &c);

    print_int_list(list);
    free_list(list);
    return 0;
}
