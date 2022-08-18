#include <iostream>
#include <stdlib.h>
#define MAX_VALUE 11
#define Selected 1
#define notSelected 0

using namespace std;

int length;
char signMatrix[MAX_VALUE][MAX_VALUE] = {"1", };
int answer[MAX_VALUE];
int isSelected[MAX_VALUE];

void init() {
    scanf("%d", &length);
    for(int i = 1; i <= length; i++) {
        for(int j = i; j <= length; j++) {
            scanf(" %1c", &signMatrix[i][j]);
        }
    }
    for(int i = 1; i <= length; i++) {
        for(int j = 1; j <= length; j++) {
            printf("%c", signMatrix[i][j]);
        }
        printf("\n");
    }
}

void solve() {
    if(signMatrix[0][0] == '+') {
        for(int i = 1; i <= 10; i++) {
            answer[0] = i;
            isSelected[i] = Selected;
            selectNextNumber(1);
            isSelected[i] = notSelected;
        }
    }
    else if(signMatrix[0][0] == '-') {
        for(int i = -10; i <= -1; i++) {
            answer[0] = i;
            isSelected[i] = Selected;
            selectNextNumber(1);
            isSelected[i] = notSelected;
        }
    }
    else if(signMatrix[0][0] == '0') {
        answer[0] = 0;
            isSelected[0] = Selected;
            selectNextNumber(1);
            isSelected[0] = notSelected;
    }
    // 밑에서 부터 치고 올라오자! 맨밑에 부호보고 범위 결정 후 위로 오면서 범위 좁혀오는 방식으로
}

int main() {
    init();
    solve();
}