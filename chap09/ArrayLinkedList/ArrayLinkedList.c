#include <stdio.h>
#include <stdlib.h>
#include "ArrayLinkedList.h"

static Index GetIndex(List* list) {
	if (list->deleted == NULL) {
		return ++(list->max);
	}
	else {
		Index rec = list->deleted;
		list->deleted = list->n[rec].free_next;
		return rec;
	}
}


void Initialize(List* list, int size);

Index search(List* list, const int* x, int compare(const int* x, const int* y));

void InsertFront(List* list, const int* x);

void InsertRear(List* list, const int* x);

void RemoveFront(List* list);

void RemoveRear(List* list);

void RemoveCurrent(List* list);

void Clear(List* list);

void PrintCurrent(const List* list);

void Print(const List* list);

void Terminate(List* list);