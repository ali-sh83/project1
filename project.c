#include <stdio.h>
#include <string.h>

#define MAX_SIZE 17                         // حداکثر تعداد سطر و ستون
#define STRING_LENGTH 10

char map[MAX_SIZE][MAX_SIZE][STRING_LENGTH];
int line, col;

void mapdraw() {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < col; j++) {
            strcpy(map[i][j], ".");
        }
    }
}

void mapchap() {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < col; j++) {
            printf("%s ", map[i][j]);
        }
        printf("\n");
    }
}

int is_valid_position(int i, int j) {
    if (i < 1  i > line  j < 1  j > col) {
        printf("Error: Position (%d, %d) is out of bounds!\n", i, j);
        return 0;
    }
    if (strcmp(map[i-1][j-1], ".") != 0) {
        printf("Error: Position (%d, %d) is already occupied by '%s'!\n", i, j, map[i-1][j-1]);
        return 0;
    }
    return 1;
}

void kingdom() {
    int i1, j1, i2, j2;
    printf("Enter positions for K1 (row column) and K2 (row column): ");
    scanf("%d %d %d %d", &i1, &j1, &i2, &j2);

    if (is_valid_position(i1, j1)) {
        strcpy(map[i1-1][j1-1], "K1");
    }
    if (is_valid_position(i2, j2)) {
        strcpy(map[i2-1][j2-1], "K2");
    }
}

void block() {
    int n;
    printf("Please enter the number of blocks: ");
    scanf("%d", &n);
    for (int k = 0; k < n; k++) {
        int i, j;
        printf("Please enter block location (row column): ");
        scanf("%d %d", &i, &j);
        if (is_valid_position(i, j)) {
            strcpy(map[i-1][j-1], "B");
        }
    }
}

int main() {
    printf("Enter map dimensions (lines columns): ");
    scanf("%d %d", &line, &col);

    if (line > MAX_SIZE  col > MAX_SIZE) {
        printf("Error: Maximum size is %dx%d\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    mapdraw();
    kingdom();
    block();
    mapchap();

    return 0;
}