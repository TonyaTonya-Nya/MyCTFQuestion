#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 31
#define H 'H'
#define W ' '
#define A '*'
#define G 'V'

void f1(int x, int y, char a[][M]);
void f2(char a[][M]);
void f3(char a[][M]);
void f4();
void f5(int n);

int var1 = 1;
int var2 = 1;
int num = 0;


// I made a mistake, maybe counter will have some problems...

char a1[] = {56, 14, 22, 27, 83, 9, 113, 116, 106, 1, 120, 25, 37, 115, 41, 66, 60, 101, 76, 45, 55, 105, 85, 34, 70};
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

    f1(1, 1, Arrays);
    Arrays[var1][var2] = A;

    while (Arrays[M - 2][M - 2] == G)
    {
        f2(Arrays);
        printf("%d\n", num);
        f3(Arrays);
        f5(++num);
        system("cls");
    }

    f4();
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

void f5(int n)
{
    if (n == 0)
    {
        a1[10] = 75;
    }
    else if (n == 1)
    {
        a1[19] = 91;
    }
    else if (n == 2)
    {
        a1[18] = 113;
    }
    else if (n == 3)
    {
        a1[18] = 53;
    }
    else if (n == 4)
    {
        a1[18] = 20;
    }
    else if (n == 5)
    {
        a1[18] = 39;
    }
    else if (n == 6)
    {
        a1[14] = 80;
    }
    else if (n == 7)
    {
        a1[18] = 100;
    }
    else if (n == 8)
    {
        a1[15] = 0;
    }
    else if (n == 9)
    {
        a1[5] = 57;
    }
    else if (n == 10)
    {
        a1[10] = 46;
    }
    else if (n == 11)
    {
        a1[18] = 100;
    }
    else if (n == 12)
    {
        a1[12] = 88;
    }
    else if (n == 13)
    {
        a1[16] = 44;
    }
    else if (n == 14)
    {
        a1[21] = 95;
    }
    else if (n == 15)
    {
        a1[5] = 21;
    }
    else if (n == 16)
    {
        a1[9] = 115;
    }
    else if (n == 17)
    {
        a1[7] = 9;
    }
    else if (n == 18)
    {
        a1[0] = 123;
    }
    else if (n == 19)
    {
        a1[22] = 84;
    }
    else if (n == 20)
    {
        a1[22] = 20;
    }
    else if (n == 21)
    {
        a1[11] = 51;
    }
    else if (n == 22)
    {
        a1[4] = 98;
    }
    else if (n == 23)
    {
        a1[13] = 29;
    }
    else if (n == 24)
    {
        a1[10] = 121;
    }
    else if (n == 25)
    {
        a1[17] = 28;
    }
    else if (n == 26)
    {
        a1[19] = 75;
    }
    else if (n == 27)
    {
        a1[21] = 33;
    }
    else if (n == 28)
    {
        a1[24] = 35;
    }
    else if (n == 29)
    {
        a1[0] = 38;
    }
    else if (n == 30)
    {
        a1[2] = 119;
    }
    else if (n == 31)
    {
        a1[6] = 80;
    }
    else if (n == 32)
    {
        a1[4] = 38;
    }
    else if (n == 33)
    {
        a1[2] = 73;
    }
    else if (n == 34)
    {
        a1[12] = 105;
    }
    else if (n == 35)
    {
        a1[14] = 122;
    }
    else if (n == 36)
    {
        a1[16] = 93;
    }
    else if (n == 37)
    {
        a1[14] = 108;
    }
    else if (n == 38)
    {
        a1[0] = 6;
    }
    else if (n == 39)
    {
        a1[4] = 7;
    }
    else if (n == 40)
    {
        a1[16] = 17;
    }
    else if (n == 41)
    {
        a1[7] = 107;
    }
    else if (n == 42)
    {
        a1[15] = 27;
    }
    else if (n == 43)
    {
        a1[1] = 64;
    }
    else if (n == 44)
    {
        a1[8] = 72;
    }
    else if (n == 45)
    {
        a1[1] = 82;
    }
    else if (n == 46)
    {
        a1[21] = 44;
    }
    else if (n == 47)
    {
        a1[13] = 58;
    }
    else if (n == 48)
    {
        a1[17] = 17;
    }
    else if (n == 49)
    {
        a1[5] = 124;
    }
    else if (n == 50)
    {
        a1[19] = 89;
    }
    else if (n == 51)
    {
        a1[9] = 21;
    }
    else if (n == 52)
    {
        a1[9] = 111;
    }
    else if (n == 53)
    {
        a1[23] = 126;
    }
    else if (n == 54)
    {
        a1[21] = 24;
    }
    else if (n == 55)
    {
        a1[23] = 43;
    }
    else if (n == 56)
    {
        a1[21] = 94;
    }
    else if (n == 57)
    {
        a1[0] = 105;
    }
    else if (n == 58)
    {
        a1[13] = 30;
    }
    else if (n == 59)
    {
        a1[22] = 122;
    }
    else if (n == 60)
    {
        a1[1] = 64;
    }
    else if (n == 61)
    {
        a1[10] = 82;
    }
    else if (n == 62)
    {
        a1[1] = 22;
    }
    else if (n == 63)
    {
        a1[14] = 33;
    }
    else if (n == 64)
    {
        a1[24] = 25;
    }
    else if (n == 65)
    {
        a1[15] = 76;
    }
    else if (n == 66)
    {
        a1[17] = 105;
    }
    else if (n == 67)
    {
        a1[3] = 82;
    }
    else if (n == 68)
    {
        a1[5] = 71;
    }
    else if (n == 69)
    {
        a1[10] = 44;
    }
    else if (n == 70)
    {
        a1[8] = 95;
    }
    else if (n == 71)
    {
        a1[17] = 99;
    }
    else if (n == 72)
    {
        a1[17] = 95;
    }
    else if (n == 73)
    {
        a1[11] = 79;
    }
    else if (n == 74)
    {
        a1[5] = 21;
    }
    else if (n == 75)
    {
        a1[24] = 83;
    }
    else if (n == 76)
    {
        a1[1] = 63;
    }
    else if (n == 77)
    {
        a1[21] = 64;
    }
    else if (n == 78)
    {
        a1[22] = 76;
    }
    else if (n == 79)
    {
        a1[11] = 49;
    }
    else if (n == 80)
    {
        a1[10] = 48;
    }
    else if (n == 81)
    {
        a1[1] = 72;
    }
    else if (n == 82)
    {
        a1[14] = 22;
    }
    else if (n == 83)
    {
        a1[3] = 2;
    }
    else if (n == 84)
    {
        a1[13] = 15;
    }
    else if (n == 85)
    {
        a1[15] = 98;
    }
    else if (n == 86)
    {
        a1[5] = 122;
    }
    else if (n == 87)
    {
        a1[23] = 98;
    }
    else if (n == 88)
    {
        a1[22] = 31;
    }
    else if (n == 89)
    {
        a1[18] = 73;
    }
    else if (n == 90)
    {
        a1[22] = 68;
    }
    else if (n == 91)
    {
        a1[12] = 93;
    }
    else if (n == 92)
    {
        a1[17] = 44;
    }
    else if (n == 93)
    {
        a1[9] = 0;
    }
    else if (n == 94)
    {
        a1[24] = 31;
    }
    else if (n == 95)
    {
        a1[22] = 106;
    }
    else if (n == 96)
    {
        a1[0] = 59;
    }
    else if (n == 97)
    {
        a1[23] = 26;
    }
    else if (n == 98)
    {
        a1[21] = 8;
    }
    else if (n == 99)
    {
        a1[22] = 100;
    }
    else if (n == 100)
    {
        a1[10] = 122;
    }
    else if (n == 101)
    {
        a1[7] = 93;
    }
    else if (n == 102)
    {
        a1[3] = 19;
    }
    else if (n == 103)
    {
        a1[11] = 73;
    }
    else if (n == 104)
    {
        a1[18] = 53;
    }
    else if (n == 105)
    {
        a1[2] = 25;
    }
    else if (n == 106)
    {
        a1[7] = 87;
    }
    else if (n == 107)
    {
        a1[3] = 31;
    }
    else if (n == 108)
    {
        a1[9] = 25;
    }
    else if (n == 109)
    {
        a1[18] = 24;
    }
    else if (n == 110)
    {
        a1[3] = 7;
    }
    else if (n == 111)
    {
        a1[10] = 83;
    }
    else if (n == 112)
    {
        a1[16] = 33;
    }
    else if (n == 113)
    {
        a1[22] = 68;
    }
    else if (n == 114)
    {
        a1[4] = 28;
    }
    else if (n == 115)
    {
        a1[17] = 35;
    }
    else if (n == 116)
    {
        a1[1] = 54;
    }
    else if (n == 117)
    {
        a1[23] = 97;
    }
    else if (n == 118)
    {
        a1[11] = 77;
    }
    else if (n == 119)
    {
        a1[16] = 112;
    }
    else if (n == 120)
    {
        a1[11] = 60;
    }
    else if (n == 121)
    {
        a1[12] = 18;
    }
    else if (n == 122)
    {
        a1[16] = 40;
    }
    else if (n == 123)
    {
        a1[14] = 105;
    }
    else if (n == 124)
    {
        a1[17] = 17;
    }
    else if (n == 125)
    {
        a1[8] = 13;
    }
    else if (n == 126)
    {
        a1[7] = 28;
    }
    else if (n == 127)
    {
        a1[23] = 41;
    }
    else if (n == 128)
    {
        a1[8] = 103;
    }
    else if (n == 129)
    {
        a1[10] = 114;
    }
    else if (n == 130)
    {
        a1[17] = 106;
    }
    else if (n == 131)
    {
        a1[14] = 63;
    }
    else if (n == 132)
    {
        a1[2] = 87;
    }
    else if (n == 133)
    {
        a1[8] = 84;
    }
    else if (n == 134)
    {
        a1[6] = 62;
    }
    else if (n == 135)
    {
        a1[8] = 11;
    }
    else if (n == 136)
    {
        a1[18] = 94;
    }
    else if (n == 137)
    {
        a1[16] = 125;
    }
    else if (n == 138)
    {
        a1[20] = 69;
    }
    else if (n == 139)
    {
        a1[13] = 80;
    }
    else if (n == 140)
    {
        a1[14] = 18;
    }
    else if (n == 141)
    {
        a1[6] = 92;
    }
    else if (n == 142)
    {
        a1[21] = 2;
    }
    else if (n == 143)
    {
        a1[11] = 101;
    }
    else if (n == 144)
    {
        a1[19] = 45;
    }
    else if (n == 145)
    {
        a1[20] = 121;
    }
    else if (n == 146)
    {
        a1[24] = 48;
    }
    else if (n == 147)
    {
        a1[12] = 98;
    }
    else if (n == 148)
    {
        a1[16] = 59;
    }
    else if (n == 149)
    {
        a1[0] = 98;
    }
    else if (n == 150)
    {
        a1[21] = 17;
    }
    else if (n == 151)
    {
        a1[4] = 48;
    }
    else if (n == 152)
    {
        a1[13] = 85;
    }
    else if (n == 153)
    {
        a1[4] = 119;
    }
    else if (n == 154)
    {
        a1[18] = 21;
    }
    else if (n == 155)
    {
        a1[5] = 13;
    }
    else if (n == 156)
    {
        a1[9] = 83;
    }
    else if (n == 157)
    {
        a1[0] = 20;
    }
    else if (n == 158)
    {
        a1[23] = 82;
    }
    else if (n == 159)
    {
        a1[13] = 89;
    }
    else if (n == 160)
    {
        a1[10] = 100;
    }
    else if (n == 161)
    {
        a1[2] = 1;
    }
    else if (n == 162)
    {
        a1[6] = 90;
    }
    else if (n == 163)
    {
        a1[8] = 116;
    }
    else if (n == 164)
    {
        a1[1] = 125;
    }
    else if (n == 165)
    {
        a1[23] = 17;
    }
    else if (n == 166)
    {
        a1[17] = 62;
    }
    else if (n == 167)
    {
        a1[19] = 83;
    }
    else if (n == 168)
    {
        a1[4] = 102;
    }
    else if (n == 169)
    {
        a1[23] = 124;
    }
    else if (n == 170)
    {
        a1[18] = 35;
    }
    else if (n == 171)
    {
        a1[20] = 1;
    }
    else if (n == 172)
    {
        a1[24] = 127;
    }
    else if (n == 173)
    {
        a1[20] = 57;
    }
    else if (n == 174)
    {
        a1[23] = 58;
    }
    else if (n == 175)
    {
        a1[10] = 70;
    }
    else if (n == 176)
    {
        a1[2] = 15;
    }
    else if (n == 177)
    {
        a1[0] = 29;
    }
    else if (n == 178)
    {
        a1[11] = 6;
    }
    else if (n == 179)
    {
        a1[8] = 83;
    }
    else if (n == 180)
    {
        a1[16] = 38;
    }
    else if (n == 181)
    {
        a1[1] = 111;
    }
    else if (n == 182)
    {
        a1[8] = 109;
    }
    else if (n == 183)
    {
        a1[5] = 105;
    }
    else if (n == 184)
    {
        a1[23] = 15;
    }
    else if (n == 185)
    {
        a1[15] = 30;
    }
    else if (n == 186)
    {
        a1[2] = 120;
    }
    else if (n == 187)
    {
        a1[20] = 11;
    }
    else if (n == 188)
    {
        a1[7] = 70;
    }
    else if (n == 189)
    {
        a1[7] = 88;
    }
    else if (n == 190)
    {
        a1[1] = 8;
    }
    else if (n == 191)
    {
        a1[9] = 79;
    }
    else if (n == 192)
    {
        a1[0] = 36;
    }
    else if (n == 193)
    {
        a1[1] = 91;
    }
    else if (n == 194)
    {
        a1[4] = 109;
    }
    else if (n == 195)
    {
        a1[6] = 89;
    }
    else if (n == 196)
    {
        a1[18] = 56;
    }
    else if (n == 197)
    {
        a1[22] = 123;
    }
    else if (n == 198)
    {
        a1[17] = 59;
    }
    else if (n == 199)
    {
        a1[3] = 49;
    }
    else if (n == 200)
    {
        a1[24] = 0;
    }
    else if (n == 201)
    {
        a1[17] = 54;
    }
    else if (n == 202)
    {
        a1[1] = 73;
    }
    else if (n == 203)
    {
        a1[18] = 77;
    }
    else if (n == 204)
    {
        a1[9] = 111;
    }
    else if (n == 205)
    {
        a1[11] = 18;
    }
    else if (n == 206)
    {
        a1[8] = 15;
    }
    else if (n == 207)
    {
        a1[7] = 6;
    }
    else if (n == 208)
    {
        a1[12] = 73;
    }
    else if (n == 209)
    {
        a1[6] = 9;
    }
    else if (n == 210)
    {
        a1[6] = 107;
    }
    else if (n == 211)
    {
        a1[11] = 26;
    }
    else if (n == 212)
    {
        a1[22] = 36;
    }
    else if (n == 213)
    {
        a1[16] = 47;
    }
    else if (n == 214)
    {
        a1[16] = 102;
    }
    else if (n == 215)
    {
        a1[18] = 64;
    }
    else if (n == 216)
    {
        a1[5] = 66;
    }
    else if (n == 217)
    {
        a1[16] = 87;
    }
    else if (n == 218)
    {
        a1[14] = 87;
    }
    else if (n == 219)
    {
        a1[6] = 81;
    }
    else if (n == 220)
    {
        a1[15] = 82;
    }
    else if (n == 221)
    {
        a1[23] = 78;
    }
    else if (n == 222)
    {
        a1[11] = 18;
    }
    else if (n == 223)
    {
        a1[12] = 21;
    }
    else if (n == 224)
    {
        a1[16] = 61;
    }
    else if (n == 225)
    {
        a1[0] = 66;
    }
    else if (n == 226)
    {
        a1[18] = 87;
    }
    else if (n == 227)
    {
        a1[6] = 127;
    }
    else if (n == 228)
    {
        a1[22] = 67;
    }
    else if (n == 229)
    {
        a1[20] = 82;
    }
    else if (n == 230)
    {
        a1[18] = 70;
    }
    else if (n == 231)
    {
        a1[14] = 71;
    }
    else if (n == 232)
    {
        a1[24] = 62;
    }
    else if (n == 233)
    {
        a1[14] = 85;
    }
    else if (n == 234)
    {
        a1[17] = 36;
    }
    else if (n == 235)
    {
        a1[1] = 117;
    }
    else if (n == 236)
    {
        a1[4] = 20;
    }
    else if (n == 237)
    {
        a1[18] = 10;
    }
    else if (n == 238)
    {
        a1[18] = 60;
    }
    else if (n == 239)
    {
        a1[10] = 67;
    }
    else if (n == 240)
    {
        a1[5] = 112;
    }
    else if (n == 241)
    {
        a1[7] = 110;
    }
    else if (n == 242)
    {
        a1[2] = 58;
    }
    else if (n == 243)
    {
        a1[4] = 91;
    }
    else if (n == 244)
    {
        a1[20] = 76;
    }
    else if (n == 245)
    {
        a1[0] = 14;
    }
    else if (n == 246)
    {
        a1[5] = 109;
    }
    else if (n == 247)
    {
        a1[7] = 13;
    }
    else if (n == 248)
    {
        a1[4] = 119;
    }
    else if (n == 249)
    {
        a1[18] = 98;
    }
    else if (n == 250)
    {
        a1[16] = 105;
    }
    else if (n == 251)
    {
        a1[12] = 62;
    }
    else if (n == 252)
    {
        a1[22] = 7;
    }
    else if (n == 253)
    {
        a1[24] = 26;
    }
    else if (n == 254)
    {
        a1[24] = 58;
    }
    else if (n == 255)
    {
        a1[17] = 46;
    }
    else if (n == 256)
    {
        a1[14] = 6;
    }
    else if (n == 257)
    {
        a1[14] = 116;
    }
    else if (n == 258)
    {
        a1[12] = 91;
    }
    else if (n == 259)
    {
        a1[7] = 53;
    }
    else if (n == 260)
    {
        a1[1] = 69;
    }
    else if (n == 261)
    {
        a1[13] = 67;
    }
    else if (n == 262)
    {
        a1[7] = 0;
    }
    else if (n == 263)
    {
        a1[11] = 75;
    }
    else if (n == 264)
    {
        a1[24] = 105;
    }
    else if (n == 265)
    {
        a1[11] = 43;
    }
    else if (n == 266)
    {
        a1[13] = 42;
    }
    else if (n == 267)
    {
        a1[4] = 120;
    }
    else if (n == 268)
    {
        a1[19] = 25;
    }
    else if (n == 269)
    {
        a1[16] = 21;
    }
    else if (n == 270)
    {
        a1[13] = 70;
    }
    else if (n == 271)
    {
        a1[13] = 61;
    }
    else if (n == 272)
    {
        a1[4] = 123;
    }
    else if (n == 273)
    {
        a1[3] = 6;
    }
    else if (n == 274)
    {
        a1[22] = 53;
    }
    else if (n == 275)
    {
        a1[20] = 109;
    }
    else if (n == 276)
    {
        a1[16] = 73;
    }
    else if (n == 277)
    {
        a1[2] = 63;
    }
    else if (n == 278)
    {
        a1[21] = 92;
    }
    else if (n == 279)
    {
        a1[0] = 98;
    }
    else if (n == 280)
    {
        a1[4] = 61;
    }
    else if (n == 281)
    {
        a1[1] = 18;
    }
    else if (n == 282)
    {
        a1[7] = 63;
    }
    else if (n == 283)
    {
        a1[13] = 88;
    }
    else if (n == 284)
    {
        a1[21] = 33;
    }
    else if (n == 285)
    {
        a1[9] = 75;
    }
    else if (n == 286)
    {
        a1[8] = 76;
    }
    else if (n == 287)
    {
        a1[24] = 59;
    }
    else if (n == 288)
    {
        a1[23] = 118;
    }
    else if (n == 289)
    {
        a1[16] = 61;
    }
    else if (n == 290)
    {
        a1[2] = 4;
    }
    else if (n == 291)
    {
        a1[2] = 81;
    }
    else if (n == 292)
    {
        a1[19] = 45;
    }
    else if (n == 293)
    {
        a1[11] = 32;
    }
    else if (n == 294)
    {
        a1[14] = 117;
    }
    else if (n == 295)
    {
        a1[8] = 108;
    }
    else if (n == 296)
    {
        a1[12] = 103;
    }
    else if (n == 297)
    {
        a1[12] = 43;
    }
    else if (n == 298)
    {
        a1[7] = 37;
    }
    else if (n == 299)
    {
        a1[22] = 84;
    }
    else if (n == 300)
    {
        a1[5] = 92;
    }
    else if (n == 301)
    {
        a1[10] = 112;
    }
    else if (n == 302)
    {
        a1[2] = 93;
    }
    else if (n == 303)
    {
        a1[17] = 24;
    }
    else if (n == 304)
    {
        a1[15] = 17;
    }
    else if (n == 305)
    {
        a1[1] = 92;
    }
    else if (n == 306)
    {
        a1[20] = 64;
    }
    else if (n == 307)
    {
        a1[13] = 91;
    }
    else if (n == 308)
    {
        a1[24] = 55;
    }
    else if (n == 309)
    {
        a1[9] = 92;
    }
    else if (n == 310)
    {
        a1[24] = 112;
    }
    else if (n == 311)
    {
        a1[12] = 57;
    }
    else if (n == 312)
    {
        a1[21] = 4;
    }
    else if (n == 313)
    {
        a1[6] = 93;
    }
    else if (n == 314)
    {
        a1[19] = 52;
    }
    else if (n == 315)
    {
        a1[24] = 103;
    }
    else if (n == 316)
    {
        a1[5] = 121;
    }
    else if (n == 317)
    {
        a1[5] = 95;
    }
    else if (n == 318)
    {
        a1[18] = 74;
    }
    else if (n == 319)
    {
        a1[22] = 1;
    }
    else if (n == 320)
    {
        a1[3] = 84;
    }
    else if (n == 321)
    {
        a1[8] = 67;
    }
    else if (n == 322)
    {
        a1[13] = 15;
    }
    else if (n == 323)
    {
        a1[5] = 66;
    }
    else if (n == 324)
    {
        a1[17] = 49;
    }
    else if (n == 325)
    {
        a1[5] = 5;
    }
    else if (n == 326)
    {
        a1[24] = 86;
    }
    else if (n == 327)
    {
        a1[18] = 53;
    }
    else if (n == 328)
    {
        a1[11] = 56;
    }
    else if (n == 329)
    {
        a1[8] = 47;
    }
    else if (n == 330)
    {
        a1[3] = 110;
    }
    else if (n == 331)
    {
        a1[3] = 58;
    }
    else if (n == 332)
    {
        a1[11] = 66;
    }
    else if (n == 333)
    {
        a1[15] = 89;
    }
    else if (n == 334)
    {
        a1[5] = 27;
    }
    else if (n == 335)
    {
        a1[16] = 32;
    }
    else if (n == 336)
    {
        a1[16] = 82;
    }
    else if (n == 337)
    {
        a1[22] = 31;
    }
    else if (n == 338)
    {
        a1[21] = 65;
    }
    else if (n == 339)
    {
        a1[23] = 99;
    }
    else if (n == 340)
    {
        a1[16] = 105;
    }
    else if (n == 341)
    {
        a1[1] = 88;
    }
    else if (n == 342)
    {
        a1[6] = 26;
    }
    else if (n == 343)
    {
        a1[7] = 76;
    }
    else if (n == 344)
    {
        a1[0] = 116;
    }
    else if (n == 345)
    {
        a1[10] = 10;
    }
    else if (n == 346)
    {
        a1[7] = 72;
    }
    else if (n == 347)
    {
        a1[24] = 56;
    }
    else if (n == 348)
    {
        a1[10] = 112;
    }
    else if (n == 349)
    {
        a1[24] = 95;
    }
    else if (n == 350)
    {
        a1[4] = 119;
    }
    else if (n == 351)
    {
        a1[23] = 61;
    }
    else if (n == 352)
    {
        a1[7] = 6;
    }
    else if (n == 353)
    {
        a1[7] = 63;
    }
    else if (n == 354)
    {
        a1[7] = 126;
    }
    else if (n == 355)
    {
        a1[3] = 21;
    }
    else if (n == 356)
    {
        a1[19] = 28;
    }
    else if (n == 357)
    {
        a1[8] = 1;
    }
    else if (n == 358)
    {
        a1[6] = 62;
    }
    else if (n == 359)
    {
        a1[16] = 57;
    }
    else if (n == 360)
    {
        a1[11] = 20;
    }
    else if (n == 361)
    {
        a1[14] = 17;
    }
    else if (n == 362)
    {
        a1[0] = 95;
    }
    else if (n == 363)
    {
        a1[0] = 103;
    }
    else if (n == 364)
    {
        a1[4] = 120;
    }
    else if (n == 365)
    {
        a1[20] = 92;
    }
    else if (n == 366)
    {
        a1[6] = 22;
    }
    else if (n == 367)
    {
        a1[21] = 107;
    }
    else if (n == 368)
    {
        a1[12] = 4;
    }
    else if (n == 369)
    {
        a1[17] = 112;
    }
    else if (n == 370)
    {
        a1[22] = 119;
    }
    else if (n == 371)
    {
        a1[18] = 125;
    }
    else if (n == 372)
    {
        a1[9] = 110;
    }
    else if (n == 373)
    {
        a1[6] = 100;
    }
    else if (n == 374)
    {
        a1[8] = 34;
    }
    else if (n == 375)
    {
        a1[2] = 0;
    }
    else if (n == 376)
    {
        a1[8] = 112;
    }
    else if (n == 377)
    {
        a1[7] = 81;
    }
    else if (n == 378)
    {
        a1[14] = 124;
    }
    else if (n == 379)
    {
        a1[21] = 105;
    }
    else if (n == 380)
    {
        a1[2] = 60;
    }
    else if (n == 381)
    {
        a1[20] = 81;
    }
    else if (n == 382)
    {
        a1[24] = 33;
    }
    else if (n == 383)
    {
        a1[12] = 56;
    }
    else if (n == 384)
    {
        a1[11] = 116;
    }
    else if (n == 385)
    {
        a1[24] = 81;
    }
    else if (n == 386)
    {
        a1[3] = 124;
    }
    else if (n == 387)
    {
        a1[22] = 47;
    }
    else if (n == 388)
    {
        a1[6] = 53;
    }
    else if (n == 389)
    {
        a1[21] = 87;
    }
    else if (n == 390)
    {
        a1[10] = 95;
    }
    else if (n == 391)
    {
        a1[6] = 76;
    }
    else if (n == 392)
    {
        a1[15] = 110;
    }
    else if (n == 393)
    {
        a1[16] = 84;
    }
    else if (n == 394)
    {
        a1[4] = 69;
    }
    else if (n == 395)
    {
        a1[12] = 67;
    }
    else if (n == 396)
    {
        a1[23] = 62;
    }
    else if (n == 397)
    {
        a1[4] = 6;
    }
    else if (n == 398)
    {
        a1[12] = 49;
    }
    else if (n == 399)
    {
        a1[15] = 109;
    }
    else if (n == 400)
    {
        a1[13] = 92;
    }
    else if (n == 401)
    {
        a1[22] = 10;
    }
    else if (n == 402)
    {
        a1[24] = 87;
    }
    else if (n == 403)
    {
        a1[2] = 44;
    }
    else if (n == 404)
    {
        a1[3] = 103;
    }
    else if (n == 405)
    {
        a1[14] = 85;
    }
    else if (n == 406)
    {
        a1[15] = 118;
    }
    else if (n == 407)
    {
        a1[8] = 26;
    }
    else if (n == 408)
    {
        a1[24] = 12;
    }
    else if (n == 409)
    {
        a1[10] = 120;
    }
    else if (n == 410)
    {
        a1[11] = 51;
    }
    else if (n == 411)
    {
        a1[13] = 15;
    }
    else if (n == 412)
    {
        a1[0] = 121;
    }
    else if (n == 413)
    {
        a1[0] = 22;
    }
    else if (n == 414)
    {
        a1[4] = 111;
    }
    else if (n == 415)
    {
        a1[11] = 103;
    }
    else if (n == 416)
    {
        a1[9] = 97;
    }
    else if (n == 417)
    {
        a1[1] = 16;
    }
    else if (n == 418)
    {
        a1[8] = 103;
    }
    else if (n == 419)
    {
        a1[21] = 58;
    }
    else if (n == 420)
    {
        a1[12] = 18;
    }
    else if (n == 421)
    {
        a1[11] = 0;
    }
    else if (n == 422)
    {
        a1[24] = 126;
    }
    else if (n == 423)
    {
        a1[16] = 94;
    }
    else if (n == 424)
    {
        a1[7] = 53;
    }
    else if (n == 425)
    {
        a1[18] = 23;
    }
    else if (n == 426)
    {
        a1[9] = 126;
    }
    else if (n == 427)
    {
        a1[7] = 99;
    }
    else if (n == 428)
    {
        a1[16] = 39;
    }
    else if (n == 429)
    {
        a1[15] = 23;
    }
    else if (n == 430)
    {
        a1[5] = 41;
    }
    else if (n == 431)
    {
        a1[11] = 90;
    }
    else if (n == 432)
    {
        a1[18] = 43;
    }
    else if (n == 433)
    {
        a1[6] = 75;
    }
    else if (n == 434)
    {
        a1[13] = 68;
    }
    else if (n == 435)
    {
        a1[2] = 44;
    }
    else if (n == 436)
    {
        a1[6] = 49;
    }
    else if (n == 437)
    {
        a1[11] = 49;
    }
    else if (n == 438)
    {
        a1[4] = 98;
    }
    else if (n == 439)
    {
        a1[9] = 98;
    }
    else if (n == 440)
    {
        a1[1] = 76;
    }
    else if (n == 441)
    {
        a1[22] = 109;
    }
    else if (n == 442)
    {
        a1[2] = 75;
    }
    else if (n == 443)
    {
        a1[20] = 70;
    }
    else if (n == 444)
    {
        a1[11] = 89;
    }
    else if (n == 445)
    {
        a1[21] = 46;
    }
    else if (n == 446)
    {
        a1[6] = 53;
    }
    else if (n == 447)
    {
        a1[1] = 50;
    }
    else if (n == 448)
    {
        a1[7] = 109;
    }
    else if (n == 449)
    {
        a1[20] = 87;
    }
    else if (n == 450)
    {
        a1[21] = 110;
    }
    else if (n == 451)
    {
        a1[22] = 76;
    }
    else if (n == 452)
    {
        a1[10] = 29;
    }
    else if (n == 453)
    {
        a1[19] = 117;
    }
    else if (n == 454)
    {
        a1[23] = 102;
    }
    else if (n == 455)
    {
        a1[23] = 62;
    }
    else if (n == 456)
    {
        a1[13] = 25;
    }
    else if (n == 457)
    {
        a1[23] = 29;
    }
    else if (n == 458)
    {
        a1[19] = 119;
    }
    else if (n == 459)
    {
        a1[22] = 104;
    }
    else if (n == 460)
    {
        a1[2] = 33;
    }
    else if (n == 461)
    {
        a1[2] = 99;
    }
    else if (n == 462)
    {
        a1[1] = 98;
    }
    else if (n == 463)
    {
        a1[11] = 41;
    }
    else if (n == 464)
    {
        a1[0] = 13;
    }
    else if (n == 465)
    {
        a1[3] = 10;
    }
    else if (n == 466)
    {
        a1[12] = 122;
    }
    else if (n == 467)
    {
        a1[20] = 85;
    }
    else if (n == 468)
    {
        a1[7] = 2;
    }
    else if (n == 469)
    {
        a1[24] = 93;
    }
    else if (n == 470)
    {
        a1[11] = 41;
    }
    else if (n == 471)
    {
        a1[9] = 42;
    }
    else if (n == 472)
    {
        a1[5] = 7;
    }
    else if (n == 473)
    {
        a1[20] = 92;
    }
    else if (n == 474)
    {
        a1[21] = 127;
    }
    else if (n == 475)
    {
        a1[0] = 30;
    }
    else if (n == 476)
    {
        a1[13] = 79;
    }
    else if (n == 477)
    {
        a1[21] = 74;
    }
    else if (n == 478)
    {
        a1[13] = 2;
    }
    else if (n == 479)
    {
        a1[8] = 114;
    }
    else if (n == 480)
    {
        a1[19] = 46;
    }
    else if (n == 481)
    {
        a1[23] = 84;
    }
    else if (n == 482)
    {
        a1[16] = 81;
    }
    else if (n == 483)
    {
        a1[7] = 95;
    }
    else if (n == 484)
    {
        a1[13] = 127;
    }
    else if (n == 485)
    {
        a1[24] = 105;
    }
    else if (n == 486)
    {
        a1[24] = 69;
    }
    else if (n == 487)
    {
        a1[10] = 66;
    }
    else if (n == 488)
    {
        a1[2] = 97;
    }
    else if (n == 489)
    {
        a1[18] = 115;
    }
    else if (n == 490)
    {
        a1[8] = 13;
    }
    else if (n == 491)
    {
        a1[4] = 62;
    }
    else if (n == 492)
    {
        a1[0] = 120;
    }
    else if (n == 493)
    {
        a1[1] = 70;
    }
    else if (n == 494)
    {
        a1[2] = 51;
    }
    else if (n == 495)
    {
        a1[22] = 62;
    }
    else if (n == 496)
    {
        a1[12] = 69;
    }
    else if (n == 497)
    {
        a1[10] = 24;
    }
    else if (n == 498)
    {
        a1[10] = 24;
    }
    else if (n == 499)
    {
        a1[22] = 28;
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