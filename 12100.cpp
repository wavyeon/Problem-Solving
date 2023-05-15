#include <iostream>
#include <vector>
#include <string.h>
#define MAX 21

using namespace std;

int n, maxResult;
int board[MAX][MAX];

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
}

void moveLeft(int cnt, int board[][MAX], int afterLeft[][MAX]) {
    for(int i = 0; i < n; i++) {
        vector<int> curNums;
        vector<int> addedNums;
        for(int j = 0; j < n; j++) {
            if(board[i][j] != 0) {
                curNums.push_back(board[i][j]);
                if(addedNums.size() == 0) {
                    addedNums.push_back(board[i][j]);
                }
                else {
                    if(curNums[curNums.size()-2] == board[i][j] && addedNums[addedNums.size()-1] == board[i][j]) {
                        addedNums[addedNums.size()-1] *= 2;
                    }
                    else {
                        addedNums.push_back(board[i][j]);
                    }
                }
            }
        }
        for(int j = 0; j < addedNums.size(); j++) {
            afterLeft[i][j] = addedNums[j];
        }
    }
}

void moveRight(int cnt, int board[][MAX], int afterRight[][MAX]) {
    for(int i = 0; i < n; i++) {
        vector<int> curNums;
        vector<int> addedNums;
        for(int j = n-1; j >= 0; j--) {
            if(board[i][j] != 0) {
                curNums.push_back(board[i][j]);
                if(addedNums.size() == 0) {
                    addedNums.push_back(board[i][j]);
                }
                else {
                    if(curNums[curNums.size()-2] == board[i][j] && addedNums[addedNums.size()-1] == board[i][j]) {
                        addedNums[addedNums.size()-1] *= 2;
                    }
                    else {
                        addedNums.push_back(board[i][j]);
                    }
                }
            }
        }
        for(int j = 0; j < addedNums.size(); j++) {
            afterRight[i][n-1-j] = addedNums[j];
        }
    }
}

void moveUp(int cnt, int board[][MAX], int afterUp[][MAX]) {
    for(int i = 0; i < n; i++) {
        vector<int> curNums;
        vector<int> addedNums;
        for(int j = 0; j < n; j++) {
            if(board[j][i] != 0) {
                curNums.push_back(board[j][i]);
                if(addedNums.size() == 0) {
                    addedNums.push_back(board[j][i]);
                }
                else {
                    if(curNums[curNums.size()-2] == board[j][i] && addedNums[addedNums.size()-1] == board[j][i]) {
                        addedNums[addedNums.size()-1] *= 2;
                    }
                    else {
                        addedNums.push_back(board[j][i]);
                    }
                }
            }
        }
        for(int j = 0; j < addedNums.size(); j++) {
            afterUp[j][i] = addedNums[j];
        }
    }
}

void moveDown(int cnt, int board[][MAX], int afterDown[][MAX]) {
    for(int i = 0; i < n; i++) {
        vector<int> curNums;
        vector<int> addedNums;
        for(int j = n-1; j >= 0; j--) {
            if(board[j][i] != 0) {
                curNums.push_back(board[j][i]);
                if(addedNums.size() == 0) {
                    addedNums.push_back(board[j][i]);
                }
                else {
                    if(curNums[curNums.size()-2] == board[j][i] && addedNums[addedNums.size()-1] == board[j][i]) {
                        addedNums[addedNums.size()-1] *= 2;
                    }
                    else {
                        addedNums.push_back(board[j][i]);
                    }
                }
            }
        }
        for(int j = 0; j < addedNums.size(); j++) {
            afterDown[n-1-j][i] = addedNums[j];
        }
    }
}

void game(int cnt, int board[][MAX]) {

    if(cnt == 5) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] > maxResult) {
                    maxResult = board[i][j];
                }
            }
        }
        return;
    }

    int afterLeft[MAX][MAX];
    memset(afterLeft, 0, sizeof(afterLeft));
    moveLeft(cnt, board, afterLeft);
    game(cnt+1, afterLeft);

    int afterRight[MAX][MAX];
    memset(afterRight, 0, sizeof(afterRight));
    moveRight(cnt, board, afterRight);
    game(cnt+1, afterRight);

    int afterUp[MAX][MAX];
    memset(afterUp, 0, sizeof(afterUp));
    moveUp(cnt, board, afterUp);
    game(cnt+1, afterUp);

    int afterDown[MAX][MAX];
    memset(afterDown, 0, sizeof(afterDown));
    moveDown(cnt, board, afterDown);
    game(cnt+1, afterDown);

}

void solve() {
    game(0, board);
    cout << maxResult << endl;
}

int main() {
    input();
    solve();
}