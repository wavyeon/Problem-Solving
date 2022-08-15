#include <iostream>
#include <algorithm>
#define MAX_SCOPE 301

using namespace std;

int width, height, rotationTime;
int originalMatrix[MAX_SCOPE][MAX_SCOPE];
int rotatedMatrix[MAX_SCOPE][MAX_SCOPE];

void init() {
    scanf("%d %d %d" , &height, &width, &rotationTime);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            scanf("%d", &originalMatrix[i][j]);
        }
    }
    rotationTime %= (height*width);
}

void rotateOneLayer(int horizonStart, int horizonEnd, int verticalStart, int verticalEnd) {
    for(int i = verticalStart; i < verticalEnd; i++) {
        rotatedMatrix[i+1][horizonStart] = originalMatrix[i][horizonStart];
    }
    for(int i = horizonStart; i < horizonEnd; i++) {
        rotatedMatrix[verticalEnd][i+1] = originalMatrix[verticalEnd][i];
    }
    for(int i = verticalEnd; i > verticalStart; i--) {
        rotatedMatrix[i-1][horizonEnd] = originalMatrix[i][horizonEnd];
    }
    for(int i = horizonEnd; i > horizonStart; i--) {
        rotatedMatrix[verticalStart][i-1] = originalMatrix[verticalStart][i];
    }
}

void solve() {
    int horizonStart = 0;
    int horizonEnd = width - 1;
    int verticalStart = 0;
    int verticalEnd = height - 1;
    for(int j = 0; j < rotationTime; j++) {
        for(int i = 0; i < min(height, width) / 2; i++) {
            rotateOneLayer(horizonStart+i, horizonEnd-i, verticalStart+i, verticalEnd-i);
        }
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                originalMatrix[i][j] = rotatedMatrix[i][j];
            }
        }
    }
}

void print() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("%d ", rotatedMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    init();
    solve();
    print();
}