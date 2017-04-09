#ifndef NAVIGATE_H_
#define NAVIGATE_H_

#include"BinHeap.h"

bool AstarNavigate(Point startPoint, Point goalPoint,unsigned char *map, char *parent);
int CalcDist(Point start, Point goal);
#endif