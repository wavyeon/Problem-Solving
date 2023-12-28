#include <iostream>
#define MAX 12
#define endl '\n'

using namespace std;

int n;
int operands[MAX];
int operators[4];
int minResult = 1000000001;
int maxResult = -1000000001;

void input() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> operands[i];
    }
    for(int i = 0; i < 4; i++) {
        cin >> operators[i];
    }
}

void dfs(int curResult, int idx, int curOperator[4]) {
    if(idx == n) { // 모든 연산자 소모
        if(curResult < minResult) {
            minResult = curResult;
        }
        if(curResult > maxResult) {
            maxResult = curResult;
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        if(curOperator[i]) { // 해당 연산자가 남아있다면
            int nextResult;
            int nextOperator[4];
            for(int i = 0; i < 4; i++) { // 연산자 배열 복사 (재귀함수의 매개변수로 넘겨주기 위해)
                nextOperator[i] = curOperator[i];
            }
            switch (i) {
                case 0:
                    nextResult = curResult + operands[idx];
                    break;
                case 1:
                    nextResult = curResult - operands[idx];
                    break;
                case 2:
                    nextResult = curResult * operands[idx];
                    break;
                case 3:
                    nextResult = curResult / operands[idx];
                    break;
            }
            nextOperator[i]--;
            dfs(nextResult, idx+1, nextOperator);
        }
    }
}

void solve() {
    dfs(operands[0], 1, operators);
    cout << maxResult << endl << minResult << endl;
}

int main() {
    input();
    solve();
}