#ifndef MAP_H_
#define MAP_H_

#define Width 300
#define Height 300


typedef struct TwdStruct
{
	int x;
	int y;
	int cost;
}Twd;

typedef struct MapStruct
{
	int width;
	int height;
	unsigned char *mapData;
}Map;

typedef Map* MapPtr;

void InitMap(unsigned char* map);
bool ReadMapFromPgm(char* filepath, MapPtr* mapPointer);


#endif