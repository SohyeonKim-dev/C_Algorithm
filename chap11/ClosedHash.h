#ifndef ___ClosedHash
#define ___ClosedHash

typedef enum {
	Occupied, Empty, Deleted
} Status ;

typedef struct {
	int data;
	Status stat;
} Bucket;

typedef struct {
	int size;
	Bucket* table;
} ClosedHash;

int Initialize(ClosedHash* h, int size);

Bucket* Search(const ClosedHash* h, const int* x);

int Add(ClosedHash* h, const int* x);

int Remove(ClosedHash* h, const int* x);

void Dump(const ClosedHash* h);

void Clear(ClosedHash* h);

void Terminate(ClosedHash* h);


#endif ___ClosedHash