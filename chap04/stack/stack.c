#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int Initialize(IntStack* s, int max) {
	s->firstStack = 0;
	if ((s->firstStack = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

int Push(IntStack* s, int x) {
	if (s->ptr >= s->max) {
		return -1;
	}
	s->firstStack[s->ptr++] = x;
	return 0;
}

int Pop(IntStack* s, int* x) {
	if (s->ptr <= 0) {
		return -1;
	}
	*x = s->firstStack[s->ptr--];
	return 0;
}

int Peek(const IntStack* s, int* x) {
	if (s->ptr <= 0) {
		return -1;
	}
	*x = s->firstStack[s->ptr - 1];
	return 0;
}

void Clear(IntStack* s) {
	s->ptr = 0;
}

int Capacity(const IntStack* s) {
	return s->max;
}

int Size(const IntStack* s) {
	return s->ptr;
}

int IsEmpty(const IntStack* s) {
	return s->ptr <= 0;
}

int IsFull(const IntStack* s) {
	return s->ptr >= s->max;
}

int Search(const IntStack* s, int x) {
	int i;
	for (i = s->ptr - 1;i >= 0; i--) {
		if (s->firstStack[i] == x) {
			return i;
		}
	}
	return -1;
}

void Print(const IntStack* s) {
	int i;
	for (i = 0;i < s->ptr;i++) {
		printf("%d ", s->firstStack[i]);
	}
	putchar('\n');
}

void Terminate(IntStack* s) {
	if (s->firstStack != NULL) {
		free(s->firstStack);
	}
	s->max = 0;
	s->ptr = 0;
}