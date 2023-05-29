#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 31
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
// AIS3JUNIOR_easy
// 找到四個按鍵在迷宮移動
char flag[] = {88, 73, 51, 32, 71, 5, 33, 2, 97, 12, 107, 119, 113, 96, 61};
char key[] = {25, 0, 96, 19, 13, 80, 111, 75, 46, 94, 52, 18, 16, 19, 68};

int main()
{
    char puzzle[MAX][MAX];
    char hint[] = "No one knows I use YFNL move it ><\n";
    printf("%s", hint);
    system("cls");

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

    if (way == ((flag[0] + 32) ^ (flag[5] + 28)))
    {
        type = 1;
    }
    else if (way == ((flag[1] + 3) ^ (flag[3] - 22)))
    {
        type = 2;
    }
    else if (way == ((flag[9] - 11) ^ (flag[12] - 34)))
    {
        type = 3;
    }
    else if (way == ((flag[2] - 14) ^ (flag[14] + 44)))
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

    for (size_t i = 0; i < sizeof(flag); i++)
    {
        char c = flag[i] ^ key[i];
        printf("%c", c);
    }
    printf("\n");
}