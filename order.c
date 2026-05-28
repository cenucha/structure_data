#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	int id;
	char name[50];
	double rating;
	int mark;
	struct student* next;
} STUD;

void AddElement(STUD **first, STUD **last, int id, char name[50], double rating, int mark) {
	STUD *q = malloc(sizeof(STUD));
	if (q == NULL) {
		fprintf(stderr, "Ошибка выделения памяти\n");
		return;
	}

	q->id = id;
	strcpy(q->name, name);
	q->rating = rating;
	q->mark = mark;
	q->next = NULL;

	if (*first == NULL) {
		*first = q;
		*last = q;
		return;
	}


	if (rating > (*first)->rating) {
		q->next = *first;
		*first = q;
		return;
	}

	STUD *current = *first;
	while (current->next != NULL && current->next->rating >= rating) {
		current = current->next;
	}

	q->next = current->next;
	current->next = q;

	if (q->next == NULL) {
		*last = q;
	}
}

void show_queue(STUD *first) {
	STUD* current = first;
	while (current != NULL) {
		printf("%d %s %lf\n", current->id, current->name, current->rating);
		current = current->next;
	}
}

void free_queue(STUD **first) {
	STUD *current = *first;
	STUD *next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
}

void pop_queue(STUD **first, STUD **last)
{
	STUD *current = *first;
	*first = (*first)->next;
	free(current);
	if (*first == NULL) {
		*last = NULL;
	}
}

int main() {
	STUD *first = NULL;
	STUD *last = NULL;

	AddElement(&first, &last, 1, "Ksenia", 3, 5);
	AddElement(&first, &last, 2, "Sofia", 4, 1);
	AddElement(&first, &last, 3, "Maria", 6, 6);

	show_queue(first);
	pop_queue(&first, &last);
	printf("Delete \n");
	show_queue(first);


	return 0;
}

