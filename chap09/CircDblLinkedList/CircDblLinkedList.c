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

// ���� �� �Լ��� ������Ͽ� �������� �ʴ� ����: ĸ��ȭ�� ����
// �ҽ� �������� ����ϱ� ���Ͽ�, ������ �Լ��̴�. 
// main (���� ����), �� ����ڿ��� ������ �ʿ伺 X -> ���� ��(main �� �巯���� ����)

void Initialize(Dlist* list) {
	Dnode* dummynode = AllocDNode();
	list->current = dummynode;
	list->head = list->current;

	dummynode->next = dummynode;
	dummynode->prev = dummynode;
}

void PrintCurrent(const Dlist* list) {
	if (IsEmpty(list)) {
		puts("�ָ��尡 �����ϴ�.");
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
		puts("��尡 �����ϴ�.");
	}
	else {
		Dnode* ptr = list->head->next;
		puts("�� ��� ���� ��");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

void PrintReverse(const Dlist* list) {
	if (IsEmpty(list)) {
		puts("��尡 �����ϴ�.");
	}
	else {
		Dnode* ptr = list->head->prev; //�����̶� �̰� ������ ����̴ϱ�. 
		puts("�� ��� ���� ��");
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