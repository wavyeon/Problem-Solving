#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#define pii pair<int, int>
 
using namespace std;
 
int N;
vector<pii> points;
double result;
bool visited[21];
 
double vec_sum(){
    pii vec = {0, 0};
    for(int i = 0; i < N; i++){
        // 시작점인 경우
        if(visited[i]){
            vec.first -= points[i].first;
            vec.second -= points[i].second;
        }
        // 도착점인 경우
        else{
            vec.first += points[i].first;
            vec.second += points[i].second;
        }
    }
    
    return sqrt(pow(vec.first, 2) + pow(vec.second, 2));
}
 
void dfs(int now, int cnt){
    if(cnt == N/2){
        result = min(result, vec_sum());
        return;
    } 
    
    for(int i = now; i < N; i++){
        visited[i] = true;
        dfs(i+1, cnt+1);
        visited[i] = false;
    }
}
 
void input(){
    int a, b;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        points.push_back({a, b});
    }
}
 
int main(){
    int test;
    cin >> test;
    while(test--){
        memset(visited, 0, sizeof(visited));
        points.clear();
        result = 1e9+7;
    
        input();
        
        dfs(0, 0);
        printf("%.7lf\n", result);
    }
    
    return 0;
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

int main() {
    solve();
}