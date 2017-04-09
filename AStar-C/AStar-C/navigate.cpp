#include"navigate.h"
#include"BinHeap.h"
#include"map.h"
#include <stdlib.h>
bool AstarNavigate(Point startPoint,Point goalPoint,unsigned char *map,char *parent)
{

	char closed[Width*Height] = { 0 };
	PtrHeap open = nullptr;
	Node startNode;
	Node tmpNode;
	Node popNode;
	int row = 0, col = 0;
	int nodeIndex = 0;

	Twd twds[8] = { { 0, -1, 10 },
					{ 0, 1, 10 },
					{ -1, 0, 10 },
					{ 1, 0, 10 },
					{ -1, -1, 14 },
					{ 1, -1, 14 },
					{ -1, 1, 14 },
					{ 1, 1, 14 }, };


	InitHeap(&open);
	startNode.point = startPoint;
	startNode.gValue = 0;
	startNode.hValue = CalcDist(startPoint, goalPoint);
	startNode.fValue = startNode.gValue + startNode.hValue;
	InsertElement(open, startNode);

	while (open->curPos != 0 )
	{
		popNode = PopMinElement(open);
		closed[popNode.point.y*Width + popNode.point.x] = 1;
		for (int i = 0; i < 8; i++)
		{
			row = popNode.point.x + twds[i].x;
			col = popNode.point.y + twds[i].y;
			//在地图内部
			if (row >= 0 && row <= Width && col >= 0 && col <= Height)
			{
				//不是障碍物且不在closed里
				if (closed[col * Width + row] != 1 && map[col * Width + row] != 1)
				{
					if (row != goalPoint.x || col != goalPoint.y)
					{
						tmpNode.point.x = row;
						tmpNode.point.y = col;
						tmpNode.gValue = popNode.gValue + twds[i].cost;
						tmpNode.hValue = CalcDist(tmpNode.point, goalPoint);
						tmpNode.fValue = tmpNode.gValue + tmpNode.hValue;

						nodeIndex = ExistElement(open, tmpNode);
						if (nodeIndex != MIN_VALUE)
						{
							if (open->ele[nodeIndex].fValue > tmpNode.fValue)
							{
								open->ele[nodeIndex].fValue = tmpNode.fValue;
								parent[tmpNode.point.y * Width + tmpNode.point.x] = popNode.point.y * Width + popNode.point.x;
							}
						}
						else
						{
							InsertElement(open, tmpNode);
							parent[tmpNode.point.y * Width + tmpNode.point.x] = popNode.point.y * Width + popNode.point.x;
						}
					}
					else
					{						
						return true;
					}
				}
			}
		}
	}
	return false;

}

int CalcDist(Point start, Point goal)
{
	int disX = abs(start.x - goal.x) * 10;
	int disY = abs(start.y - goal.y) * 10;
	return disX + disY;
}