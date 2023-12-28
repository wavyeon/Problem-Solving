#include <iostream>
#include <string>
#include <deque>
#include <cmath>
#define endl '\n'
#define MAX 101

using namespace std;
deque<int> gear[5]; // 앞뒤로 자주 변경될 수열일 경우에는 deque 사용 고려하자!
int rotation;
int rotatedIdx[MAX];
int rotatedDir[MAX];

void input() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 1; i <= 4; i++) {
        string arr;
        cin >> arr;
        for(int j = 0; j < arr.length(); j++) {
            gear[i].push_back(arr[j] - '0');
        }
    }
    cin >> rotation;
    for(int i = 0; i < rotation; i++) {
        cin >> rotatedIdx[i] >> rotatedDir[i];
    }
}   

void rotateSelf(int idx, int dir) {
    if(dir == 1) {
        int tmp = gear[idx].back();
        gear[idx].pop_back();
        gear[idx].push_front(tmp);
    }
    else if(dir == -1) {
        int tmp = gear[idx].front();
        gear[idx].pop_front();
        gear[idx].push_back(tmp);
    }
}

void rotateRightGear(int idx, int dir) {
    if(idx != 4) {
        if(gear[idx][2] != gear[idx+1][6]) {
            rotateRightGear(idx + 1, dir * (-1));
        }
    }
    rotateSelf(idx, dir);
}

void rotateLeftGear(int idx, int dir) {
    if(idx != 1) {
        if(gear[idx][6] != gear[idx-1][2]) {
            rotateLeftGear(idx - 1, dir * (-1));
        }
    }
    rotateSelf(idx, dir);
}

void rotateGear(int idx, int dir) {
    if(idx == 1) {
        if(gear[idx][2] != gear[idx+1][6]) {
            rotateRightGear(idx + 1, dir * (-1));
        }
    }
    else if(idx == 4) {
        if(gear[idx][6] != gear[idx-1][2]) {
            rotateLeftGear(idx - 1, dir * (-1));
        }
    }
    else {
        if(gear[idx][2] != gear[idx+1][6]) {
            rotateRightGear(idx + 1, dir * (-1));
        }
        if(gear[idx][6] != gear[idx-1][2]) {
            rotateLeftGear(idx - 1, dir * (-1));
        }
    }
    rotateSelf(idx, dir);
}

void printScore() {
    int score = 0; 
    for(int i = 1; i <= 4; i++) {
        score += gear[i][0] * pow(2,i-1);
    }
    cout << score << endl;
}

void solve() {
    for(int i = 0; i < rotation; i++) {
        rotateGear(rotatedIdx[i], rotatedDir[i]);
    }
    printScore();
}

int main() {
    input();
    solve();
}