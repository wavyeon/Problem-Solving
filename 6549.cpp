#include <iostream>
#include <stack>
#include <vector>
#define MAX 100001
#define endl '\n'

using namespace std;

long long histogram[MAX];
stack<long long> leftS, rightS;
vector<long long> answer;
int maxArea;

void findMaxSquare(int num) {
    for(int i = 0; i < num; i++) {
        long long leftwidth = 0;
        long long rightwidth = 0;
        long long height = rightS.top();
        stack<long long> tmpleft = leftS;
        stack<long long> tmpright = rightS;
        while(!tmpleft.empty() && tmpleft.top() >= height) {
            leftwidth++;
            tmpleft.pop();
        }
        while(!tmpright.empty() && tmpright.top() >= height) {
            rightwidth++;
            tmpright.pop();
        }
        if((leftwidth+rightwidth) * height > maxArea) {
            maxArea = (leftwidth+rightwidth) * height;
        }
        leftS.push(rightS.top());
        rightS.pop();
        // cout << height << " " << leftwidth << " " << rightwidth << " " << maxArea << endl;
    }
}

void solve() {
    int num;
    while(true) {
        cin >> num;
        if(num == 0) {
            break;
        }
        else {
            for(int i = 0; i < num; i++) {
                cin >> histogram[i];
            }
            for(int i = num-1; i >= 0; i--) {
                rightS.push(histogram[i]);
            }
            findMaxSquare(num);
        }
        answer.push_back(maxArea);
        maxArea = 0;
    }
    // cout << answer.size() << endl;
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}

int main() {
    solve();
}