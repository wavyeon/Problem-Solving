#include <iostream>
#include <cmath>

using namespace std;


int blockSize, N, x, y, count;
// int Zblock[32768][32768];

void init() {
    cin >> N >> y >> x;
    blockSize = pow(2,N);
}

void solve(int side, int startY, int startX) {
    // cout << startY << " " << startX << " " << count << endl;
    if(side == 1) {
        if(startY == y && startX == x) {
            cout << count << endl;
        }
        else {
            count++;
        }
        if(startY == y && startX+1 == x) {
            cout << count << endl;
        }
        else {
            count++;
        }
        if(startY+1 == y && startX == x) {
            cout << count << endl;
        }
        else {
            count++;
        }
        if(startY+1 == y && startX+1 == x) {
            cout << count << endl;
        }
        else {
            count++;
        }
        // Zblock[startY][startX] = count++;
        // Zblock[startY][startX+1] = count++;
        // Zblock[startY+1][startX] = count++;
        // Zblock[startY+1][startX+1] = count++;
    }
    else {
        solve(side/2, startY, startX);
        solve(side/2, startY, startX + side);
        solve(side/2, startY + side, startX);
        solve(side/2, startY + side, startX + side);
    }
}

int main() {
    init();
    solve(blockSize/2, 0, 0);
}