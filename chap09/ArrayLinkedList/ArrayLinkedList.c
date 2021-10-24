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

static void DeleteIndex(List* list, Index idx){
	if (list->deleted == NULL) {      
		list->deleted = idx;
		list->n[idx].free_next = NULL;
	}
	else {
		Index ptr = list->deleted;
		list->deleted = idx;
		list->n[idx].free_next = ptr;
	}
}


static void SetNode(Node* n, const int * x, Index next) {
	n->data = *x;
	n->next = next;
}


void Initialize(List* list, int size) {
	list->n = calloc(size, sizeof(Node));
	list->head = NULL;
	list->current = NULL;			
	list->max = NULL;
	list->deleted = NULL;
}

Index search(List* list, const int* x, int compare(const int* x, const int* y)) {
	Index ptr = list->head;
	while (ptr != NULL) {
		if (compare(&list->n[ptr].data, x) == 0) {
			list->current = ptr;
			return ptr;
		}
		ptr = list->n[ptr].next;
	}
	return NULL;
}

void InsertFront(List* list, const int* x) {
	Index ptr = list->head;
	list->current = GetIndex(list);
	list->head = list->current;
	SetNode(&list->n[list->head], x, ptr);
}

void InsertRear(List* list, const int* x) {
	if (list->head = NULL) {
		InsertFront(list, x);
	}
	else {
		Index ptr = list->head;
		while (list->n[ptr].next != NULL) {
			ptr = list->n[ptr].next;
		}
		list->current = GetIndex(list);
		list->n[ptr].next = list->current;
		SetNode(&list->n[list->n[ptr].next], x, NULL);
	}
}

void RemoveFront(List* list) {
	if (list->head != NULL) {
		Index ptr = list->n[list->head].next;
		DeleteIndex(list, list->head);
		list->head = list->current = ptr;
	}
}

void RemoveRear(List* list) {
	if (list->head != NULL) {
		if (list->n[list->head].next == NULL) {
			RemoveFront(list);
		}
		else {
			Index ptr = list->head;
			Index pre;
			while (list->n[ptr].next != NULL) {
				pre = ptr;
				ptr = list->n[ptr].next;
			}
			list->n[pre].next = NULL;
			DeleteIndex(list, ptr);
			list->current = pre;
		}
	}
}

void RemoveCurrent(List* list) {
	if (list->head != NULL) {
		if (list->current == list->head) {
			RemoveFront(list);
		}
							
		else {
			Index ptr = list->head;
			while (list->n[ptr].next != list->current) {
				ptr = list->n[ptr].next;
			}
			list->n[ptr].next = list->n[list->current].next;
			DeleteIndex(list, list->current);
			list->current = ptr;
		}
	}
}

void Clear(List* list) {
	while (list->head != NULL) {
		RemoveFront(list);
	}
	list->current = NULL;
}

void PrintCurrent(const List* list) {
	if (list->current == NULL) {
		printf("주목노드가 없습니다.");
	}
	else {
		PrintMember(&list->n[list->current].data);
	}
}

void Print(const List* list) {
	if (list->head == NULL) {
		puts("노드가 없습니다.");
	}
	else {
		Index ptr = list->head;
		puts("【 모두 보기 】");
		while (ptr != NULL) {
			PrintLnMember(&list->n[ptr].data); // member 포함X 수정 need
			ptr = list->n[ptr].next;
		}
	}
}

void Terminate(List* list) {
	Clear(list);
	free(list->n);
}

/*

함수 printf( )
문자열 및 다양한 정보를 서식화 하여 출력하는 함수다. 
puts는 단순히 문자열만을 출력하는데 그쳤다면, printf는 문자열뿐만 아니라 정수, 실수, 문자를 출력할 수 있다.

*/