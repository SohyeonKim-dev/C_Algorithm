#ifndef ___LinkedList
#define ___LinkedList

typedef struct __node {
	int data;
	struct __node* next;
} Node;

typedef struct {
	Node* head;
	Node* current;
} List ;

void Initialize(List* list);

Node* search(List* list, const int* x, int compare(const int* x, const int * y));

void InsertFront(List* list, const int * x);

void InsertRear(List* list, const int * x);

void RemoveFront(List* list);

void RemoveRear(List* list);

void RemoveCurrent(List* list);

void Clear(List* list);

void PrintCurrent(const List* list);

void Print(const List* list);

void Terminate(List* list);

#endif ___LinkedList 
