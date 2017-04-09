#ifndef BINHEAP_H_
#define BINHEAP_H_


#define MIN_VALUE  -999
#define MAX_SIZE   100000
#define ERROR      -123
#define OK         1

typedef struct PointStruct
{
	int x;
	int y;
}Point;

typedef struct NodeStruct
{
	Point point;
	int gValue;
	int hValue;
	int fValue;
}Node;

typedef struct HeapStruct
{
	Node *ele;
	int curPos;
	int size;
}Heap;

typedef Heap* PtrHeap;

bool InitHeap(PtrHeap *h);
Node PopMinElement(PtrHeap h);
bool InsertElement(PtrHeap h, Node ele);
int ExistElement(PtrHeap h, Node ele);
void ReInitHeap(PtrHeap h);



#endif