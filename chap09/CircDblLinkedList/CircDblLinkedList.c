#include <stdio.h>
#include <stdlib.h>
#include "CircDblLinkedList.h"

static Dnode* AllocDNode(void) {
	return calloc(1, sizeof(Dnode));
}

static void SetDNode(Dnode* n, const int* x, const Dnode* prev, const Dnode* next) {
	n->data = *x;
	n->prev = prev;
	n->next = next;
}

static int IsEmpty(const Dlist* list) {
	return list->head->next == list->head;
}

// 위의 세 함수를 헤더파일에 선언하지 않는 이유: 캡슐화와 연관
// 소스 내에서만 사용하기 위하여, 정의한 함수이다. 
// main (실행 파일), 즉 사용자에게 전달할 필요성 X -> 감춘 것(main 상에 드러나지 않음)

void Initialize(Dlist* list) {
	Dnode* dummynode = AllocDNode();
	list->current = dummynode;
	list->head = list->current;

	dummynode->next = dummynode;
	dummynode->prev = dummynode;
}

void PrintCurrent(const Dlist* list) {
	if (IsEmpty(list)) {
		puts("주목노드가 없습니다.");
	}
	else {
		PrintMember(&list->current->data);
	}
}

Dnode* search(Dlist* list, const int* x, int compare(const int* x, const int* y)) {
	Dnode* ptr = list->head->next;
	while (ptr != list->head) {
		if (compare(&ptr->data, x) == 0) {
			list->current = ptr;
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

void Print(const Dlist* list) {
	if (IsEmpty(list)) {
		puts("노드가 없습니다.");
	}
	else {
		Dnode* ptr = list->head->next;
		puts("【 모두 보기 】");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

void PrintReverse(const Dlist* list) {
	if (IsEmpty(list)) {
		puts("노드가 없습니다.");
	}
	else {
		Dnode* ptr = list->head->prev; //원형이라 이게 마지막 노드이니까. 
		puts("【 모두 보기 】");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->prev;
		}
	}
		
}

int Next(Dlist* list) {
	if (IsEmpty(list) || list->current->data == list->head) {
		return 0;
	}

	list->current = list->current->next;
	return 1;
}

int Prev(Dlist* list) {
	if (IsEmpty(list) || list->current->prev == list->head) {
		return 0;
	}
	list->current = list->current->prev;
	return 1;
}

void InsertAfter(Dlist* list, Dnode* p, const int* x) {
	Dnode* ptr = AllocDNode();
	Dnode* nxt = p->next;
	p->next->prev = ptr;
	p->next = p->next->prev;
	SetDNode(ptr, x, p, nxt);
	list->current = ptr;
}

void InsertFront(Dlist* list, const int* x) {
	InsertAfter(list, list->head, x);
}

void InsertRear(Dlist* list, const int* x) {
	InsertAfter(list, list->head->prev, x);
}

void Remove(Dlist* list, Dnode* p) {
	p->prev->next = p->next;
	p->next->prev = p->prev;
	list->current = p->prev;
	free(p);

	if (list->current == list->head) {
		list->current = list->head->next;
	}
}

void RemoveFront(Dlist* list) {
	if (!IsEmpty(list)) {
		Remove(list, list->head->next);
	}
}

void RemoveRear(Dlist* list) {
	if (!IsEmpty(list)) {
		Remove(list, list->head->prev);
	}
}

void RemoveCurrent(Dlist* list) {
	if (list->current != list->head) {
		Remove(list, list->current);
	}
}

void Clear(Dlist* list) {
	while (IsEmpty(list)) {
		RemoveFront(list);
	}
}

void Terminate(Dlist* list) {
	Clear(list);
	free(list->head);
}