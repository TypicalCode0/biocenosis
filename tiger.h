#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 10
#define ageTiger 80
#define death 8
#define stepT 1
#define rangeT 3

void move_to_rabbit(int x, int y, int x2, int y2, WORLD map[][SIZE]) {
    int x1 = x, y1 = y;
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    int error = deltaX - deltaY;
    int n = 0;
    while (x1 != x2 || y1 != y2 || n != rangeT)
    {
        int error2 = error * 2;
        if (error2 > -deltaY)
        {
            error -= deltaY;
            x1 += signX;
        }
        if (error2 < deltaX)
        {
            error += deltaX;
            y1 += signY;
        }
        ++n;
    }
    if (x1 == x2 && y1 == y2) {
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].flag = 1;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tHere = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tHere;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tHere = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tiger.age = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.age;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.age = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tiger.gender = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.gender;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.gender = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tiger.hunger = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tiger.pregnancy = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregnancy;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregnancy = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tiger.pregnancy = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregnancy;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregnancy = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].rabbit.age = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].rabbit.gender = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].rabbit.hunger = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].rabbit.pregnancy = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].rabbit.pregTime = 0;
        return;
    }
    if (map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tHere == 0 && !map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].flag && !map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].rHere) {
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].flag = 1;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tHere = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tHere;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tHere = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tiger.age = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.age;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.age = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tiger.gender = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.gender;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.gender = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tiger.hunger = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tiger.pregnancy = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregnancy;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregnancy = 0;
        map[(x1 + SIZE) % SIZE][(y1 + SIZE) % SIZE].tiger.pregTime = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregTime;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregTime = 0;
    }
}

int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[] = { -1,-1,-1, 0, 1, 1,  1,  0 };
void find_empty_T(int x, int y, WORLD map[][SIZE]) {
    for (int i = 0; i < 8; ++i) {
        if (map[(x + dx[i] + SIZE) % SIZE][(y + dy[i] + SIZE) % SIZE].rHere == 0 && map[(x + dx[i] + SIZE) % SIZE][(y + dy[i] + SIZE) % SIZE].tHere == 0 && !map[(x + dx[i] + SIZE) % SIZE][(y + dy[i] + SIZE) % SIZE].flag) {
            map[(x + dx[i] + SIZE) % SIZE][(y + dy[i] + SIZE) % SIZE].flag = 1;
            map[(x + dx[i] + SIZE) % SIZE][(y + dy[i] + SIZE) % SIZE].tHere = 1;
            map[(x + dx[i] + SIZE) % SIZE][(y + dy[i] + SIZE) % SIZE].tiger.age = 0;
            map[(x + dx[i] + SIZE) % SIZE][(y + dy[i] + SIZE) % SIZE].tiger.hunger = 0;
            map[(x + dx[i] + SIZE) % SIZE][(y + dy[i] + SIZE) % SIZE].tiger.pregnancy = 0;
            map[(x + dx[i] + SIZE) % SIZE][(y + dy[i] + SIZE) % SIZE].tiger.pregTime = 0;
            int abc = rand() % 2 + 1;
            map[(x + dx[i] + SIZE) % SIZE][(y + dy[i] + SIZE) % SIZE].tiger.gender = abc;
            return;
        }
    }
}

int loveT(int x, int y, WORLD map[][SIZE], int rad) {
    int i, j = y - rad;
    for (i = x - rad; i < x + rad; ++i) {
        if (rad <= stepT && !map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tHere && ((map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger <= 4 && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tiger.hunger > 4) || (map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger > 4 && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tiger.hunger <= 4))) {
            int random = rand() % 5;
            if (random == 0 || random == 1) {
                find_empty_T(x, y, map);
                map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].flag = 1;
                map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag = 1;
                return 1;
            }
        }
        else if (rad <= stepT && !map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tHere && map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger <= 4 && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tiger.hunger <= 4) {
            int random = rand() % 5;
            if (random == 0 || random == 1 || random == 2) {
                find_empty_T(x, y, map);
                map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].flag = 1;
                map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag = 1;
                return 1;
            }
        }
    }
    for (; j < y + rad; ++j) {
        if (rad <= stepT && !map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tHere && ((map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger <= 4 && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tiger.hunger > 4) || (map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger > 4 && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tiger.hunger <= 4))) {
            int random = rand() % 5;
            if (random == 0 || random == 1) {
                find_empty_T(x, y, map);
                map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].flag = 1;
                map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag = 1;
                return 1;
            }
        }
        else if (rad <= stepT && !map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tHere && map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger <= 4 && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tiger.hunger <= 4) {
            int random = rand() % 5;
            if (random == 0 || random == 1 || random == 2) {
                find_empty_T(x, y, map);
                map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].flag = 1;
                map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag = 1;
                return 1;
            }
        }
    }
    for (; i > x - rad; --i) {
        if (rad <= stepT && !map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tHere && ((map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger <= 4 && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tiger.hunger > 4) || (map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger > 4 && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tiger.hunger <= 4))) {
            int random = rand() % 5;
            if (random == 0 || random == 1) {
                find_empty_T(x, y, map);
                map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].flag = 1;
                map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag = 1;
                return 1;
            }
        }
        else if (rad <= stepT && !map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tHere && map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger <= 4 && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tiger.hunger <= 4) {
            int random = rand() % 5;
            if (random == 0 || random == 1 || random == 2) {
                find_empty_T(x, y, map);
                map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].flag = 1;
                map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag = 1;
                return 1;
            }
        }
    }
    for (; j > y - rad; --j) {
        if (rad <= stepT && !map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tHere && ((map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger <= 4 && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tiger.hunger > 4) || (map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger > 4 && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tiger.hunger <= 4))) {
            int random = rand() % 5;
            if (random == 0 || random == 1) {
                find_empty_T(x, y, map);
                map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].flag = 1;
                map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag = 1;
                return 1;
            }
        }
        else if (rad <= stepT && !map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tHere && map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger <= 4 && map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].tiger.hunger <= 4) {
            int random = rand() % 5;
            if (random == 0 || random == 1 || random == 2) {
                find_empty_T(x, y, map);
                map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].flag = 1;
                map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag = 1;
                return 1;
            }
        }
    }
    return 0;
}

