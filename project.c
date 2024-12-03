#include <stdio.h>

#define MAX_SIZE 17

char map[MAX_SIZE][MAX_SIZE];
int line, col;

void mapdraw() {           // مقدار اولیه مپ
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < col; j++) {
            map[i][j] = '.';
        }
    }
}

void mapchap() {          // چاپ نقشه
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
void interputchek(){}
void kingdom(){
    int i,j,m,n;
    scanf("");
}
void villageg(){}
void blocks(){}
int main() {
    scanf("%d %d", &line, &col);

    if (line > MAX_SIZE || col > MAX_SIZE) {
        printf("Error: Maximum size is %dx%d\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    mapdraw();
    mapchap();

}