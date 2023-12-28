// https://technicolour.tistory.com/19
// 누르는 순서 무의미, 최소값을 구하기 위해서는 중복 없어야 함!!
// 따라서 왼쪽 위에서 오른쪽 아래로 순차적으로 접근
#include <iostream>
#define INF 2e9

using namespace std;

bool arr[11][11];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int ans = INF;

void init() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    char bulb;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> bulb;
            if(bulb == 'O') { // 켜져 있는 경우에 true
                arr[i][j] = true;
            }
        }
    }
}

void copyArr(bool copy[][11], bool original[][11]) {
	// c++에서 매개변수로 배열 넘기면 주소 넘어가서 원본 배열 변함
	// 따라서 경우의 수 따질 때마다 임시 배열에 원본 배열을 복사해서 사용
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            copy[i][j] = original[i][j];
        }
    }
}

bool inRange(int x, int y) {
	if(x >= 0 && y >= 0 && x < 10 && y < 10) {
		return true;
	}
	return false;
}

void toggle(bool arr[][11], int x, int y) {
	arr[y][x] = !arr[y][x];
	for(int i = 0; i < 4; i++) {
		int adjacentX = x + dx[i];
		int adjacentY = y + dy[i];
		if(inRange(adjacentX, adjacentY)) {
			arr[adjacentY][adjacentX] = !arr[adjacentY][adjacentX];
		}
	}
}

void firstLine(int x, int cnt, bool tmp_arr[][11]) { // 첫번째 줄에 있는 전구의 모든 경우의 수 (2^n)을 체크하는 재귀함수 (dfs)
    if(x == 10) { // 첫번째 줄 완성하면
		bool firstLineFilledArr[11][11] = {0, };
		copyArr(firstLineFilledArr, tmp_arr);
		for(int i = 1; i < 10; i++) { // 두 번째 줄부터 마지막 줄까지 가면서 최대한 꺼줌
			for(int j = 0; j < 10; j++) {
				if(firstLineFilledArr[i-1][j]) { // 바로 윗 칸이 켜져있으면 이번 칸에서 반드시 꺼줘야함 (지금 아니면 끌 수 있는 경우 더이상 없으므로)
					toggle(firstLineFilledArr, j, i);
					cnt++;
				}
			}
		}
		for(int i = 0; i < 10; i++) {
			if(firstLineFilledArr[9][i] == true) { // 마지막 줄에 아직 안꺼진 전구가 있음 -> 전구 모두 못끄는 경우
				return;
			}
		}
		if(cnt < ans) {
			ans = cnt;
		}
    }
    else { // 아직 완성하지 못했다면 이번 칸 누를지 말고 결정하고 다음 칸으로
		// 이번 칸 누르는 경우
        bool toggled_arr[11][11] = {0, };
        copyArr(toggled_arr, tmp_arr);
		toggle(toggled_arr, x, 0);
		firstLine(x+1, cnt+1, toggled_arr);

		// 이번 칸 누르지 않는 경우
        bool notToggled_arr[11][11] = {0, };
        copyArr(notToggled_arr, tmp_arr);
        firstLine(x+1, cnt, notToggled_arr);
    }
}

void solve() {
    firstLine(0, 0, arr);
	cout << ans << endl;
}

int main() {
    init();
    solve();
}








