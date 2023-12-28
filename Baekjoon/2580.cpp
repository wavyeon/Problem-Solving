#include <iostream>

using namespace std;

int puzzle[9][9];
bool visited_3x3[3][3][10];
bool visited_ver9[9][10];
bool visited_hor9[9][10];

void init() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> puzzle[i][j];
            if(puzzle[i][j] != 0) {
                visited_3x3[i/3][j/3][puzzle[i][j]] = true;
                visited_hor9[i][puzzle[i][j]] = true;
                visited_ver9[j][puzzle[i][j]] = true;
            }
        }
    }
}

void checkVisit(int i, int j, int val) {
    visited_hor9[i][val] = true;
    visited_ver9[j][val] = true;
    visited_3x3[i/3][j/3][val] = true;
    puzzle[i][j] = val;
}

void uncheckVisit(int i, int j, int val) {
    visited_hor9[i][val] = false;
    visited_ver9[j][val] = false;
    visited_3x3[i/3][j/3][val] = false;
    puzzle[i][j] = 0;
}

bool isVisitable(int i, int j, int val) {
    if(visited_hor9[i][val] == false) {
        if(visited_ver9[j][val] == false) {
            if(visited_3x3[i/3][j/3][val] == false) {
                return true;
            }
        }
    }
    return false;
}

void print() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << puzzle[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int cur) {
    if(cur == 81) {
        print();
        exit(0);
    }
    int i = cur / 9;
    int j = cur % 9;
    if(puzzle[i][j] == 0) {
        for(int k = 1; k <= 9; k++) {
            if(isVisitable(i, j, k)) {
                checkVisit(i, j, k);
                solve(cur+1);
                uncheckVisit(i, j, k);
            }
        }
    }
    else {
        solve(cur+1);
    }
}

int main() {
    init();
    solve(0);
}
