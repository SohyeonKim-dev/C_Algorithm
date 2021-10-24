#ifndef ___CircDblLinkedList
#define ___CircDblLinkedList

typedef struct __node  {	//태그(임시 이름, 자기 참조 구조체)
	int data;
	struct __node* prev;
	struct __node* next;
} Dnode;

typedef struct {
	Dnode* head;
	Dnode* current;
} Dlist ; // 자기 참조 구조체가 아니므로, 태그 필요 없다.

void Initialize(Dlist* list);

void PrintCurrent(const Dlist* list);

Dnode* search(Dlist* list, const int* x,	int compare(const int* x, const int* y));

void Print(const Dlist* list);

void PrintReverse(const Dlist* list);

int Next(Dlist* list);

int Prev(Dlist* list);

void InsertAfter(Dlist* list, Dnode* p, const int* x);

void InsertFront(Dlist* list, const int* x);

void InsertRear(Dlist* list, const int* x);

void Remove(Dlist* list, Dnode* p);

void RemoveFront(Dlist* list);

void RemoveRear(Dlist* list);

void RemoveCurrent(Dlist* list);

void Clear(Dlist* list);

void Terminate(Dlist* list);

#endif ___CircDblLinkedList