// https://technicolour.tistory.com/19
#include <iostream>

using namespace std;

bool arr[11][11];

void init() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    char bulb;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> bulb;
            if(bulb == 'O') {
                arr[i][j] = true;
            }
        }
    }
}

void copyArr(bool copy[][11], bool original[][11]) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            copy[i][j] = original[i][j];
        }
    }
}

void firstLine(int x, int cnt, bool tmp_arr[][11]) { // 첫번째 줄에 있는 전구의 모든 경우의 수 (2^n)을 체크하는 재귀함수 (dfs)
    if(x == 10) { // 첫번째 줄 완성하면

    }
    else {
        bool toggled_arr[11][11] = {0, };
        copyArr(toggled_arr, tmp_arr);

        bool notToggled_arr[11][11] = {0, };
        copyArr(notToggled_arr, tmp_arr);

        firstLine(x+1, cnt, )
    }
}

void solve() {
    firstLine();
}

int main() {
    init();
    solve();
}








#include <bits/stdc++.h>
using namespace std;
#define MAX 10
#define INF 1e9

bool arr[15][15];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = INF;

bool outrange(int x, int y) {
	if (x < 0 || x >= MAX || y < 0 || y >= MAX) return 1;
	return 0;
}

void toggle(int x, int y, bool tmp_arr[][15]) {
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!outrange(nx, ny)) tmp_arr[nx][ny] = !tmp_arr[nx][ny];
	}
	tmp_arr[x][y] = !tmp_arr[x][y];
}


bool islight(bool tmp_arr[][15]) {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (tmp_arr[i][j]) return 1;
	return 0;
}

void init(bool t_arr1[][15], bool t_arr2[][15], bool t_arr[][15]) {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++) {
			t_arr2[i][j] = t_arr[i][j];
			t_arr1[i][j] = t_arr[i][j];
		}
}

void firstLine(int x, int sum, bool t_arr[][15]) {
	if (x == MAX) {
		//copy
		bool t_arr3[15][15] = { 0, };
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				t_arr3[i][j] = t_arr[i][j];


		//두 번째 ~ 마지막 줄에 대해서 toggle 진행
		for (int i = 1; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (t_arr3[i - 1][j]) {
					toggle(i, j, t_arr3);
					sum++;
				}
			}
		}
		
		//모든 불이 다 꺼져 있으면!
		if (!islight(t_arr3))  ans = min(ans, sum);
		return;
	}

	bool t_arr1[15][15] = { 0, };
	bool t_arr2[15][15] = { 0, };

	//c++ 특성상, 배열의 주소를 넘겨주므로 새로운 함수를 만날 때 마다
	//원 배열의 값이 달라진다. 따라서 계속 copy를 해줘야 됨
	init(t_arr1, t_arr2, t_arr);

	//해당 칸을 안누르고 넘어가는 경우
	firstLine(x + 1, sum, t_arr1);

	//해당 칸을 누르고 넘어가는 경우
	toggle(0, x, t_arr2);
	firstLine(x + 1, sum + 1, t_arr2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
		{
			char c; cin >> c;
			if (c == 'O') arr[i][j] = 1;
		}
	}

	firstLine(0, 0, arr);

	if (ans == INF) cout << -1;
	else cout << ans;
}