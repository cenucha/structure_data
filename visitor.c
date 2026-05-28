#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct visitor {
    int id;
    char name[50];
    int dress_number;
    struct visitor *next;
} VIS;


void AddElement(VIS **first, VIS **last, int id, char name[50], int dress_number)
{
    VIS *ptr = malloc(sizeof(VIS));
    ptr->id = id;
    strcpy(ptr->name, name);
    ptr->dress_number = dress_number;
    ptr->next = NULL;

    if (*first == NULL)
    {
        *first = ptr;
        *last = ptr;
    }
    else
    {
        (*last)->next = ptr;
        *last = ptr; 
    }
}

void show_order(VIS *first) {
    VIS *current = first;
    while(current != NULL)
    {
        printf("%d %s %d\n", current->id, current->name, current->dress_number);
        current = current->next;
    }

}

void pop_queue(VIS **first, VIS **last)
{
	VIS *current = *first;
	*first = (*first)->next;
	free(current);
	if (*first == NULL) {
		*last = NULL;
	}
}

void pop_full(VIS **first)
{
    VIS *current = *first;
	VIS *next;
	while (current != NULL) {
        printf("Picks up things: %d %s %d\n", current->id, current->name, current->dress_number);
		next = current->next;
		free(current);
		current = next;
	}

    *first = NULL;
	
}

int main(void)
{
    VIS *first = NULL;
    VIS *last = NULL;

    AddElement(&first, &last, 1, "John", 10);
    AddElement(&first, &last, 2, "Mary", 12);
    show_order(first);
    pop_full(&first);

    return 0;

}