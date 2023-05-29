#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 31
#define WALL 'H'
#define WAY ' '
#define ANS '*'
#define GOAL 'V'
#define STAR '$'

void create(int x, int y, char a[][MAX]);
void printPuzzle(char a[][MAX]);
int walk(char a[][MAX]);
void buryStar(char map[][MAX]);
void printFlag();
void calculateStar();
void checkGoldFinger(char map[][MAX]);

int playerX = 1;
int playerY = 1;
int num = 0;
int starCounter = 0;

// AIS3JUNIOR_GoldenFinger
// 吃到指定數量以上的$
char flag[] = {41, 35, 85, 86, 52, 23, 118, 10, 34, 126, 44, 17, 30, 60, 68, 113, 83, 14, 8, 76, 63, 48, 2};
char key[] = {104, 106, 6, 101, 126, 66, 56, 67, 109, 44, 115, 86, 113, 80, 32, 20, 61, 72, 97, 34, 88, 85, 112};
int goldFinger[] = {1, 1, 3, 3, 2, 4, 2, 4, 1, 3};
int history[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main()
{
    char puzzle[MAX][MAX];
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
    buryStar(puzzle);

    while (puzzle[MAX - 2][MAX - 2] == GOAL)
    {
        checkGoldFinger(puzzle);
        printPuzzle(puzzle);
        printf("%d\n", starCounter);
        history[(num % 10)] = walk(puzzle);
        system("cls");
    }

    calculateStar();
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

int walk(char map[][MAX])
{
    int offsetX[5] = {0, -1, 0, 1, 0};
    int offsetY[5] = {0, 0, -1, 0, 1};
    int type = 0;
    char way;
    scanf("%c", &way);

    if (way == 'w')
    {
        type = 1;
        num++;
    }
    else if (way == 'a')
    {
        type = 2;
        num++;
    }
    else if (way == 's')
    {
        type = 3;
        num++;
    }
    else if (way == 'd')
    {
        type = 4;
        num++;
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
        if (map[playerX + offsetX[type]][playerY + offsetY[type]] == STAR)
        {
            starCounter++;
        }

        map[playerX][playerY] = WAY;
        playerX += offsetX[type];
        playerY += offsetY[type];
        map[playerX][playerY] = ANS;
    }

    return type;
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

    for (size_t i = 0; i < sizeof(flag); i++)
    {
        char c = flag[i] ^ key[i];
        printf("%c", c);
    }
    printf("\n");
}

void buryStar(char map[][MAX])
{
    int starX = rand() % MAX;
    int starY = rand() % MAX;

    for (size_t i = 0; i < 5; i++)
    {
        while (map[starX][starY] != WAY)
        {
            starX = rand() % MAX;
            starY = rand() % MAX;
        }

        map[starX][starY] = STAR;
    }
}

void calculateStar()
{
    if (starCounter < 11)
    {
        system("cls");
        printf("More Star!\n");
        system("PAUSE");
        exit(0);
    }
}

void checkGoldFinger(char map[][MAX])
{
    for (size_t i = 0; i < 10; i++)
    {
        if (goldFinger[i] != history[i])
        {
            return;
        }
    }

    buryStar(map);
}