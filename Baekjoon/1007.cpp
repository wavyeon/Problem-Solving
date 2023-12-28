#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#define pii pair<int, int> // pair 간결하게 사용하기!
#define MAX 1e9+7
#define endl '\n'
 
using namespace std;
 
int n, test;
vector<pii> points;
double result;
bool visited[21];
 
double vectorSum(){
    pii vec = {0, 0};
    for(int i = 0; i < n; i++){
        if(visited[i]){ // 시작점인 경우
            vec.first -= points[i].first;
            vec.second -= points[i].second;
        }
        else{ // 도착점인 경우
            vec.first += points[i].first;
            vec.second += points[i].second;
        }
    }
    return sqrt(pow(vec.first, 2) + pow(vec.second, 2));
}
 
void dfs(int now, int cnt){
    if(cnt == n/2){
        result = min(result, vectorSum()); // 매번 크기 비교하는 코드 필요 없음!
        return;
    } 
    for(int i = now; i < n; i++){
        visited[i] = true;
        dfs(i+1, cnt+1);
        visited[i] = false;
    }
}
 
void input(){
    int x, y;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        points.push_back({x, y});
    }
}

void solve() {
    cin >> test;
    for(int i = 0; i < test; i++) {
        memset(visited, 0, sizeof(visited));
        points.clear();
        result = MAX; 
        input();
        dfs(0, 0);
        printf("%.7lf\n", result);
    }
} 

int main(){
    solve();    
}

// void matchVector(int curX, int curY, int cnt, int idx) {
//     if(cnt == coordinate.size() / 2) {
//         int allFromX = xSum - curX;
//         int allFromY = ySum - curY;
//         int allToX = curX;
//         int allToY = curY;
//         int a = allToX - allFromX;
//         int b = allToY - allFromY;
//         if(minVal >  sqrt(pow(a, 2) + pow(b, 2))) {
//             minVal = sqrt(pow(a, 2) + pow(b, 2));
//         }
//         return;
//     }
//     for(int i = idx; i < coordinate.size(); i++) {
//         matchVector(curX + coordinate[i].first, curY + coordinate[i].second, cnt + 1, idx + 1);
//         matchVector(curX, curY, cnt, idx + 1);
//     }
// }

// void solve() {
//     cin.tie(0);
//     cout.tie(0);
//     ios::sync_with_stdio(false);
//     cin >> test;
//     for(int i = 0; i < test; i++) {
//         cin >> point;
//         int x, y;
//         xSum = 0;
//         ySum = 0;
//         coordinate.clear();
//         minVal = 2147483647;
//         for(int j = 0; j < point; j++) {
//             cin >> x >> y;
//             coordinate.push_back({x, y});
//             xSum += x;
//             ySum += y;
//         }
//         matchVector(xSum, ySum, 0, 0);
//         cout.precision(20);
//         cout << minVal << endl;
//     }
// }


// void matchVector(int curX, int curY, int cnt) {
//     bool isMatched[coordinate.size()];
//     memset(isMatched, false, sizeof(isMatched));
//     if(cnt == coordinate.size() / 2) { // 모든 벡터 매칭 완료
        // if(minVal >  sqrt(pow(curX, 2) + pow(curY, 2))) {
        //     minVal = sqrt(pow(curX, 2) + pow(curY, 2));
        // }
//         tmp++;
//         // cout << "----------------------------------" << endl;
//         // cout << curX << " " << curY << endl;
//         return;
//     }
//     int fromX, fromY, toX, toY;
//     for(int i = 0; i < coordinate.size(); i++) {
//         if(!isMatched[i]) {
//              fromX = coordinate[i].first;
//              fromY = coordinate[i].second;
//              isMatched[i] = true;
//              if(isMatched[i]) {
//                 for(int j = 0; j < coordinate.size(); j++) {
//                     if(!isMatched[j]) {
//                         toX = coordinate[j].first;
//                         toY = coordinate[j].second;
//                         isMatched[j] = true;
//                         // cout << i << j << endl;
//                         if(isMatched[j]) {
//                             matchVector(curX + (toX - fromX), curY + (toY - fromY), cnt + 1);
//                             isMatched[j] = false;
//                         }
//                     }
//                 }
//                 isMatched[i] = false;
//              }
//         }
//     }
// }

// void solve() {
//     cin.tie(0);
//     cout.tie(0);
//     ios::sync_with_stdio(false);
//     cin >> test;
    // for(int i = 0; i < test; i++) {
    //     cin >> point;
    //     int x, y;
    //     for(int j = 0; j < point; j++) {
    //         cin >> x >> y;
    //         coordinate.push_back({x, y});
    //     }
//         matchVector(0,0,0);
//         cout.precision(20);
//         cout << minVal << endl;
        // coordinate.clear();
        // minVal = 2147483647;
//         // cout << tmp << endl;
//     }
// }