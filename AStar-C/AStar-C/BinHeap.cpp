#include"BinHeap.h"
#include <stdlib.h>
#include<stdio.h>
#include<string.h>

bool InitHeap(PtrHeap *h)
{
	if (*h != nullptr)
	{
		return false;
	}
	(*h) = (PtrHeap)malloc(sizeof(Heap));
	(*h)->size = MAX_SIZE;
	(*h)->ele = (Node *)malloc(((*h)->size)*sizeof(int));
	(*h)->curPos = 0;
	
	return true;
}
Node PopMinElement(PtrHeap h)
{
	int minIndex = 1;
	int childIndex = 0;
	int holeIndex = 0;
	Node lastNode ;
	Node popNode;


	lastNode = h->ele[h->curPos];
	popNode = h->ele[minIndex];
	
	holeIndex = minIndex;
	childIndex = minIndex * 2;

	
	while (childIndex <= h->curPos)
	{
		if (lastNode.fValue < h->ele[childIndex].fValue && lastNode.fValue < h->ele[childIndex + 1].fValue)
		{
			break;
		}
		else
		{
			if ((childIndex < h->curPos) && (h->ele[childIndex].fValue>h->ele[childIndex + 1].fValue))
				childIndex += 1;
			h->ele[holeIndex]= h->ele[childIndex];
			holeIndex = childIndex;
			childIndex = holeIndex * 2;
		}
	}
	h->ele[holeIndex] = lastNode;
	//free(h->ele[h->curPos]);
	h->curPos--;
	
	return popNode;
}
bool InsertElement(PtrHeap h, Node ele)
{
	int i = 0;
	if (h == nullptr)
		return false;
	if (h->curPos == h->size - 1)
	{
		printf("Error:out of size\r\n");
		return false;
	}
	for (i = ++(h->curPos); h->ele[i/2].fValue > ele.fValue; i = i / 2)
	{
		h->ele[i] = h->ele[i / 2];
	}
	h->ele[i] = ele;
	return true;
}

int ExistElement(PtrHeap h, Node ele)
{
	if (h == NULL)
		return 0;
	for (int i = 0; i < h->curPos; i++)
	{
		if (ele.point.x == h->ele[i].point.x&&ele.point.y == h->ele[i].point.y)
		{
			return i;
		}
	}
	return MIN_VALUE;
}

void ReInitHeap(PtrHeap h)
{
	Point initPoint = { 0, 0 };
	Node initNode ;
	initNode.fValue = 0;
	initNode.gValue = 0;
	initNode.hValue = 0;
	initNode.point = initPoint;
	for (int i = 1; i < h->curPos; i++)
	{
		h->ele[i] = initNode;
	}
}