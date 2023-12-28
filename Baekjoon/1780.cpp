// 분할정복인 것 인지하면서 코드 짜자!

// #include <iostream>
// #include <cmath>
// #include <vector>
// #define MAX 2188

// using namespace std;

// int n, paperSize;
// int paper[MAX][MAX];
// int ans[4]; // -1, 0, 1, 2 색종이의 개수

// void init() {
//     cin.tie(0); cout.tie(0);
//     ios::sync_with_stdio(false);
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             cin >> paper[i][j];
//         }
//     }
// }

// int cutPaper(int x, int y, int sz) {
//     if(sz == 1) {
//         return paper[y][x];      
//     }
//     int dist = sz / 3;
//     int slice[3][3];
//     int rep = paper[y][x]; // 대표값
//     int sliceY = 0;
//     for(int i = y; i < y + sz; i += dist) {
//         int sliceX = 0;
//         for(int j = x; j < x + sz; j += dist) {
//             slice[sliceY][sliceX] = cutPaper(j, i, dist);
//             sliceX++;
//         }
//         sliceY++;
//     }
//     for(int i = 0; i < 3; i++) {
//         for(int j = 0; j < 3; j++) {
//             if(slice[i][j] != rep) { // 종이를 9등분 해야하는 경우
//                 for(int m = 0; m < 3; m++) {
//                     for(int k = 0; k < 3; k++) {
//                         ans[slice[m][k] + 1]++;
//                     }
//                 }
//                 return 2;
//             }
//         }
//     }
//     return rep;
// }

// void solve() {
//     int tmp = cutPaper(0, 0, n);
//     if(tmp != 2) {
//         ans[tmp+1]++;
//     }
    // for(int i = 0; i < 3; i++) {
    //     cout << ans[i] << endl;
    // }
// }

// int main() {
//     init();
//     solve();
// }

#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 2188

using namespace std;

int n;
int ans[3];
int paper[MAX][MAX];

// 단위 종이 내 모든 칸들이 모두 같은지 아닌지 판단하는 함수
bool check(int row, int col, int num) {
	int rep = paper[row][col];
	for (int i = row; i < row + num; i++) {
		for (int j = col; j < col + num; j++) {
			if (rep != paper[i][j])
				return false;
		}
	}
	return true;
}

// 9분할로 나눠보는 함수
void divide(int row, int col, int num) {
	// 지금 단위 종이 내 모든 칸들의 값이 같을 경우
	if (check(row, col, num)) {
		ans[paper[row][col] + 1]++;
	}
	else {
		// 새로운 단위사이즈를 만든다.
		int size = num / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(row + size * i, col + size * j, size);
			}
		}
	}
}

void init() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
}

void solve() {
    divide(0, 0, n);
    for(int i = 0; i < 3; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    init();
    solve();
}