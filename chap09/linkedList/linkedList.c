#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

static Node* AllocNode(void)
{
	return calloc(1, sizeof(Node));
}

static void SetNode(Node* n, const int* x, const Node* next)
{
	n->data = *x;		
	n->next = next;		
}

void Initialize(List* list) {
	list->head = NULL;
	list->current = NULL;
}

Node* search(List* list, const int* x, int compare(const int* x, const int* y)) {
	Node* ptr = list->head;

	while (ptr != NULL) {
		if (compare(&ptr->data, x) == 0) {
			list->current = ptr;
			return ptr; //success
		}
		ptr = ptr->next;
	}
	return NULL; // failed 
}

void InsertFront(List* list, const int* x) {
	Node* ptr = list->head;
	list->current = AllocNode();
	list->head = list->current;
	SetNode(list->head, x, ptr);
	// ������ ��带 ���� �����ͷ� ����Ų��. 
}

void InsertRear(List* list, const int* x) {
	if (list->head == NULL) {
		InsertFront(list, x);
	}
	else {
		Node* ptr = list->head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		list->current = AllocNode;
		ptr->next = list->current;
		SetNode(ptr->next, x, NULL);
	}
}

void RemoveFront(List* list) {
	if (list->head != NULL) {
		Node* ptr = list->head->next;
		free(list->head);
		list->current = ptr;
		list->head = list->current;
	}
}

void RemoveRear(List* list) {
	if (list->head != NULL) {
		if (list->head->next == NULL) {
			RemoveFront(list);
		}
		else {
			Node* ptr = list->head;
			Node* pre = NULL;
			while (ptr->next != NULL) {
				pre = ptr;
				ptr = ptr->next;
			}
			ptr->next = NULL;
			free(ptr);
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
			Node* ptr = list->head;
			while (ptr->next != list->current) {
				ptr = ptr->next;
			}
			ptr->next = list->current->next;
			free(list->current);
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
		printf("������ ��尡 �����ϴ�.");
	}
	else {
		PrintMember(&list->current->data);
		//��� ���/�ҽ� �����ؼ� ���� �ʿ���
	}
}

void Print(const List* list) {
	if (list->head == NULL) {
		puts("��尡 �����ϴ�.");
	}
	else {
		Node* ptr = list->head;
		puts("[ ��� ���� ]");
		while (ptr != NULL) {
			PrintCurrent(list);
			ptr = ptr->next;
		}
	}
}

void Terminate(List* list) {
	Clear(list);
}
