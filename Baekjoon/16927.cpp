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
    // int sideLength = (width+height)*2 - 4; // 테두리 길이 
    // rotationTime = rotationTime % sideLength;
    // rotationTime이 0이 되버리는 경우 대비
    // for(int i = 0; i < height; i++) {
    //     for(int j = 0; j < width; j++) {
    //         rotatedMatrix[i][j] = originalMatrix[i][j];
    //     }
    // }
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
    //바로 다시 원래 matrix로 복사시켜서 다음 회전 준비
    for(int i = verticalStart; i < verticalEnd; i++) {
        originalMatrix[i+1][horizonStart] = rotatedMatrix[i+1][horizonStart];
    }
    for(int i = horizonStart; i < horizonEnd; i++) {
        originalMatrix[verticalEnd][i+1] = rotatedMatrix[verticalEnd][i+1];
    }
    for(int i = verticalEnd; i > verticalStart; i--) {
        originalMatrix[i-1][horizonEnd] = rotatedMatrix[i-1][horizonEnd];
    }
    for(int i = horizonEnd; i > horizonStart; i--) {
        originalMatrix[verticalStart][i-1] = rotatedMatrix[verticalStart][i-1];
    }
}

void solve() {
    int horizonStart = 0;
    int horizonEnd = width - 1;
    int verticalStart = 0;
    int verticalEnd = height - 1;
    for(int i = 0; i < min(height, width) / 2; i++) {
        int sideLength = (( (height - (2*i)) + (width - (2*i)) ) * 2 - 4);
        for(int j = 0; j < rotationTime % sideLength; j++) {
            rotateOneLayer(horizonStart+i, horizonEnd-i, verticalStart+i, verticalEnd-i);
        }
    }

    // for(int k = 0; k < rotationTime; k++) {
    //     for(int i = 0; i < min(height, width) / 2; i++) {
    //         rotateOneLayer(horizonStart+i, horizonEnd-i, verticalStart+i, verticalEnd-i);
    //     }
    //     for(int i = 0; i < height; i++) {
    //         for(int j = 0; j < width; j++) {
    //             originalMatrix[i][j] = rotatedMatrix[i][j];
    //         }
    //     }
    // }
}

void print() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("%d ", originalMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    init();
    solve();
    print();
}