#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 31
#define H 'H'
#define W ' '
#define A '*'
#define G 'V'
#define STAR '$'

void f1(int x, int y, char a[][M]);
void f2(char a[][M]);
int f3(char a[][M]);
void f5(char a[][M]);
void function4();
void f6();
void f7(char a[][M]);

int var1 = 1;
int var2 = 1;
int num = 0;
int var3 = 0;

char a1[] = {41, 35, 85, 86, 52, 23, 118, 10, 34, 126, 44, 17, 30, 60, 68, 113, 83, 14, 8, 76, 63, 48, 2};
char a2[] = {}; // I wont give you guys this, sor.
int ag[] = {1, 1, 3, 3, 2, 4, 2, 4, 1, 3};
int ah[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main()
{
    char Arrays[M][M];
    srand(time(NULL));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            Arrays[i][j] = H;
        }
    }

    f1(1, 1, Arrays);
    Arrays[var1][var2] = A;
    f5(Arrays);

    while (Arrays[M - 2][M - 2] == G)
    {
        f7(Arrays);
        f2(Arrays);
        printf("%d\n", var3);
        ah[(num % 10)] = f3(Arrays);
        system("cls");
    }

    f6();
    function4();
    system("PAUSE");
}

void f1(int x, int y, char arr[][M])
{
    int a3[4] = {2, 0, -2, 0};
    int a4[4] = {0, -2, 0, 2};

    while (x != M - 2 || y != M - 2)
    {
        int r = rand() % 4;

        while ((x == 1 && r == 2) || (y == 1 && r == 1) || (x == M - 2 && r == 0) || (y == M - 2 && r == 3))
        {
            r = rand() % 4;
        }

        if (arr[x + a3[r]][y + a4[r]] == H)
        {
            arr[x + a3[r]][y + a4[r]] = W;
            arr[x + a3[r] / 2][y + a4[r] / 2] = W;
        }
        x = x + a3[r];
        y = y + a4[r];
    }

    arr[M - 2][M - 2] = G;
}

int f3(char arr[][M])
{
    int a5[5] = {0, -1, 0, 1, 0};
    int a6[5] = {0, 0, -1, 0, 1};
    int t = 0;
    char w;
    scanf("%c", &w);

    if (w == 'w')
    {
        t = 1;
        num++;
    }
    else if (w == 'a')
    {
        t = 2;
        num++;
    }
    else if (w == 's')
    {
        t = 3;
        num++;
    }
    else if (w == 'd')
    {
        t = 4;
        num++;
    }
    else if (w == 'q')
    {
        exit(0);
    }

    if (arr[var1 + a5[t]][var2 + a6[t]] == H)
    {
        printf("No way!\n");
    }
    else
    {
        if (arr[var1 + a5[t]][var2 + a6[t]] == STAR)
        {
            var3++;
        }

        arr[var1][var2] = W;
        var1 += a5[t];
        var2 += a6[t];
        arr[var1][var2] = A;
    }

    return t;
}

void f2(char arr[][M])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

void function4()
{

    for (size_t i = 0; i < sizeof(a1); i++)
    {
        char c = a1[i] ^ a2[i];
        printf("%c", c);
    }
    printf("\n");
}

void f5(char arr[][M])
{
    int starX = rand() % M;
    int starY = rand() % M;

    for (size_t i = 0; i < 5; i++)
    {
        while (arr[starX][starY] != W)
        {
            starX = rand() % M;
            starY = rand() % M;
        }

        arr[starX][starY] = STAR;
    }
}

void f6()
{
    if (var3 < 11)
    {
        system("cls");
        printf("More Star!\n");
        system("PAUSE");
        exit(0);
    }
}

void f7(char arr[][M])
{
    for (size_t i = 0; i < 10; i++)
    {
        if (ag[i] != ah[i])
        {
            return;
        }
    }

    f5(arr);
}