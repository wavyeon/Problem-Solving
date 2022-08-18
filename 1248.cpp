#include <iostream>
#include <stdlib.h>
#define MAX_VALUE 11

using namespace std;

int length;
char signMatrix[MAX_VALUE][MAX_VALUE];
int answer[MAX_VALUE];
// int isSelected[MAX_VALUE];
bool answerFound = false;

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

int arraySum(int i, int j) {
    int result = 0;
    for(int k = i; k <= j; k++) {
        result += answer[k];
    }
    return result;
}

bool isAvaliableNum(int sum, char sign) {
    if( (sum > 0 && sign == '+') || (sum == 0 && sign == '0') || (sum < 0 && sign == '-') ) {
        return true;
    }
    else {
        return false;
    }
}

void solve(index idx) {
    if(answerFound == true) {
        return;
    }
    else {
        bool avaliable = true;
        if(idx == length+1) {
            for(int i = 1; i <= length; i++) {
                printf("%d ", answer[i]);
            }
            answerFound = true;
        }
        else {
            if(signMatrix[idx][idx] == '+') {
                for(int i = 1; i <= 10; i++) {
                    for(int j = idx-1; j >= 1; j--) {
                        avaliable = isAvaliableNum( arraySum(i, j), signMatrix[i][j] ); 
                    }
                    if(avaliable == true) {
                        answer[idx] = 
                    }
                    else if(avaliable == false) {
                        avaliable = true;
                        continue;
                    }
                }
            }
            else if(signMatrix[idx][idx] == '-') {
                for(int i = -10; i <= -1; i++) {

                }
            }
            else if(signMatrix[idx][idx] == '0') {
                
            }
            
        }
    }
    
    else {
        if(signMatrix[i][i] == '+') {
            for(int i = 1; i <= 10; i++) {

            }
        }
        else if(signMatrix[i][i] == '-') {
            
        }
        else if(signMatrix[i][i] == '0') {
            
        }
    }
}

void solve() {
    if(signMatrix[1][1] == '+') {
        for(int i = 1; i <= 10; i++) {
            answer[1] = i;
            isSelected[i] = Selected;
            selectNextNumber(2);
            isSelected[i] = notSelected;
        }
    }
    else if(signMatrix[1][1] == '-') {
        for(int i = -10; i <= -1; i++) {
            answer[1] = i;
            isSelected[i] = Selected;
            selectNextNumber(2);
            isSelected[i] = notSelected;
        }
    }
    else if(signMatrix[1][1] == '0') {
            answer[1] = 0;
            isSelected[0] = Selected;
            selectNextNumber(2);
            isSelected[0] = notSelected;
    }
    // 밑에서 부터 치고 올라오자! 맨밑에 부호보고 범위 결정 후 위로 오면서 범위 좁혀오는 방식으로
}

int main() {
    init();
    solve();
}