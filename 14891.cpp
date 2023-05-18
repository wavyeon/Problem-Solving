#include <iostream>
#include <string>
#define endl '\n'
#define MAX 101

using namespace std;

int gear[5][9];
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
            gear[i][j] = arr[j] - '0';
        }
    }
    cin >> rotation;
    for(int i = 0; i < rotation; i++) {
        cin >> rotatedIdx[i] >> rotatedDir[i];
    }
}   

void rotateRightGear() {

}

void rotateLeftGear() {

}

void rotateGear(int idx, int dir) {
    if(idx == 1) {
        if(gear[idx][2] != gear[idx+1][6]) {
            rotateRightGear();
        }
    }
    else if(idx == 4) {
        if(gear[idx][6] != gear[idx-1][2]) {
            rotateLeftGear();
        }
    }
    else {
        if(gear[idx][2] != gear[idx+1][6]) {
            rotateRightGear();
        }
        if(gear[idx][6] != gear[idx-1][2]) {
            rotateLeftGear();
        }
    }
    if(dir == 1) {
        int tmp[8];
        tmp = {gear[idx][7], gear[idx][0], gear[idx][1], gear[idx][2], 
                    gear[idx][3], gear[idx][4], gear[idx][5], gear[idx][6]};
    }
    else if(dir == -1) {

    }
    
}

void solve() {
    for(int i = 0; i < rotation; i++) {
        rotateGear(rotatedIdx[i], rotatedDir[i]);
    }
    // 점수 계산
}

int main() {
    input();
    solve();
}