#include <iostream>
#include <set>
#define MAX 500001

using namespace std;

int card, test;
set<int> numbers;
int check[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> card;
    int num;
    for(int i = 0; i < card; i++) {
        cin >> num;
        numbers.insert(num);
    }
    cin >> test;
    for(int i = 0; i < test; i++) {
        cin >> check[i];
    }
}

void solve() {
    for(int i = 0; i < test; i++) {
        if(numbers.find(check[i]) == numbers.end()) {
            cout << "0 ";
        }
        else {
            cout << "1 ";
        }
    }
}

int main() {
    init();
    solve();
}