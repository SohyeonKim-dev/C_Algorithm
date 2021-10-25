#ifndef ___BinTree
#define ___BinTree

typedef struct __bnode {
	int data;
	struct __bnode* left;
	struct __bnode* right;
}BinNode ;

BinNode* Search(BinNode* p, const int* x);

BinNode* Add(BinNode* p, const int* x);

int Remove(BinNode** root, const int* x);

void PrintTree(const BinNode* p);

void FreeTree(BinNode* p);


#endif ___BinTree