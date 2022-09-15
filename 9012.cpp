#include <iostream>
#include <stack>
#include <string.h>
#include <vector>

using namespace std;

stack<char> input;
stack<char> leftP;
stack<char> rightP;
vector<string> answer;
int test;
char ps[51];

void init() {
    scanf("%d", &test);
    cin.ignore();
}

void solve() {
    for(int i = 0; i < test; i++) {
        cin.getline(ps, 51);
        for(int j = 0; j < strlen(ps); j++) {
            input.push(ps[j]);
        }
        while(!input.empty()) {
            if(input.top() == '(') {
                if(!rightP.empty()) {
                    rightP.pop();
                }
                else {
                    leftP.push('(');
                }
            }
            else {
                rightP.push(')');
            }
            input.pop();
        }
        if(rightP.empty() && leftP.empty()) {
            answer.push_back("YES");
        }
        else {
            answer.push_back("NO");
        }
        while(!leftP.empty()) {
            leftP.pop();
        }
        while(!rightP.empty()) {
            rightP.pop();
        }
    }
}

void output() {
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
}

int main() {
    init();
    solve();
    output();
}