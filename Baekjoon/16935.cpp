#include <iostream>

#define MAX_SCOPE 101

using namespace std;

int width, height, instruction;
int originalMatrix[MAX_SCOPE][MAX_SCOPE];
int rotatedMatrix[MAX_SCOPE][MAX_SCOPE];

void init() {
    scanf("%d %d %d" , &height, &width, &instruction);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            scanf("%d", &originalMatrix[i][j]);
        }
    }
}

void calcuate(int instNum, int originalMatrix[][MAX_SCOPE], int rotatedMatrix[][MAX_SCOPE]) {
    int horizonEnd = width - 1;
    int verticalEnd = height - 1;
    if(instNum == 1) {
        for(int i = 0; i < width; i++) {
            for(int j = 0; j < height; j++) {
                rotatedMatrix[verticalEnd-j][i] = originalMatrix[j][i];
            }
        }
    }
    else if(instNum == 2) {
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                rotatedMatrix[i][horizonEnd-j] = originalMatrix[i][j];
            }
        }
    }
    else if(instNum == 3) {
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                rotatedMatrix[j][height-1-i] = originalMatrix[i][j];
            }
        }
        int tmp = height;
        height = width;
        width = tmp;
    }
    else if(instNum == 4) {
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                rotatedMatrix[width-1-j][i] = originalMatrix[i][j];
            }
        }
        int tmp = height;
        height = width;
        width = tmp;
    }
    else if(instNum == 5) {
        for(int i = 0; i < height/2; i++) {
            for(int j = 0; j < width/2; j++) {
                rotatedMatrix[i][j + width/2] = originalMatrix[i][j];
                rotatedMatrix[i + height/2][j + width/2] = originalMatrix[i][j + width/2];
                rotatedMatrix[i + height/2][j] = originalMatrix[i + height/2][j + width/2];
                rotatedMatrix[i][j] = originalMatrix[i + height/2][j];
            }
        }
    }
    else if(instNum == 6) {
        for(int i = 0; i < height/2; i++) {
            for(int j = 0; j < width/2; j++) {
                rotatedMatrix[i][j + width/2] = originalMatrix[i + height/2][j + width/2];
                rotatedMatrix[i + height/2][j + width/2] = originalMatrix[i + height/2][j];
                rotatedMatrix[i + height/2][j] = originalMatrix[i][j];
                rotatedMatrix[i][j] = originalMatrix[i][j + width/2];
            }
        }
    }
}

void solve() {
    int instNum;
    for(int i = 0; i < instruction; i++) {
        scanf("%d", &instNum);
        if(i%2 == 0) {
            calcuate(instNum, originalMatrix, rotatedMatrix);
        }
        else {
            calcuate(instNum, rotatedMatrix, originalMatrix);
        }
    }
}

void print() {
    if(instruction%2 == 0) {
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                printf("%d ", originalMatrix[i][j]);
            }
            printf("\n");
        }
    }
    else {
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                printf("%d ", rotatedMatrix[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    init();
    solve();
    print();
}