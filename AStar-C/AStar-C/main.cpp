#include "BinHeap.h"
#include "navigate.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	//unsigned char map[Width*Height] = { 0 };
	char parent[Width*Height] = { 0 };

	Point startPoint, goalPoint;

	bool findFlag = false;
	MapPtr map=NULL;
	/*test*/
	//InitHeap(&open);
	//Node a,b,c,d,e,f,g,h;
	//Node tempNode;
	//a.fValue = 1;
	//b.fValue = 2;
	//c.fValue = 3;
	//d.fValue = 4;
	//e.fValue = 5;
	//f.fValue = 6;
	//g.fValue = 7;
	//h.fValue = 8;
	//
	//InsertElement(open, a);
	//InsertElement(open, b);
	//InsertElement(open, c);
	//InsertElement(open, d);
	//InsertElement(open, e);
	//InsertElement(open, f);
	//InsertElement(open, g);
	//InsertElement(open, h);
	//for (int i = 0; i < 8; i++)
	//{
	//	tempNode = PopMinElement(open);
	//	printf("%d\r\n", tempNode.fValue);
	//}

	/*test end*/

	char *filepath = "C:\\Users\\Arthas\\Desktop\\±ÏÒµÉè¼Æ\\AStar-C\\AStar-C\\mymap.pgm";

	ReadMapFromPgm(filepath, &map);

	//InitMap(map);
	//
	//while (1)
	//{
	//	startPoint.x = rand() % Height;
	//	startPoint.y = rand() % Width;
	//	goalPoint.x = rand() % Height;
	//	goalPoint.y = rand() % Width;
	//	printf("startpoint x:%d,y:%d\t", startPoint.x, startPoint.y);
	//	printf("goalpoint x:%d,y:%d\t", goalPoint.x, goalPoint.y);
	//	if (map[startPoint.y*Width + startPoint.x] == 1 || map[goalPoint.y*Width + goalPoint.x] == 1)
	//	{
	//		printf("target point is on the obstacle!!!!!");
	//		system("pause");
	//		continue;
	//	}

	//	findFlag=AstarNavigate(startPoint, goalPoint, map, parent);

	//	
	//	if (findFlag == false)
	//	{
	//		printf("fail");
	//		//memset(map, 0, sizeof(map));
	//		memset(parent, 0, sizeof(parent));
	//	}
	//	else
	//	{
	//		findFlag = false;
	//		//memset(map, 0, sizeof(map));
	//		memset(parent, 0, sizeof(parent));
	//	}
	//	system("pause");
	//}
		
	
	
}


