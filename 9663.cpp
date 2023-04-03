#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, cnt;
int XforY[16]; // index가 y좌표, value가 x좌표 의미 (행마다 퀸은 하나만 존재하므로 y좌표에 x좌표 매핑)

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
}

void placeQueen(int y) { // y는 현재(유망성을 판단하려는) y값
    if(y == n) {
        cnt++;
        return;
    }
    for(int x = 0; x < n; x++) { // x는 현재(유망성을 판단하려는) x값
        bool available = true;
        for(int row = 0; row < y; row++) { // row는 이전에 결정된 퀸의 y값
            int col = XforY[row]; // col은 이전에 결정된 퀸의 x값
            if(col == x || abs(col - x) == abs(row - y)) {
                // 같은 열에 있진 않은 지, 대각선에 있진 않은 지 체크
                // 한 행에 하나의 퀸만 들어갈 수 있으므로 같은 행에 있는 지는 체크할 필요 없음
                // 따라서 이중 for문 없이 일중 for문으로 해결 가능하다는 것이 핵심
                available = false;
            }
        }
        if (available) { // 이전의 퀸의 위치들을 고려했을 때 놓을 수 있는 위치일 때
            XforY[y] = x; // y열에 퀸 배치
            placeQueen(y+1); // 다음 열로
        }
    }
}

void solve() {
    placeQueen(0);
    cout << cnt << endl;
}

int main() {
    init();
    solve();
}