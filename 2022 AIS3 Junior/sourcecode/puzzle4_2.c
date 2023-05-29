#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 23
#define WALL 'H'
#define WAY ' '
#define ANS '*'
#define GOAL 'V'

void create(int x, int y, char a[][MAX]);
void printPuzzle(char a[][MAX]);
void walk(char a[][MAX]);
void printFlag();

int playerX = 1;
int playerY = 1;
// AIS3JUNIOR_Blind_LOL
// 盲走迷宮 0w0
char flag[] = {77, 105, 26, 13, 47, 44, 108, 66, 48, 14, 123, 52, 76, 38, 30, 27, 84, 118, 99, 54};
char key[] = {12, 32, 73, 62, 101, 121, 34, 11, 127, 92, 36, 118, 32, 79, 112, 127, 11, 58, 44, 122};

int main()
{
    char puzzle[MAX][MAX];
    srand(0x79979);

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
        walk(puzzle);
    }

    printFlag();
    system("PAUSE");
}

void create(int x, int y, char map[][MAX])
{
    int offsetX[4] = {2, 0, -2, 0};
    int offsetY[4] = {0, -2, 0, 2};

    while (x != MAX - 2 || y != MAX - 2)
    {
        int dig_dir = rand() % 4;

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
        printf("oops...U die.\n");
        system("PAUSE");
        exit(0);
    }
    else
    {
        map[playerX][playerY] = WAY;
        playerX += offsetX[type];
        playerY += offsetY[type];
        map[playerX][playerY] = ANS;
    }
}

void printFlag()
{

    for (size_t i = 0; i < sizeof(flag); i++)
    {
        char c = flag[i] ^ key[i];
        printf("%c", c);
    }
    printf("\n");
}