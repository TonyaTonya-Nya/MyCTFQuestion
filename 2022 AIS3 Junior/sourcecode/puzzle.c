#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 31	 // puzzle size, odd only
#define WALL 'H' // wall char
#define WAY ' '	 // wall route
#define ANS '*'	 // player locate
#define GOAL 'V' // goal locate

void create(int x, int y, char a[][MAX]);
void printPuzzle(char a[][MAX]);
void walk(char a[][MAX]);

int playerX = 1;
int playerY = 1;

int main()
{
	char puzzle[MAX][MAX];
	srand(time(NULL));

	// initial wall
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			puzzle[i][j] = WALL;
		}
	}

	create(1, 1, puzzle);
	puzzle[playerX][playerY] = ANS;

	while (puzzle[MAX - 2][MAX - 2] == GOAL)
	{
		printPuzzle(puzzle);
		walk(puzzle);
		system("cls");
	}

	system("PAUSE");
}

void create(int x, int y, char map[][MAX])
{
	int offsetX[4] = {2, 0, -2, 0};
	int offsetY[4] = {0, -2, 0, 2};

	while (x != MAX - 2 || y != MAX - 2)
	{
		int dig_dir = rand() % 4;

		// side limit
		while ((x == 1 && dig_dir == 2) || (y == 1 && dig_dir == 1) || (x == MAX - 2 && dig_dir == 0) || (y == MAX - 2 && dig_dir == 3))
		{
			dig_dir = rand() % 4;
		}

		if (map[x + offsetX[dig_dir]][y + offsetY[dig_dir]] == WALL)
		{
			map[x + offsetX[dig_dir]][y + offsetY[dig_dir]] = WAY;
			map[x + offsetX[dig_dir] / 2][y + offsetY[dig_dir] / 2] = WAY;
		}
		x = x + offsetX[dig_dir];
		y = y + offsetY[dig_dir];
	}

	map[MAX - 2][MAX - 2] = GOAL;
}

void walk(char map[][MAX])
{
	int offsetX[5] = {0, -1, 0, 1, 0};
	int offsetY[5] = {0, 0, -1, 0, 1};
	int type = 0;
	char way;
	scanf("%c", &way);

	if (way == 'w')
	{
		type = 1;
	}
	else if (way == 'a')
	{
		type = 2;
	}
	else if (way == 's')
	{
		type = 3;
	}
	else if (way == 'd')
	{
		type = 4;
	}
	else if (way == 'q')
	{
		exit(0);
	}

	if (map[playerX + offsetX[type]][playerY + offsetY[type]] == WALL)
	{
		printf("No way!\n");
	}
	else
	{
		map[playerX][playerY] = WAY;
		playerX += offsetX[type];
		playerY += offsetY[type];
		map[playerX][playerY] = ANS;
	}
}

void printPuzzle(char map[][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
}