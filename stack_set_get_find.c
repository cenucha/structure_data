#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
    int data;
    struct elem *next;
} OBJ;

OBJ* push(OBJ *top, int data)
{
    OBJ *ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

void show_stack(OBJ* top)
{
    OBJ* current = top;
    while (current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}

OBJ* pop(OBJ *top)
{
    if (top == NULL) return top;
    OBJ *ptr_next = top->next;
    free(top);
    return ptr_next;
}

int get(OBJ* top, int index)
{
    OBJ* current = top;
    int i = 0;
    while(i != index) {
        current = current->next;
        i++;
    }
    return current->data;
}

void set(OBJ* top, int index, int data)
{
    OBJ* current = top;
    int i = 0;
    while(i != index) {
        current = current->next;
        i++;
    }
    current->data = data;
}

OBJ* find(OBJ* top, int cur_data)
{
    OBJ* current = top;
    while(current->data != cur_data){
        current = current->next;
    }
    return current;
}
int main()
{
    OBJ *top = NULL;

    top = push(top, 1234);
    top = push(top, 1248);
    top = push(top, 1244);
    // show_stack(top);

    // printf("Elem %d: %d\n", 1, get(top, 1));
    set(top, 1, 12345);
    show_stack(top);

    return 0;

}