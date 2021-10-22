#ifndef ___ArrayLinkedList
#define ___ArrayLinkedList

#define NULL	-1
typedef int Index;

typedef struct {
	int data;
	Index next;
	Index free_next;
} Node ;

typedef struct {
	Node* n;
	Index head;
	Index max;
	Index deleted;
	Index current;
}List;

void Initialize(List* list, int size);

Index search(List* list, const int* x,int compare(const int* x, const int* y));

void InsertFront(List* list, const int* x);

void InsertRear(List* list, const int* x);

void RemoveFront(List* list);

void RemoveRear(List* list);

void RemoveCurrent(List* list);

void Clear(List* list);

void PrintCurrent(const List* list);

void Print(const List* list);

void Terminate(List* list);

#endif ___ArrayLinkedList