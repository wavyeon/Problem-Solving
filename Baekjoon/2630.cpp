#include <iostream>
#define MAX_SCOPE 128
#define BLUE 1
#define WHITE 0

using namespace std;

int side, whiteCount, blueCount;
int colorPaper[MAX_SCOPE][MAX_SCOPE];

void init() {
    scanf("%d", &side);
    for(int i = 0; i < side; i++) {
        for(int j = 0; j < side; j++) {
            scanf("%d", &colorPaper[i][j]);
        }
    }
}

void findWhite(int length, int startY, int startX) {
    // cout << "(" <<startY << ", " << startX << ") 길이: " << length << endl;
    if(length == 1) {
        if(colorPaper[startY][startX] == BLUE) {
            return;
        }
        else if(colorPaper[startY][startX] == WHITE) {
            // cout << "here!!" << endl;
            whiteCount++;
        }
    }
    else {
        bool exist = true;
        for(int i = startY; i < startY + length; i++) {
            for(int j = startX; j < startX + length; j++) {
                if(colorPaper[i][j] == BLUE) {
                    exist = false;
                    break;
                }
            }
        }
        if(exist == true) {
            // cout << "here!!" << endl;
            whiteCount++;
        }
        else if(exist == false) {
            findWhite(length/2, startY, startX);
            findWhite(length/2, startY, startX+length/2);
            findWhite(length/2, startY+length/2, startX);
            findWhite(length/2, startY+length/2, startX+length/2);
        }
    }
}

void findBlue(int length, int startY, int startX) {
    // cout << "(" <<startY << ", " << startX << ") 길이: " << length << endl;
    if(length == 1) {
        if(colorPaper[startY][startX] == WHITE) {
            return;
        }
        else if(colorPaper[startY][startX] == BLUE) {
            // cout << "here!!" << endl;
            blueCount++;
        }
    }
    else {
        bool exist = true;
        for(int i = startY; i < startY + length; i++) {
            for(int j = startX; j < startX + length; j++) {
                if(colorPaper[i][j] == WHITE) {
                    exist = false;
                    break;
                }
            }
        }
        if(exist == true) {
            // cout << "here!!" << endl;
            blueCount++;
        }
        else if(exist == false) {
            findBlue(length/2, startY, startX);
            findBlue(length/2, startY, startX+length/2);
            findBlue(length/2, startY+length/2, startX);
            findBlue(length/2, startY+length/2, startX+length/2);
        }
    }
}


int main() {
    init();
    findWhite(side, 0, 0);
    findBlue(side, 0, 0);
    cout << whiteCount << endl << blueCount << endl;
}