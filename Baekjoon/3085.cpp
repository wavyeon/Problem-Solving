#include <iostream>
#define MAX_SIZE 50

using namespace std;

void init(int size);
char board [MAX_SIZE][MAX_SIZE];
void solve(int size);
void swap(int i, int j, int size);
void check(int size);
int maxCandy = 0;

int main() {
    int size;
    cin >> size;
    init(size);
    solve(size);
}

void init(int size) {
    for(int i = 0; i < size; i++) {
        char* row = new char[size+1];
        cin >> row;
        for(int j = 0; j < size; j++) {
        board[i][j] = row[j];
        }
    }
}

void check(int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            int verLength = 1;
            int horLength = 1;
            int up = i; int down = i;
            int left = j; int right = j;
            while( (up-1 >= 0) && (board[up-1][j] == board[up][j]) )  {
                verLength++;
                up--;
            }
            while ( (down+1 < size) && (board[down+1][j] == board[down][j]) ) {
                verLength++;
                down++;
            }
            while ( (left-1 >= 0) && (board[i][left-1] == board[i][left]) ) {
                horLength++;
                left--;
            }
            while ( (right+1 < 0) && (board[i][right+1] == board[i][right]) ) {
                horLength++;
                right++;
            }
            if(verLength > maxCandy) {
                maxCandy = verLength;
            }
            if(horLength > maxCandy) {
                maxCandy = horLength;
            } 
        }
    }
}

void swap(int i, int j, int size) {
    char tmp;
    if( (i-1 >= 0) && (board[i][j] != board[i-1][j]) ) {
        // cout << i << j << "up" << endl;
        tmp = board[i-1][j];
        board[i-1][j] = board[i][j];
        board[i][j] = tmp;
        check(size);
        tmp = board[i-1][j];
        board[i-1][j] = board[i][j];
        board[i][j] = tmp;
    }
    if( (j+1 < size) && (board[i][j] != board[i][j+1]) ) {
        // cout << i << j << "right" << endl;
        tmp = board[i][j+1];
        board[i][j+1] = board[i][j];
        board[i][j] = tmp;
        check(size);
        tmp = board[i][j+1];
        board[i][j+1] = board[i][j];
        board[i][j] = tmp;
    }
    if( (i+1 < size) && (board[i][j] != board[i+1][j]) ) {
        // cout << i << j << "down" << endl;
        tmp = board[i+1][j];
        board[i+1][j] = board[i][j];
        board[i][j] = tmp;
        check(size);
        tmp = board[i+1][j];
        board[i+1][j] = board[i][j];
        board[i][j] = tmp;
    }
    if( (j-1 >= 0) && (board[i][j] != board[i][j-1]) ) {
        // cout << i << j << "left" << endl;
        tmp = board[i][j-1];
        board[i][j-1] = board[i][j];
        board[i][j] = tmp;
        check(size);
        tmp = board[i][j-1];
        board[i][j-1] = board[i][j];
        board[i][j] = tmp;
    }
}

void solve(int size) {
    // swap(0, 0, size);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            swap(i, j, size);
        }
    }
    cout << maxCandy << endl;
}