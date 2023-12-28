#include <iostream>
#include <string.h>
#define MAX_VALUE 11
#define isVisited 1
#define notVisited 0

using namespace std;

int n, m, k;
int board[MAX_VALUE][MAX_VALUE];
int visited[MAX_VALUE][MAX_VALUE] = {notVisited, };
int output[3];
int maxOutput = 0;

void init() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}

void setVisited() {
    for(int i = 0; i < n; i++) {
        memset(visited[i], notVisited, sizeof(int)*m);
    }
}

// void solve(int startY, int startX, int count) {
//     cout << startY << startX << count << endl;
//     if(count == k) {
//         cout << output[0] << output[1] << output[2] << endl;
//         int curMax = output[0] + output[1] + output[2];
//         if(curMax > maxOutput) {
//             maxOutput = curMax;
//         }
//     }
//     // int i = startY;
//     // int j = startX
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             cout << "현재" << i << j << endl;

//             for(int y = 0; y < n; y++) {
//                     for(int x = 0; x < m; x++) {
//                        cout << visited[y][x] << " ";
//                     }
//                     cout << endl;
//                 }

//             if(visited[i][j] == notVisited) {
//                 cout << "방문함" << endl;
//                 visited[i][j] = isVisited;
//                 bool leftFlag, upFlag, rightFlag, downFlag = false;
//                 if(i-1 >= 0) {
//                     visited[i-1][j] = isVisited;
//                     upFlag = true;
//                 }
//                 if(i+1 < n) {
//                     visited[i+1][j] = isVisited;
//                     downFlag = true;
//                 }
//                 if(j-1 >= 0) {
//                     visited[i][j-1] = isVisited;
//                     leftFlag = true;
//                 }
//                 if(j+1 < m) {
//                     visited[i][j+1] = isVisited;
//                     rightFlag = true;
//                 }

//                 for(int y = 0; y < n; y++) {
//                     for(int x = 0; x < m; x++) {
//                        cout << visited[y][x] << " ";
//                     }
//                     cout << endl;
//                 }

//                 output[count] = board[i][j];
//                 if(j+1 == m) {
//                     cout << "!!!!!!!!!!!!11111" << endl;
//                     solve(i+1, 0, count+1);
//                 }
//                 else {
//                     solve(i, j+1, count+1);
//                 }

                

//                 visited[i][j] = notVisited;
//                 if(upFlag) {
//                     visited[i-1][j] = notVisited;
//                 }
//                 if(downFlag) {
//                     visited[i+1][j] = notVisited;
//                 }
//                 if(leftFlag) {
//                     visited[i][j-1] = notVisited;
//                 }
//                 if(rightFlag) {
//                     visited[i][j+1] = notVisited;
//                 }
//             }
//         }
//     }
// }

void solve(int startIdx, int count) {
    cout << startIdx/m << startIdx%m << count << endl;
    if(count == k) {
        cout << "here! " << output[0] << output[1] << output[2] << endl;
        int curMax = output[0] + output[1] + output[2];
        if(curMax > maxOutput) {
            maxOutput = curMax;
        }
    }
    // int i = startY;
    // int j = startX
    for(int idx = startIdx; idx < n*m; idx++) {
        int i = idx/m;
        int j = idx%m;
    // for(int i = ; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << "현재" << i << j << endl;

            for(int y = 0; y < n; y++) {
                    for(int x = 0; x < m; x++) {
                       cout << visited[y][x] << " ";
                    }
                    cout << endl;
                }

            if(visited[i][j] == notVisited) {
                cout << "방문함" << endl;
                visited[i][j] = isVisited;
                bool leftFlag, upFlag, rightFlag, downFlag = false;
                if(i-1 >= 0) {
                    visited[i-1][j] = isVisited;
                    upFlag = true;
                }
                if(i+1 < n) {
                    visited[i+1][j] = isVisited;
                    downFlag = true;
                }
                if(j-1 >= 0) {
                    visited[i][j-1] = isVisited;
                    leftFlag = true;
                }
                if(j+1 < m) {
                    visited[i][j+1] = isVisited;
                    rightFlag = true;
                }

                for(int y = 0; y < n; y++) {
                    for(int x = 0; x < m; x++) {
                       cout << visited[y][x] << " ";
                    }
                    cout << endl;
                }

                output[count] = board[i][j];
                solve(idx+1, count+1);
                // if(j+1 == m) {
                //     cout << "!!!!!!!!!!!!11111" << endl;
                //     solve(i+1, 0, count+1);
                // }
                // else {
                //     solve(i, j+1, count+1);
                // }

                

                visited[i][j] = notVisited;
                if(upFlag) {
                    visited[i-1][j] = notVisited;
                }
                if(downFlag) {
                    visited[i+1][j] = notVisited;
                }
                if(leftFlag) {
                    visited[i][j-1] = notVisited;
                }
                if(rightFlag) {
                    visited[i][j+1] = notVisited;
                }
            }
        }
    // }
}

int main() {
    init();
    for(int idx = 0; idx < n*m; idx++) {
        solve(idx, 0);
        setVisited;
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         solve(i, j, 0);
    //         setVisited();
    //     }
    // }
    printf("%d", maxOutput);
}