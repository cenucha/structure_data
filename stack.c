#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
	int data;
	int type;
	struct elem* next;
} ELEM;

ELEM* push(ELEM* top, int data, int type){
	ELEM* ptr = malloc(sizeof(ELEM));
	ptr->data = data;
	ptr->type = type;
	ptr->next = top;
	return ptr;
}

ELEM* pop(ELEM* top){
	if (top == NULL) return top;
	ELEM* ptr_next = top->next;
	free(top);
	return ptr_next;
}

void show_stack(const ELEM* top)
{
	const ELEM* current = top;
	while(current != NULL) {
		printf("%d\n", current->data);
		current = current->next;
	}
}

ELEM* T(const ELEM* top, int type)
{
	ELEM* top_t = NULL;
	const ELEM* current = top;
	while(current != NULL) {
		if (current->type == type) {
		ELEM *ptr = malloc(sizeof(ELEM));
		ptr->data = current->data;
		ptr->type = current->type;
			ptr->next = top_t;
			top_t = ptr;
		}

		current = current->next;
	}
	return top_t;
}


int main()
{
	ELEM* top = NULL;
	top = push(top, 1, 1);
	top = push(top, 2, 2);
	top = push(top, 3, 1);
	top = push(top, 4, 2);
	
	
	ELEM *top_1= T(top, 1);
	show_stack(top_1);
	
	ELEM *top_2= T(top, 2);
	show_stack(top_2);

	return 0;
}
