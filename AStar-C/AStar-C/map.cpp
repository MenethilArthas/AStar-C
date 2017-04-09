#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "map.h"


void InitMap(unsigned char* map)
{
	if (map == NULL)
		return;
	//初始化地图，生成障碍物
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5000; i++)
	{
		int obsRow = rand() % Height;
		int obsCol = rand() % Width;
		map[obsCol*Width + obsRow] = 1;
	}
}

bool ReadMapFromPgm(char* filepath, MapPtr* mapPointer)
{
	int width = 0, height = 0;
	FILE *fp = fopen(filepath, "r");
	char temp[10], c_width[10], c_height[10], maxvalue[10];

	int white = 0;
	int grey = 0;
	int black = 0;

	if (filepath == NULL)
		return false;	

	*mapPointer = (MapPtr)malloc(sizeof(Map));


	fscanf(fp, "%s %s %s %s", temp, c_width, c_height, maxvalue);
	for (int i = 0; c_width[i] != '\0'; ++i)
	{
		width = width * 10 + c_width[i] - '0';
	}
	for (int i = 0; c_height[i] != '\0'; ++i)
	{
		height = height * 10 + c_height[i] - '0';
	}
	(*mapPointer)->height = height;
	(*mapPointer)->width = width;
	(*mapPointer)->mapData = (unsigned char *)malloc(sizeof(unsigned char)*(width*height));
	unsigned char value;
	value = fgetc(fp);									// 第一个值都是10，可以忽略
	for (int i = 0; i < height*width; ++i)						
	{
		value = fgetc(fp);
		(*mapPointer)->mapData[i] = value;

	}
	fclose(fp);
	return false;
}