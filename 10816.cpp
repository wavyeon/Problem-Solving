#include <iostream>
#include <map>
#define MAX 500001

using namespace std;

int card, test;
map<int, int> numbers;
int answer[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> card;
    int num;
    for(int i = 0; i < card; i++) {
        cin >> num;
        numbers[num]++;
    }
    cin >> test;
}

void solve() {
    int check;
    for(int i = 0; i < test; i++) {
        cin >> check;
        answer[i] = numbers[check];
    }
    for(int i = 0; i < test; i++) {
        cout << answer[i] << " ";
    }
}

int main() {
    init();
    solve();
}