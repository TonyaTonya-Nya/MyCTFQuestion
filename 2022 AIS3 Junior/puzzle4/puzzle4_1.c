#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define M 23
#define H 'H'
#define W ' '
#define A '*'
#define G 'V'

void f1(int x, int y, char a[][M]);
void f2(char a[][M]);
void f3(char a[][M]);
void f4(int argc, char *argv[]);
int var1 = 1;
int var2 = 1;

int main(int argc, char *argv[])
{
    char Arrays[M][M];

    f4(argc, argv);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            Arrays[i][j] = H;
        }
    }

    f1(1, 1, Arrays);
    Arrays[var1][var2] = A;

    while (Arrays[M - 2][M - 2] == G)
    {
        f2(Arrays);
        f3(Arrays);
        system("cls");
    }

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

void f3(char arr[][M])
{
    int a5[5] = {0, -1, 0, 1, 0};
    int a6[5] = {0, 0, -1, 0, 1};
    int t = 0;
    char w;
    scanf("%c", &w);

    if (w == 'w')
    {
        t = 1;
    }
    else if (w == 'a')
    {
        t = 2;
    }
    else if (w == 's')
    {
        t = 3;
    }
    else if (w == 'd')
    {
        t = 4;
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
        arr[var1][var2] = W;
        var1 += a5[t];
        var2 += a6[t];
        arr[var1][var2] = A;
    }
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

void f4(int argc, char *argv[])
{
    int s = time(NULL);
    if (argc > 1)
    {
        char *p;
        errno = 0;
        long conv = strtol(argv[1], &p, 10);

        if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN)
        {
            exit(0);
        }
        else
        {
            s = conv;
        }
    }
    srand(s);
}