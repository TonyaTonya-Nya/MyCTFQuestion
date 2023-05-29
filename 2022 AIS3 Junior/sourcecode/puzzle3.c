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
void trickyFlag(int n);

int playerX = 1;
int playerY = 1;
int num = 0;
// AIS3JUNIOR_U_need_Play_It
// 350步剛好走到終點
char flag[] = {56, 14, 22, 27, 83, 9, 113, 116, 106, 1, 120, 25, 37, 115, 41, 66, 60, 101, 76, 45, 55, 105, 85, 34, 70};
char key[] = {53, 17, 14, 9, 61, 78, 84, 1, 96, 14, 47, 23, 102, 97, 16, 60, 13, 110, 101, 88, 33, 56, 64, 42, 43};

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

    while (puzzle[MAX - 2][MAX - 2] == GOAL)
    {
        printPuzzle(puzzle);
        printf("%d\n", num);
        walk(puzzle);
        trickyFlag(++num);
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

void trickyFlag(int n)
{
    if (n == 0)
    {
        flag[10] = 75;
    }
    else if (n == 1)
    {
        flag[19] = 91;
    }
    else if (n == 2)
    {
        flag[18] = 113;
    }
    else if (n == 3)
    {
        flag[18] = 53;
    }
    else if (n == 4)
    {
        flag[18] = 20;
    }
    else if (n == 5)
    {
        flag[18] = 39;
    }
    else if (n == 6)
    {
        flag[14] = 80;
    }
    else if (n == 7)
    {
        flag[18] = 100;
    }
    else if (n == 8)
    {
        flag[15] = 0;
    }
    else if (n == 9)
    {
        flag[5] = 57;
    }
    else if (n == 10)
    {
        flag[10] = 46;
    }
    else if (n == 11)
    {
        flag[18] = 100;
    }
    else if (n == 12)
    {
        flag[12] = 88;
    }
    else if (n == 13)
    {
        flag[16] = 44;
    }
    else if (n == 14)
    {
        flag[21] = 95;
    }
    else if (n == 15)
    {
        flag[5] = 21;
    }
    else if (n == 16)
    {
        flag[9] = 115;
    }
    else if (n == 17)
    {
        flag[7] = 9;
    }
    else if (n == 18)
    {
        flag[0] = 123;
    }
    else if (n == 19)
    {
        flag[22] = 84;
    }
    else if (n == 20)
    {
        flag[22] = 20;
    }
    else if (n == 21)
    {
        flag[11] = 51;
    }
    else if (n == 22)
    {
        flag[4] = 98;
    }
    else if (n == 23)
    {
        flag[13] = 29;
    }
    else if (n == 24)
    {
        flag[10] = 121;
    }
    else if (n == 25)
    {
        flag[17] = 28;
    }
    else if (n == 26)
    {
        flag[19] = 75;
    }
    else if (n == 27)
    {
        flag[21] = 33;
    }
    else if (n == 28)
    {
        flag[24] = 35;
    }
    else if (n == 29)
    {
        flag[0] = 38;
    }
    else if (n == 30)
    {
        flag[2] = 119;
    }
    else if (n == 31)
    {
        flag[6] = 80;
    }
    else if (n == 32)
    {
        flag[4] = 38;
    }
    else if (n == 33)
    {
        flag[2] = 73;
    }
    else if (n == 34)
    {
        flag[12] = 105;
    }
    else if (n == 35)
    {
        flag[14] = 122;
    }
    else if (n == 36)
    {
        flag[16] = 93;
    }
    else if (n == 37)
    {
        flag[14] = 108;
    }
    else if (n == 38)
    {
        flag[0] = 6;
    }
    else if (n == 39)
    {
        flag[4] = 7;
    }
    else if (n == 40)
    {
        flag[16] = 17;
    }
    else if (n == 41)
    {
        flag[7] = 107;
    }
    else if (n == 42)
    {
        flag[15] = 27;
    }
    else if (n == 43)
    {
        flag[1] = 64;
    }
    else if (n == 44)
    {
        flag[8] = 72;
    }
    else if (n == 45)
    {
        flag[1] = 82;
    }
    else if (n == 46)
    {
        flag[21] = 44;
    }
    else if (n == 47)
    {
        flag[13] = 58;
    }
    else if (n == 48)
    {
        flag[17] = 17;
    }
    else if (n == 49)
    {
        flag[5] = 124;
    }
    else if (n == 50)
    {
        flag[19] = 89;
    }
    else if (n == 51)
    {
        flag[9] = 21;
    }
    else if (n == 52)
    {
        flag[9] = 111;
    }
    else if (n == 53)
    {
        flag[23] = 126;
    }
    else if (n == 54)
    {
        flag[21] = 24;
    }
    else if (n == 55)
    {
        flag[23] = 43;
    }
    else if (n == 56)
    {
        flag[21] = 94;
    }
    else if (n == 57)
    {
        flag[0] = 105;
    }
    else if (n == 58)
    {
        flag[13] = 30;
    }
    else if (n == 59)
    {
        flag[22] = 122;
    }
    else if (n == 60)
    {
        flag[1] = 64;
    }
    else if (n == 61)
    {
        flag[10] = 82;
    }
    else if (n == 62)
    {
        flag[1] = 22;
    }
    else if (n == 63)
    {
        flag[14] = 33;
    }
    else if (n == 64)
    {
        flag[24] = 25;
    }
    else if (n == 65)
    {
        flag[15] = 76;
    }
    else if (n == 66)
    {
        flag[17] = 105;
    }
    else if (n == 67)
    {
        flag[3] = 82;
    }
    else if (n == 68)
    {
        flag[5] = 71;
    }
    else if (n == 69)
    {
        flag[10] = 44;
    }
    else if (n == 70)
    {
        flag[8] = 95;
    }
    else if (n == 71)
    {
        flag[17] = 99;
    }
    else if (n == 72)
    {
        flag[17] = 95;
    }
    else if (n == 73)
    {
        flag[11] = 79;
    }
    else if (n == 74)
    {
        flag[5] = 21;
    }
    else if (n == 75)
    {
        flag[24] = 83;
    }
    else if (n == 76)
    {
        flag[1] = 63;
    }
    else if (n == 77)
    {
        flag[21] = 64;
    }
    else if (n == 78)
    {
        flag[22] = 76;
    }
    else if (n == 79)
    {
        flag[11] = 49;
    }
    else if (n == 80)
    {
        flag[10] = 48;
    }
    else if (n == 81)
    {
        flag[1] = 72;
    }
    else if (n == 82)
    {
        flag[14] = 22;
    }
    else if (n == 83)
    {
        flag[3] = 2;
    }
    else if (n == 84)
    {
        flag[13] = 15;
    }
    else if (n == 85)
    {
        flag[15] = 98;
    }
    else if (n == 86)
    {
        flag[5] = 122;
    }
    else if (n == 87)
    {
        flag[23] = 98;
    }
    else if (n == 88)
    {
        flag[22] = 31;
    }
    else if (n == 89)
    {
        flag[18] = 73;
    }
    else if (n == 90)
    {
        flag[22] = 68;
    }
    else if (n == 91)
    {
        flag[12] = 93;
    }
    else if (n == 92)
    {
        flag[17] = 44;
    }
    else if (n == 93)
    {
        flag[9] = 0;
    }
    else if (n == 94)
    {
        flag[24] = 31;
    }
    else if (n == 95)
    {
        flag[22] = 106;
    }
    else if (n == 96)
    {
        flag[0] = 59;
    }
    else if (n == 97)
    {
        flag[23] = 26;
    }
    else if (n == 98)
    {
        flag[21] = 8;
    }
    else if (n == 99)
    {
        flag[22] = 100;
    }
    else if (n == 100)
    {
        flag[10] = 122;
    }
    else if (n == 101)
    {
        flag[7] = 93;
    }
    else if (n == 102)
    {
        flag[3] = 19;
    }
    else if (n == 103)
    {
        flag[11] = 73;
    }
    else if (n == 104)
    {
        flag[18] = 53;
    }
    else if (n == 105)
    {
        flag[2] = 25;
    }
    else if (n == 106)
    {
        flag[7] = 87;
    }
    else if (n == 107)
    {
        flag[3] = 31;
    }
    else if (n == 108)
    {
        flag[9] = 25;
    }
    else if (n == 109)
    {
        flag[18] = 24;
    }
    else if (n == 110)
    {
        flag[3] = 7;
    }
    else if (n == 111)
    {
        flag[10] = 83;
    }
    else if (n == 112)
    {
        flag[16] = 33;
    }
    else if (n == 113)
    {
        flag[22] = 68;
    }
    else if (n == 114)
    {
        flag[4] = 28;
    }
    else if (n == 115)
    {
        flag[17] = 35;
    }
    else if (n == 116)
    {
        flag[1] = 54;
    }
    else if (n == 117)
    {
        flag[23] = 97;
    }
    else if (n == 118)
    {
        flag[11] = 77;
    }
    else if (n == 119)
    {
        flag[16] = 112;
    }
    else if (n == 120)
    {
        flag[11] = 60;
    }
    else if (n == 121)
    {
        flag[12] = 18;
    }
    else if (n == 122)
    {
        flag[16] = 40;
    }
    else if (n == 123)
    {
        flag[14] = 105;
    }
    else if (n == 124)
    {
        flag[17] = 17;
    }
    else if (n == 125)
    {
        flag[8] = 13;
    }
    else if (n == 126)
    {
        flag[7] = 28;
    }
    else if (n == 127)
    {
        flag[23] = 41;
    }
    else if (n == 128)
    {
        flag[8] = 103;
    }
    else if (n == 129)
    {
        flag[10] = 114;
    }
    else if (n == 130)
    {
        flag[17] = 106;
    }
    else if (n == 131)
    {
        flag[14] = 63;
    }
    else if (n == 132)
    {
        flag[2] = 87;
    }
    else if (n == 133)
    {
        flag[8] = 84;
    }
    else if (n == 134)
    {
        flag[6] = 62;
    }
    else if (n == 135)
    {
        flag[8] = 11;
    }
    else if (n == 136)
    {
        flag[18] = 94;
    }
    else if (n == 137)
    {
        flag[16] = 125;
    }
    else if (n == 138)
    {
        flag[20] = 69;
    }
    else if (n == 139)
    {
        flag[13] = 80;
    }
    else if (n == 140)
    {
        flag[14] = 18;
    }
    else if (n == 141)
    {
        flag[6] = 92;
    }
    else if (n == 142)
    {
        flag[21] = 2;
    }
    else if (n == 143)
    {
        flag[11] = 101;
    }
    else if (n == 144)
    {
        flag[19] = 45;
    }
    else if (n == 145)
    {
        flag[20] = 121;
    }
    else if (n == 146)
    {
        flag[24] = 48;
    }
    else if (n == 147)
    {
        flag[12] = 98;
    }
    else if (n == 148)
    {
        flag[16] = 59;
    }
    else if (n == 149)
    {
        flag[0] = 98;
    }
    else if (n == 150)
    {
        flag[21] = 17;
    }
    else if (n == 151)
    {
        flag[4] = 48;
    }
    else if (n == 152)
    {
        flag[13] = 85;
    }
    else if (n == 153)
    {
        flag[4] = 119;
    }
    else if (n == 154)
    {
        flag[18] = 21;
    }
    else if (n == 155)
    {
        flag[5] = 13;
    }
    else if (n == 156)
    {
        flag[9] = 83;
    }
    else if (n == 157)
    {
        flag[0] = 20;
    }
    else if (n == 158)
    {
        flag[23] = 82;
    }
    else if (n == 159)
    {
        flag[13] = 89;
    }
    else if (n == 160)
    {
        flag[10] = 100;
    }
    else if (n == 161)
    {
        flag[2] = 1;
    }
    else if (n == 162)
    {
        flag[6] = 90;
    }
    else if (n == 163)
    {
        flag[8] = 116;
    }
    else if (n == 164)
    {
        flag[1] = 125;
    }
    else if (n == 165)
    {
        flag[23] = 17;
    }
    else if (n == 166)
    {
        flag[17] = 62;
    }
    else if (n == 167)
    {
        flag[19] = 83;
    }
    else if (n == 168)
    {
        flag[4] = 102;
    }
    else if (n == 169)
    {
        flag[23] = 124;
    }
    else if (n == 170)
    {
        flag[18] = 35;
    }
    else if (n == 171)
    {
        flag[20] = 1;
    }
    else if (n == 172)
    {
        flag[24] = 127;
    }
    else if (n == 173)
    {
        flag[20] = 57;
    }
    else if (n == 174)
    {
        flag[23] = 58;
    }
    else if (n == 175)
    {
        flag[10] = 70;
    }
    else if (n == 176)
    {
        flag[2] = 15;
    }
    else if (n == 177)
    {
        flag[0] = 29;
    }
    else if (n == 178)
    {
        flag[11] = 6;
    }
    else if (n == 179)
    {
        flag[8] = 83;
    }
    else if (n == 180)
    {
        flag[16] = 38;
    }
    else if (n == 181)
    {
        flag[1] = 111;
    }
    else if (n == 182)
    {
        flag[8] = 109;
    }
    else if (n == 183)
    {
        flag[5] = 105;
    }
    else if (n == 184)
    {
        flag[23] = 15;
    }
    else if (n == 185)
    {
        flag[15] = 30;
    }
    else if (n == 186)
    {
        flag[2] = 120;
    }
    else if (n == 187)
    {
        flag[20] = 11;
    }
    else if (n == 188)
    {
        flag[7] = 70;
    }
    else if (n == 189)
    {
        flag[7] = 88;
    }
    else if (n == 190)
    {
        flag[1] = 8;
    }
    else if (n == 191)
    {
        flag[9] = 79;
    }
    else if (n == 192)
    {
        flag[0] = 36;
    }
    else if (n == 193)
    {
        flag[1] = 91;
    }
    else if (n == 194)
    {
        flag[4] = 109;
    }
    else if (n == 195)
    {
        flag[6] = 89;
    }
    else if (n == 196)
    {
        flag[18] = 56;
    }
    else if (n == 197)
    {
        flag[22] = 123;
    }
    else if (n == 198)
    {
        flag[17] = 59;
    }
    else if (n == 199)
    {
        flag[3] = 49;
    }
    else if (n == 200)
    {
        flag[24] = 0;
    }
    else if (n == 201)
    {
        flag[17] = 54;
    }
    else if (n == 202)
    {
        flag[1] = 73;
    }
    else if (n == 203)
    {
        flag[18] = 77;
    }
    else if (n == 204)
    {
        flag[9] = 111;
    }
    else if (n == 205)
    {
        flag[11] = 18;
    }
    else if (n == 206)
    {
        flag[8] = 15;
    }
    else if (n == 207)
    {
        flag[7] = 6;
    }
    else if (n == 208)
    {
        flag[12] = 73;
    }
    else if (n == 209)
    {
        flag[6] = 9;
    }
    else if (n == 210)
    {
        flag[6] = 107;
    }
    else if (n == 211)
    {
        flag[11] = 26;
    }
    else if (n == 212)
    {
        flag[22] = 36;
    }
    else if (n == 213)
    {
        flag[16] = 47;
    }
    else if (n == 214)
    {
        flag[16] = 102;
    }
    else if (n == 215)
    {
        flag[18] = 64;
    }
    else if (n == 216)
    {
        flag[5] = 66;
    }
    else if (n == 217)
    {
        flag[16] = 87;
    }
    else if (n == 218)
    {
        flag[14] = 87;
    }
    else if (n == 219)
    {
        flag[6] = 81;
    }
    else if (n == 220)
    {
        flag[15] = 82;
    }
    else if (n == 221)
    {
        flag[23] = 78;
    }
    else if (n == 222)
    {
        flag[11] = 18;
    }
    else if (n == 223)
    {
        flag[12] = 21;
    }
    else if (n == 224)
    {
        flag[16] = 61;
    }
    else if (n == 225)
    {
        flag[0] = 66;
    }
    else if (n == 226)
    {
        flag[18] = 87;
    }
    else if (n == 227)
    {
        flag[6] = 127;
    }
    else if (n == 228)
    {
        flag[22] = 67;
    }
    else if (n == 229)
    {
        flag[20] = 82;
    }
    else if (n == 230)
    {
        flag[18] = 70;
    }
    else if (n == 231)
    {
        flag[14] = 71;
    }
    else if (n == 232)
    {
        flag[24] = 62;
    }
    else if (n == 233)
    {
        flag[14] = 85;
    }
    else if (n == 234)
    {
        flag[17] = 36;
    }
    else if (n == 235)
    {
        flag[1] = 117;
    }
    else if (n == 236)
    {
        flag[4] = 20;
    }
    else if (n == 237)
    {
        flag[18] = 10;
    }
    else if (n == 238)
    {
        flag[18] = 60;
    }
    else if (n == 239)
    {
        flag[10] = 67;
    }
    else if (n == 240)
    {
        flag[5] = 112;
    }
    else if (n == 241)
    {
        flag[7] = 110;
    }
    else if (n == 242)
    {
        flag[2] = 58;
    }
    else if (n == 243)
    {
        flag[4] = 91;
    }
    else if (n == 244)
    {
        flag[20] = 76;
    }
    else if (n == 245)
    {
        flag[0] = 14;
    }
    else if (n == 246)
    {
        flag[5] = 109;
    }
    else if (n == 247)
    {
        flag[7] = 13;
    }
    else if (n == 248)
    {
        flag[4] = 119;
    }
    else if (n == 249)
    {
        flag[18] = 98;
    }
    else if (n == 250)
    {
        flag[16] = 105;
    }
    else if (n == 251)
    {
        flag[12] = 62;
    }
    else if (n == 252)
    {
        flag[22] = 7;
    }
    else if (n == 253)
    {
        flag[24] = 26;
    }
    else if (n == 254)
    {
        flag[24] = 58;
    }
    else if (n == 255)
    {
        flag[17] = 46;
    }
    else if (n == 256)
    {
        flag[14] = 6;
    }
    else if (n == 257)
    {
        flag[14] = 116;
    }
    else if (n == 258)
    {
        flag[12] = 91;
    }
    else if (n == 259)
    {
        flag[7] = 53;
    }
    else if (n == 260)
    {
        flag[1] = 69;
    }
    else if (n == 261)
    {
        flag[13] = 67;
    }
    else if (n == 262)
    {
        flag[7] = 0;
    }
    else if (n == 263)
    {
        flag[11] = 75;
    }
    else if (n == 264)
    {
        flag[24] = 105;
    }
    else if (n == 265)
    {
        flag[11] = 43;
    }
    else if (n == 266)
    {
        flag[13] = 42;
    }
    else if (n == 267)
    {
        flag[4] = 120;
    }
    else if (n == 268)
    {
        flag[19] = 25;
    }
    else if (n == 269)
    {
        flag[16] = 21;
    }
    else if (n == 270)
    {
        flag[13] = 70;
    }
    else if (n == 271)
    {
        flag[13] = 61;
    }
    else if (n == 272)
    {
        flag[4] = 123;
    }
    else if (n == 273)
    {
        flag[3] = 6;
    }
    else if (n == 274)
    {
        flag[22] = 53;
    }
    else if (n == 275)
    {
        flag[20] = 109;
    }
    else if (n == 276)
    {
        flag[16] = 73;
    }
    else if (n == 277)
    {
        flag[2] = 63;
    }
    else if (n == 278)
    {
        flag[21] = 92;
    }
    else if (n == 279)
    {
        flag[0] = 98;
    }
    else if (n == 280)
    {
        flag[4] = 61;
    }
    else if (n == 281)
    {
        flag[1] = 18;
    }
    else if (n == 282)
    {
        flag[7] = 63;
    }
    else if (n == 283)
    {
        flag[13] = 88;
    }
    else if (n == 284)
    {
        flag[21] = 33;
    }
    else if (n == 285)
    {
        flag[9] = 75;
    }
    else if (n == 286)
    {
        flag[8] = 76;
    }
    else if (n == 287)
    {
        flag[24] = 59;
    }
    else if (n == 288)
    {
        flag[23] = 118;
    }
    else if (n == 289)
    {
        flag[16] = 61;
    }
    else if (n == 290)
    {
        flag[2] = 4;
    }
    else if (n == 291)
    {
        flag[2] = 81;
    }
    else if (n == 292)
    {
        flag[19] = 45;
    }
    else if (n == 293)
    {
        flag[11] = 32;
    }
    else if (n == 294)
    {
        flag[14] = 117;
    }
    else if (n == 295)
    {
        flag[8] = 108;
    }
    else if (n == 296)
    {
        flag[12] = 103;
    }
    else if (n == 297)
    {
        flag[12] = 43;
    }
    else if (n == 298)
    {
        flag[7] = 37;
    }
    else if (n == 299)
    {
        flag[22] = 84;
    }
    else if (n == 300)
    {
        flag[5] = 92;
    }
    else if (n == 301)
    {
        flag[10] = 112;
    }
    else if (n == 302)
    {
        flag[2] = 93;
    }
    else if (n == 303)
    {
        flag[17] = 24;
    }
    else if (n == 304)
    {
        flag[15] = 17;
    }
    else if (n == 305)
    {
        flag[1] = 92;
    }
    else if (n == 306)
    {
        flag[20] = 64;
    }
    else if (n == 307)
    {
        flag[13] = 91;
    }
    else if (n == 308)
    {
        flag[24] = 55;
    }
    else if (n == 309)
    {
        flag[9] = 92;
    }
    else if (n == 310)
    {
        flag[24] = 112;
    }
    else if (n == 311)
    {
        flag[12] = 57;
    }
    else if (n == 312)
    {
        flag[21] = 4;
    }
    else if (n == 313)
    {
        flag[6] = 93;
    }
    else if (n == 314)
    {
        flag[19] = 52;
    }
    else if (n == 315)
    {
        flag[24] = 103;
    }
    else if (n == 316)
    {
        flag[5] = 121;
    }
    else if (n == 317)
    {
        flag[5] = 95;
    }
    else if (n == 318)
    {
        flag[18] = 74;
    }
    else if (n == 319)
    {
        flag[22] = 1;
    }
    else if (n == 320)
    {
        flag[3] = 84;
    }
    else if (n == 321)
    {
        flag[8] = 67;
    }
    else if (n == 322)
    {
        flag[13] = 15;
    }
    else if (n == 323)
    {
        flag[5] = 66;
    }
    else if (n == 324)
    {
        flag[17] = 49;
    }
    else if (n == 325)
    {
        flag[5] = 5;
    }
    else if (n == 326)
    {
        flag[24] = 86;
    }
    else if (n == 327)
    {
        flag[18] = 53;
    }
    else if (n == 328)
    {
        flag[11] = 56;
    }
    else if (n == 329)
    {
        flag[8] = 47;
    }
    else if (n == 330)
    {
        flag[3] = 110;
    }
    else if (n == 331)
    {
        flag[3] = 58;
    }
    else if (n == 332)
    {
        flag[11] = 66;
    }
    else if (n == 333)
    {
        flag[15] = 89;
    }
    else if (n == 334)
    {
        flag[5] = 27;
    }
    else if (n == 335)
    {
        flag[16] = 32;
    }
    else if (n == 336)
    {
        flag[16] = 82;
    }
    else if (n == 337)
    {
        flag[22] = 31;
    }
    else if (n == 338)
    {
        flag[21] = 65;
    }
    else if (n == 339)
    {
        flag[23] = 99;
    }
    else if (n == 340)
    {
        flag[16] = 105;
    }
    else if (n == 341)
    {
        flag[1] = 88;
    }
    else if (n == 342)
    {
        flag[6] = 26;
    }
    else if (n == 343)
    {
        flag[7] = 76;
    }
    else if (n == 344)
    {
        flag[0] = 116;
    }
    else if (n == 345)
    {
        flag[10] = 10;
    }
    else if (n == 346)
    {
        flag[7] = 72;
    }
    else if (n == 347)
    {
        flag[24] = 56;
    }
    else if (n == 348)
    {
        flag[10] = 112;
    }
    else if (n == 349)
    {
        flag[24] = 95;
    }
    else if (n == 350)
    {
        flag[4] = 119;
    }
    else if (n == 351)
    {
        flag[23] = 61;
    }
    else if (n == 352)
    {
        flag[7] = 6;
    }
    else if (n == 353)
    {
        flag[7] = 63;
    }
    else if (n == 354)
    {
        flag[7] = 126;
    }
    else if (n == 355)
    {
        flag[3] = 21;
    }
    else if (n == 356)
    {
        flag[19] = 28;
    }
    else if (n == 357)
    {
        flag[8] = 1;
    }
    else if (n == 358)
    {
        flag[6] = 62;
    }
    else if (n == 359)
    {
        flag[16] = 57;
    }
    else if (n == 360)
    {
        flag[11] = 20;
    }
    else if (n == 361)
    {
        flag[14] = 17;
    }
    else if (n == 362)
    {
        flag[0] = 95;
    }
    else if (n == 363)
    {
        flag[0] = 103;
    }
    else if (n == 364)
    {
        flag[4] = 120;
    }
    else if (n == 365)
    {
        flag[20] = 92;
    }
    else if (n == 366)
    {
        flag[6] = 22;
    }
    else if (n == 367)
    {
        flag[21] = 107;
    }
    else if (n == 368)
    {
        flag[12] = 4;
    }
    else if (n == 369)
    {
        flag[17] = 112;
    }
    else if (n == 370)
    {
        flag[22] = 119;
    }
    else if (n == 371)
    {
        flag[18] = 125;
    }
    else if (n == 372)
    {
        flag[9] = 110;
    }
    else if (n == 373)
    {
        flag[6] = 100;
    }
    else if (n == 374)
    {
        flag[8] = 34;
    }
    else if (n == 375)
    {
        flag[2] = 0;
    }
    else if (n == 376)
    {
        flag[8] = 112;
    }
    else if (n == 377)
    {
        flag[7] = 81;
    }
    else if (n == 378)
    {
        flag[14] = 124;
    }
    else if (n == 379)
    {
        flag[21] = 105;
    }
    else if (n == 380)
    {
        flag[2] = 60;
    }
    else if (n == 381)
    {
        flag[20] = 81;
    }
    else if (n == 382)
    {
        flag[24] = 33;
    }
    else if (n == 383)
    {
        flag[12] = 56;
    }
    else if (n == 384)
    {
        flag[11] = 116;
    }
    else if (n == 385)
    {
        flag[24] = 81;
    }
    else if (n == 386)
    {
        flag[3] = 124;
    }
    else if (n == 387)
    {
        flag[22] = 47;
    }
    else if (n == 388)
    {
        flag[6] = 53;
    }
    else if (n == 389)
    {
        flag[21] = 87;
    }
    else if (n == 390)
    {
        flag[10] = 95;
    }
    else if (n == 391)
    {
        flag[6] = 76;
    }
    else if (n == 392)
    {
        flag[15] = 110;
    }
    else if (n == 393)
    {
        flag[16] = 84;
    }
    else if (n == 394)
    {
        flag[4] = 69;
    }
    else if (n == 395)
    {
        flag[12] = 67;
    }
    else if (n == 396)
    {
        flag[23] = 62;
    }
    else if (n == 397)
    {
        flag[4] = 6;
    }
    else if (n == 398)
    {
        flag[12] = 49;
    }
    else if (n == 399)
    {
        flag[15] = 109;
    }
    else if (n == 400)
    {
        flag[13] = 92;
    }
    else if (n == 401)
    {
        flag[22] = 10;
    }
    else if (n == 402)
    {
        flag[24] = 87;
    }
    else if (n == 403)
    {
        flag[2] = 44;
    }
    else if (n == 404)
    {
        flag[3] = 103;
    }
    else if (n == 405)
    {
        flag[14] = 85;
    }
    else if (n == 406)
    {
        flag[15] = 118;
    }
    else if (n == 407)
    {
        flag[8] = 26;
    }
    else if (n == 408)
    {
        flag[24] = 12;
    }
    else if (n == 409)
    {
        flag[10] = 120;
    }
    else if (n == 410)
    {
        flag[11] = 51;
    }
    else if (n == 411)
    {
        flag[13] = 15;
    }
    else if (n == 412)
    {
        flag[0] = 121;
    }
    else if (n == 413)
    {
        flag[0] = 22;
    }
    else if (n == 414)
    {
        flag[4] = 111;
    }
    else if (n == 415)
    {
        flag[11] = 103;
    }
    else if (n == 416)
    {
        flag[9] = 97;
    }
    else if (n == 417)
    {
        flag[1] = 16;
    }
    else if (n == 418)
    {
        flag[8] = 103;
    }
    else if (n == 419)
    {
        flag[21] = 58;
    }
    else if (n == 420)
    {
        flag[12] = 18;
    }
    else if (n == 421)
    {
        flag[11] = 0;
    }
    else if (n == 422)
    {
        flag[24] = 126;
    }
    else if (n == 423)
    {
        flag[16] = 94;
    }
    else if (n == 424)
    {
        flag[7] = 53;
    }
    else if (n == 425)
    {
        flag[18] = 23;
    }
    else if (n == 426)
    {
        flag[9] = 126;
    }
    else if (n == 427)
    {
        flag[7] = 99;
    }
    else if (n == 428)
    {
        flag[16] = 39;
    }
    else if (n == 429)
    {
        flag[15] = 23;
    }
    else if (n == 430)
    {
        flag[5] = 41;
    }
    else if (n == 431)
    {
        flag[11] = 90;
    }
    else if (n == 432)
    {
        flag[18] = 43;
    }
    else if (n == 433)
    {
        flag[6] = 75;
    }
    else if (n == 434)
    {
        flag[13] = 68;
    }
    else if (n == 435)
    {
        flag[2] = 44;
    }
    else if (n == 436)
    {
        flag[6] = 49;
    }
    else if (n == 437)
    {
        flag[11] = 49;
    }
    else if (n == 438)
    {
        flag[4] = 98;
    }
    else if (n == 439)
    {
        flag[9] = 98;
    }
    else if (n == 440)
    {
        flag[1] = 76;
    }
    else if (n == 441)
    {
        flag[22] = 109;
    }
    else if (n == 442)
    {
        flag[2] = 75;
    }
    else if (n == 443)
    {
        flag[20] = 70;
    }
    else if (n == 444)
    {
        flag[11] = 89;
    }
    else if (n == 445)
    {
        flag[21] = 46;
    }
    else if (n == 446)
    {
        flag[6] = 53;
    }
    else if (n == 447)
    {
        flag[1] = 50;
    }
    else if (n == 448)
    {
        flag[7] = 109;
    }
    else if (n == 449)
    {
        flag[20] = 87;
    }
    else if (n == 450)
    {
        flag[21] = 110;
    }
    else if (n == 451)
    {
        flag[22] = 76;
    }
    else if (n == 452)
    {
        flag[10] = 29;
    }
    else if (n == 453)
    {
        flag[19] = 117;
    }
    else if (n == 454)
    {
        flag[23] = 102;
    }
    else if (n == 455)
    {
        flag[23] = 62;
    }
    else if (n == 456)
    {
        flag[13] = 25;
    }
    else if (n == 457)
    {
        flag[23] = 29;
    }
    else if (n == 458)
    {
        flag[19] = 119;
    }
    else if (n == 459)
    {
        flag[22] = 104;
    }
    else if (n == 460)
    {
        flag[2] = 33;
    }
    else if (n == 461)
    {
        flag[2] = 99;
    }
    else if (n == 462)
    {
        flag[1] = 98;
    }
    else if (n == 463)
    {
        flag[11] = 41;
    }
    else if (n == 464)
    {
        flag[0] = 13;
    }
    else if (n == 465)
    {
        flag[3] = 10;
    }
    else if (n == 466)
    {
        flag[12] = 122;
    }
    else if (n == 467)
    {
        flag[20] = 85;
    }
    else if (n == 468)
    {
        flag[7] = 2;
    }
    else if (n == 469)
    {
        flag[24] = 93;
    }
    else if (n == 470)
    {
        flag[11] = 41;
    }
    else if (n == 471)
    {
        flag[9] = 42;
    }
    else if (n == 472)
    {
        flag[5] = 7;
    }
    else if (n == 473)
    {
        flag[20] = 92;
    }
    else if (n == 474)
    {
        flag[21] = 127;
    }
    else if (n == 475)
    {
        flag[0] = 30;
    }
    else if (n == 476)
    {
        flag[13] = 79;
    }
    else if (n == 477)
    {
        flag[21] = 74;
    }
    else if (n == 478)
    {
        flag[13] = 2;
    }
    else if (n == 479)
    {
        flag[8] = 114;
    }
    else if (n == 480)
    {
        flag[19] = 46;
    }
    else if (n == 481)
    {
        flag[23] = 84;
    }
    else if (n == 482)
    {
        flag[16] = 81;
    }
    else if (n == 483)
    {
        flag[7] = 95;
    }
    else if (n == 484)
    {
        flag[13] = 127;
    }
    else if (n == 485)
    {
        flag[24] = 105;
    }
    else if (n == 486)
    {
        flag[24] = 69;
    }
    else if (n == 487)
    {
        flag[10] = 66;
    }
    else if (n == 488)
    {
        flag[2] = 97;
    }
    else if (n == 489)
    {
        flag[18] = 115;
    }
    else if (n == 490)
    {
        flag[8] = 13;
    }
    else if (n == 491)
    {
        flag[4] = 62;
    }
    else if (n == 492)
    {
        flag[0] = 120;
    }
    else if (n == 493)
    {
        flag[1] = 70;
    }
    else if (n == 494)
    {
        flag[2] = 51;
    }
    else if (n == 495)
    {
        flag[22] = 62;
    }
    else if (n == 496)
    {
        flag[12] = 69;
    }
    else if (n == 497)
    {
        flag[10] = 24;
    }
    else if (n == 498)
    {
        flag[10] = 24;
    }
    else if (n == 499)
    {
        flag[22] = 28;
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