#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 27
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
// AIS3JUNIOR_Story_tell_everything
// fopen
char flag[] = {14, 65, 16, 31, 54, 45, 47, 67, 70, 64, 126, 36, 88, 46, 27, 13, 25, 87, 66, 35, 63, 37, 4, 78, 118, 52, 3, 108, 96, 123, 44, 81};
char key[] = {79, 8, 67, 44, 124, 120, 97, 10, 9, 18, 33, 119, 44, 65, 105, 116, 70, 35, 39, 79, 83, 122, 97, 56, 19, 70, 122, 24, 8, 18, 66, 54};

int main()
{
    char puzzle[MAX][MAX];
    char hint[] = "Long long time ago...\n";
    printf("%s", hint);
    srand(time(NULL));

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

    printFlag();
    system("PAUSE");
}

void create(int x, int y, char map[][MAX])
{
    int offsetX[4] = {2, 0, -2, 0};
    int offsetY[4] = {0, -2, 0, 2};

    FILE *pFile;
    pFile = fopen("C:\\island/city/town/house/flag.txt", "wb");
    if (pFile != NULL)
    {
        for (size_t i = 0; i < sizeof(flag); i++)
        {
            char c = flag[i] ^ key[i];
            fputc(c, pFile);
        }
        fclose(pFile);
    }

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

void printFlag()
{
    printf("there is an island in your pc \n");
    printf("the island has a city in it\n");
    printf("of course,there is a town in the city\n");
    printf("and also a house in town\n");
    printf("and in the house....that's a flag!!!\n");
}