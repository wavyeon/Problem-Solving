#include <iostream>
#include <string>
#define MAX 101
#define endl '\n'

using namespace std;


int n, m;
string combi[MAX][MAX]; 

void init() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
}

string addBigNum(string x, string y) {
    cout << x << " " << y << endl;
    string num = "";
    int sum = 0;
    int size = max(x.size(),y.size());

    for(int i=0;i<size || sum;i++){
        if(x.size()>i) sum += x[i]-'0'; // to int
        cout << sum << endl;
        if(y.size()>i) sum += y[i]-'0'; // to int
        cout << sum << endl;

        num += sum%10 +'0'; // to string
        cout << "num: " << num << endl;
        sum /= 10;
        cout << "sum: " << sum << endl;
    }

    return num;
}

void solve() {
    // Top-Down은 재귀, Bottom-Up은 dp 이용함
    // Top-Down은 점화식 이해가 쉽지만 Bottom-Up은 시간과 메모리 사용 면에서 우수함
    // combi[0][0] = "1";
    // combi[1][0] = "1"; combi[1][1] = "1";
    // for(int i = 2; i <= n; i++) {
    //     for(int j = 0; j <= m; j++) {
    //         if (i == j || j==0) {
	// 			combi[i][j] = "1";
	// 		}
    //         else {
	// 			combi[i][j] = addBigNum(combi[i - 1][j - 1], combi[i - 1][j]);
	// 		}
    //     }
    // }
    addBigNum("328", "954");
}

int main() {
    init();
    solve();
}