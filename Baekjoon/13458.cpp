#include <iostream>
#define endl '\n'
#define MAX 1000001

using namespace std;

int room, general, sub;
int tester[MAX];
long long cnt;

void input() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> room;
    for(int i = 0; i < room; i++) {
        cin >> tester[i];
    }
    cin >> general >> sub;
}

void solve() {
    for(int i = 0; i < room; i++) {
        int chargeOfSub = tester[i] - general;
        if(chargeOfSub <= 0) { // 총감독관으로 모두 감당 가능
            cnt += 1;
        } 
        else {
            if(chargeOfSub <= sub) { // 부감독관 한 명만 더 있으면 됨
                cnt += 2;
            }
            else { // 부감독관 여러 명 필요
                if(chargeOfSub % sub == 0) {
                    cnt += (chargeOfSub / sub + 1); 
                }
                else {
                    cnt += (chargeOfSub / sub + 2);
                }
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    input();
    solve();
}