#include <iostream>
#define MAX 1000001
#define endl '\n'

using namespace std;

int n, s, cnt;
int arr[MAX];
bool selected[MAX];

void select(int idx, int sum) {
    if(idx == n) {
        return;
    }
    for(int i = idx; i < n; i++) {
        if(selected[i] == false) {
            selected[i] = true;
            if(sum + arr[i] == s) {
                cnt++;
            }
            select(i+1, sum + arr[i]);
            selected[i] = false;
        }
    }
}

void solve() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    select(0, 0);
    cout << cnt << endl;
}

int main() {
    solve();
}