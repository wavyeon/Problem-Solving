#include <iostream>

using namespace std;

int prime[1001];

void solve() {
    prime[1] = 1;
    for(int i = 2; i <= 1000; i++) {
        int tmp = i;
        while(tmp <= 1000) {
            tmp += i;
            if(tmp <= 1000)
                prime[tmp] = 1;
        }
    }
    int len;
    cin >> len;
    int* num = new int[len];
    for(int i = 0; i < len; i++) {
        cin >> num[i];
    }
    int count = 0;
    for(int i = 0; i < len; i++) {
        if(prime[num[i]] == 0) {
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    solve();
}