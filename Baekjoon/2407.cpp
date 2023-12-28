#include <iostream>
#include <string>
#include <algorithm>
#define MAX 101
#define endl '\n'

using namespace std;

int n, m, sum;
string combi[MAX][MAX]; 

void init() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
}

string addBigNum(string x, string y) {
    // long long 으로도 감당 안될때는 string을 이용해 큰 수 덧셈을 구현하자
    string num = "";
    reverse(x.begin(), x.end()); // string을 뒤집어 주는 reverse 함수 이용
    reverse(y.begin(), y.end()); // void형이며 매개변수로 시작 위치와, 끝 위치를 받음
    for(int i = 0; i < max(x.length(), y.length()) || sum > 0; i++) {  // sum > 0이 붙는 이유는 자릿수가 추가되는 경우가 있기 때문
        if(i < x.size()) {
            sum += (x[i] - '0');
        }
        if(i < y.size()) {
            sum += (y[i] - '0');
        }
        num += (sum % 10 + '0');
        sum /= 10;
    } // sum을 재사용하는 것에 주목하자
    reverse(num.begin(), num.end());
    return num;
}

void solve() {
    // Top-Down은 재귀, Bottom-Up은 dp 이용함
    // Top-Down은 점화식 이해가 쉽지만 Bottom-Up은 시간과 메모리 사용 면에서 우수함
    combi[0][0] = "1";
    combi[1][0] = "1"; combi[1][1] = "1";
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= m; j++) { // nCm을 구할 때는 n-1Cm-1과 n-1Cm이 필요하므로 n번 돌 필요 없이 m번만 돌아도 값을 구할 수 있다
            if (i == j || j==0) {
				combi[i][j] = "1";
			}
            else {
				combi[i][j] = addBigNum(combi[i - 1][j - 1], combi[i - 1][j]);
			}
        }
    }
    cout << combi[n][m] << endl;
}

int main() {
    init();
    solve();
}