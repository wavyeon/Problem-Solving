#include <iostream>
#include <cmath>
#define endl '\n'
#define MAX 100001

using namespace std;

int n;
int solution[MAX];

void init() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> solution[i];
    }
}

void solve() {
    int alk, acd;
    int chrVal = 2000000001;
    int first = 0;
    int second = n-1;
    while(first != second) {
        int tmp = solution[first] + solution[second]; 
        if(abs(tmp) < chrVal) {
            chrVal = abs(tmp);
            alk = solution[first];
            acd = solution[second];
        }
        if(tmp > 0) {
            second--;
        }
        else if(tmp < 0) {
            first++;
        }
        else {
            break;
        }
    }
    cout << alk << " " << acd << endl;
}

int main() {
    init();
    solve();
}