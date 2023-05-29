#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 31
#define H 'H'
#define W ' '
#define A '*'
#define G 'V'

void function1(int x, int y, char a[][M]);
void function2(char a[][M]);
void function3(char a[][M]);
void f4();

int var1 = 1;
int var2 = 1;

char a1[] = {88, 73, 51, 32, 71, 5, 33, 2, 97, 12, 107, 119, 113, 96, 61};
char a2[] = {}; // I wont give you guys this, sor.

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

    function1(1, 1, Arrays);
    Arrays[var1][var2] = A;

    while (Arrays[M - 2][M - 2] == G)
    {
        function2(Arrays);
        function3(Arrays);
        system("cls");
    }

    f4();
    system("PAUSE");
}

void function1(int x, int y, char arr[][M])
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

void function3(char arr[][M])
{
    int a5[5] = {0, -1, 0, 1, 0};
    int a6[5] = {0, 0, -1, 0, 1};
    int t = 0;
    char w;
    scanf("%c", &w);

    if (w == ((a1[0] + 32) ^ (a1[5] + 28)))
    {
        t = 1;
    }
    else if (w == ((a1[1] + 3) ^ (a1[3] - 22)))
    {
        t = 2;
    }
    else if (w == ((a1[9] - 11) ^ (a1[12] - 34)))
    {
        t = 3;
    }
    else if (w == ((a1[2] - 14) ^ (a1[14] + 44)))
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

void function2(char arr[][M])
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

void f4()
{
    for (size_t i = 0; i < sizeof(a1); i++)
    {
        char c = a1[i] ^ a2[i];
        printf("%c", c);
    }
    printf("\n");
}