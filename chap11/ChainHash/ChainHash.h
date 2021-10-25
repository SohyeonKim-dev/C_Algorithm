#ifndef ___ChainHash
#define ___ChainHash

typedef struct __node {
	int data;
	struct __node* next;
} Node ;

typedef struct {
	int size;
	Node** table;
} ChainHash;

Node* Search(const ChainHash* h, const int* x);

int Add(ChainHash* h, const int* x);

int Remove(ChainHash* h, const int* x);

void Dump(const ChainHash* h);

void Clear(ChainHash* h);

void Terminate(ChainHash* h);


#endif  ___ChainHash
