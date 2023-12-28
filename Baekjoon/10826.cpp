#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10001

using namespace std;

int n;
string pibonacci[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    pibonacci[0] = "0";
    pibonacci[1] = "1";
}

string addBigNum(string x, string y) {
    string revX, revY;
    for(int i = x.length()-1; i >= 0; i--) {
        revX += x[i];
    }
    for(int i = y.length()-1; i >= 0; i--) {
        revY += y[i];
    }
    
    string revRes, res;
    string longer = x.length() >= y.length() ? revX : revY;
    string shorter = x.length() >= y.length() ? revY : revX;
    int high = longer.length(); // 길이가 긴 수의 자릿수 (결과값의 자릿수 결정하는데 사용)
    int low = shorter.length(); // 길이가 짧은 수의 자릿수 (까지는 두 수의 각 자릿수를 더해야 함)
    int sum;
    int carry = 0;
    for(int i = 0; i < high; i++) {
        if(i < low) {
            sum = (longer[i] - '0') + (shorter[i] - '0') + carry;
        }
        else {
            sum = (longer[i] - '0') + carry;
        }
        carry = sum / 10;
        revRes += to_string(sum % 10);
    }
    if(carry) {
        revRes += to_string(carry);
    }
    
    for(int i = revRes.length()-1; i >= 0; i--) {
        res += revRes[i];
    }

    return res;
}

void solve() {
    for(int i = 2; i <= n; i++) {
        pibonacci[i] = addBigNum(pibonacci[i-2], pibonacci[i-1]);
    }
    cout << pibonacci[n] << endl;
}

int main() {
    init();
    solve();
}