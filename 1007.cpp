#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#define endl '\n'

using namespace std;
int test, point;
// float minVal = 1.7976931348623157E + 308;
float minVal =  2147483647;
vector<pair<int, int>> coordinate;
int tmp;

void matchVector(int curX, int curY, int cnt) {
    bool isMatched[coordinate.size()];
    memset(isMatched, false, sizeof(isMatched));
    if(cnt == coordinate.size() / 2) { // 모든 벡터 매칭 완료
        if(minVal >  sqrt(pow(curX, 2) + pow(curY, 2))) {
            minVal = sqrt(pow(curX, 2) + pow(curY, 2));
        }
        tmp++;
        // cout << "----------------------------------" << endl;
        // cout << curX << " " << curY << endl;
        return;
    }
    int fromX, fromY, toX, toY;
    for(int i = 0; i < coordinate.size(); i++) {
        if(!isMatched[i]) {
             fromX = coordinate[i].first;
             fromY = coordinate[i].second;
             isMatched[i] = true;
             if(isMatched[i]) {
                for(int j = 0; j < coordinate.size(); j++) {
                    if(!isMatched[j]) {
                        toX = coordinate[j].first;
                        toY = coordinate[j].second;
                        isMatched[j] = true;
                        // cout << i << j << endl;
                        if(isMatched[j]) {
                            matchVector(curX + (toX - fromX), curY + (toY - fromY), cnt + 1);
                            isMatched[j] = false;
                        }
                    }
                }
                isMatched[i] = false;
             }
        }
    }
}

void solve() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> test;
    for(int i = 0; i < test; i++) {
        cin >> point;
        int x, y;
        for(int j = 0; j < point; j++) {
            cin >> x >> y;
            coordinate.push_back({x, y});
        }
        matchVector(0,0,0);
        cout.precision(20);
        cout << minVal << endl;
        coordinate.clear();
        minVal = 2147483647;
        // cout << tmp << endl;
    }
}

int main() {
    solve();
}

// 1
// 4
// 1 1
// 2 2
// 3 3
// 4 4