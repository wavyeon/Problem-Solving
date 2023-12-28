#include <iostream>
#include <queue>
#define MAX 21

using namespace std;

int n, fishCount, startX, startY, huntTime, eatenFish;
int curSize = 2;
int ocean[MAX][MAX];
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
bool fishExist = true;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> ocean[i][j];
            if(ocean[i][j] > 0 && ocean[i][j] < 7) {
                fishCount++;
            }
            else if(ocean[i][j] == 9) {
                startX = j;
                startY = i;
            }
        }
    }
}

// priority queue 써야함! struct 대신 pair 사용하는 식으로 ㄱㄱ
// make_pair 보다 쉬운 초기화 방법?
// 구조체 쓰면서 priority_queue를 쓰는 방법?
// 1934번도 풀이하자잉
// 최소 공배수를 구하는 새로운 방법 get
bool findFishAndMove() {
    if(fishCount == 0) {
        return false;
    }
    priority_queue< pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>> > pq;
    bool visited[MAX][MAX] = {false, };
    visited[startY][startX] = true;
    pq.push(make_pair(huntTime, make_pair(startY, startX)));
    while(!pq.empty()) {
        int curX = pq.top().second.second;
        int curY = pq.top().second.first;
        int curTime = pq.top().first;
        pq.pop();
        int check = ocean[curY][curX];
        if(check > 0 && check < 7 && check < curSize) { // 물고기 먹음
            startX = curX;
            startY = curY;
            huntTime = curTime;
            ocean[curY][curX] = 0;
            eatenFish++;
            if(eatenFish == curSize) {
                curSize++;
                eatenFish = 0;
            }
            fishCount--;
            return true;
        }
        int nextX, nextY;
        for(int i = 0; i < 4; i++) {
            nextX = curX + dx[i];
            nextY = curY + dy[i];
            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
                if(visited[nextY][nextX] == false) {
                    int target = ocean[nextY][nextX];
                    if(target == 0 || target == curSize || target == 9 || (target > 0 && target < 7 && target < curSize)) {// 빈 공간, 같은 크기의 물고기, 출발한 공간, 먹을 수 있는 물고기
                        visited[nextY][nextX] = true;
                        pq.push(make_pair(curTime+1, make_pair(nextY, nextX)));
                    }
                }
            }

        }
    }
    return false;
}

// 발견했을 때 바로 값 바꾸지 말고 queue에 넣은 후 cur에서 발견했을 때 값 바꾸는 식으로 ㄱㄱ
void solve() {
    while(fishExist) {
        fishExist = findFishAndMove();
    }
    cout << huntTime << endl;
}

int main() {
    init();
    solve();
}