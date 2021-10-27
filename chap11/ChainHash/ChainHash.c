#include <stdio.h>
#include <stdlib.h>
#include "ChainHash.h"

static int hash(int key, int size) {
	return key % size;	// 나머지를 해시 값으로 반환
}

static void SetNode(Node* n, const int* x, const Node* next)
{
	n->data = *x;				
	n->next = next;				
}

int initialize(ChainHash* h, int size) {
	if ((h->table = calloc(size, sizeof(Node*))) == NULL) {
		h->size = 0;
		return 0;
	}

	h->size = size;
	for (int i = 0; i < size; i++) {
		h->table[i] = NULL;
	}
	
	return 1;
}

Node* Search(const ChainHash* h, const int* x) {
	int key = hash(x, h->size);
	Node* p = h->table[key];

	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

int Add(ChainHash* h, const int* x) {
	int key = hash(x, h->size);
	Node* p = h->table[key];
	Node* temp;

	while (p != NULL) {
		if (p->data == x) {
			return 1;
		}
		p = p->next;
	}
	
	if ((temp = calloc(1, sizeof(Node))) == NULL) {
		return 2;
	}

	SetNode(temp, x, h->table[key]);
	h->table[key] = temp;

	return 0;
}

int Remove(ChainHash* h, const int* x) {
	int key = hash(x, h->size);
	Node* p = h->table[key];
	Node** pp = &h->table[key];

	while (p != NULL) {
		if (p->data == x) {
			*pp = p->next;
			free(p);
			return 0;
		}
		pp = &p->next;
		p = p->next;
	}
	return 1;
}

void Dump(const ChainHash* h) {
	for (int i = 0; i < h->table[i]; i++) {
		Node* p = h->table[i];
		printf("%02d ", i);

		while (p != NULL) {
			//printf("→ %d :(%s) ", p->data.no, p->data.name);
			p = p->next;
		}
		putchar('\n');
	}
}

void Clear(ChainHash* h) {
	for (int i = 0; i < h->size;i++) {
		Node* p = h->table[i];

		while (p != NULL) {
			Node* next = p->next;
			free(p);
			p = next;
		}
		h->table[i] = NULL;
	}
}

void Terminate(ChainHash* h) {
	Clear(h);
	free(h->table);
	h->size = 0;
}