int huntT(int x, int y, WORLD map[][SIZE], int rad) {
    int i, j = y - rad;
    for (i = x - rad; i < x + rad; ++i) {
        if (map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].rHere && !map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag) {
            move_to_rabbit((x + SIZE) % SIZE, (y + SIZE) % SIZE, (i + SIZE) % SIZE, (j + SIZE) % SIZE, map);
            return 1;
        }
    }
    for (; j < y + rad; ++j) {
        if (map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].rHere && !map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag) {
            move_to_rabbit((x + SIZE) % SIZE, (y + SIZE) % SIZE, (i + SIZE) % SIZE, (j + SIZE) % SIZE, map);
            return 1;
        }
    }
    for (; i > x - rad; --i) {
        if (map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].rHere && !map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag) {
            move_to_rabbit((x + SIZE) % SIZE, (y + SIZE) % SIZE, (i + SIZE) % SIZE, (j + SIZE) % SIZE, map);
            return 1;
        }
    }
    for (; j > y - rad; --j) {
        if (map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].rHere && !map[(i + SIZE) % SIZE][(j + SIZE) % SIZE].flag) {
            move_to_rabbit((x + SIZE) % SIZE, (y + SIZE) % SIZE, (i + SIZE) % SIZE, (j + SIZE) % SIZE, map);
            return 1;
        }
    }
    return 0;
}

void moveT(int x, int y, WORLD map[][SIZE]) {
    srand(time(NULL));
    char flag = 0;
    for (int i = 0; i < 15; ++i) {
        int mod = stepT + 1;
        int addX = rand() % mod, addY = rand() % mod;
        printf("%d   %d", (addX + x + SIZE) % SIZE, (addY + y + SIZE) % SIZE);
        if (addX == 0 && addY == 0) continue;
        if (!map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].flag && !map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].rHere && !map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].tHere) {
            printf("t = %d   age = %d   gender = %d   hunger = %d   ", map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tHere, map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.age, map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.gender, map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger);
            map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].flag = 1;
            map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].tHere = 1;
            map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tHere = 0;
            map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].tiger.age = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.age;
            map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.age = 0;
            map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].tiger.gender = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.gender;
            map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.gender = 0;
            map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].tiger.hunger = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger;
            map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger = 0;
            map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].tiger.pregnancy = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregnancy;
            map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregnancy = 0;
            map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].tiger.pregTime = map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregTime;
            map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregTime = 0;
            flag = 1;
            printf("\nt = %d   age = %d   gender = %d   hunger = %d   ", map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].tHere, map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].tiger.age, map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].tiger.gender, map[(x + addX + SIZE) % SIZE][(y + addY + SIZE) % SIZE].tiger.hunger);
        }
        if (flag) return;
    }
}

void tiger(int x, int y, WORLD map[][SIZE]) {
    map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.age++;
    map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger++;
    map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].flag = 1;
    if (map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.age == ageTiger) {
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tHere = 0;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.age = 0;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.gender = 0;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger = 0;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregnancy = 0;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregTime = 0;
        return;
    }
    if (map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger == death) {
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tHere = 0;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.age = 0;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.gender = 0;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger = 0;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregnancy = 0;
        map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.pregTime = 0;
        return;
    }
    if (map[(x + SIZE) % SIZE][(y + SIZE) % SIZE].tiger.hunger > 4) {
        int r = 1, flag = 0;
        while (r != rangeT) {
            flag = huntT(x, y, map, r);
            if (flag) return;
            ++r;
        }
        if (!flag) {
            moveT(x, y, map);
        }
        //r = rangeT;
        //while (r != 0) {
        //    flag = loveT(x, y, map, r);
        //    if (flag) return;
        //    --r;
        //}
    }
    else {
        int r = 1, flag = 0;
        while (r != rangeT) {
            if (r > stepT) break;
            flag = loveT(x, y, map, r);
            if (flag) return;
            ++r;
        }
        if (!flag) {
            moveT(x, y, map);
        }
        //r = rangeT;
        // while (r != 0) {
        //    flag = huntT(x, y, map, r);
        //    if (flag) return;
        //    --r;
        //}
    }
}
