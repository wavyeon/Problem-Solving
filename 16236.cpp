#include <iostream>
#include <queue>
#define MAX 21

using namespace std;

typedef struct {
    int time;
    int x;
    int y;
} shark;

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
bool findFishAndMove() {
    if(fishCount == 0) {
        return false;
    }
    priority_queue<shark, vector<shark>, greater<shark>> q;
    bool visited[MAX][MAX] = {false, };
    shark start = {huntTime, startX, startY};
    visited[startY][startX] = true;
    q.push(start);
    while(!q.empty()) {
        shark cur = q.top();
        q.pop();
        int check = ocean[cur.y][cur.x];
        if(check > 0 && check < 7 && check < curSize) {
            startX = cur.x;
            startY = cur.y;
            huntTime = cur.time;
            ocean[cur.y][cur.x] = 0;
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
            nextX = cur.x + dx[i];
            nextY = cur.y + dy[i];
            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
                if(visited[nextY][nextX] == false) {
                    int target = ocean[nextY][nextX];
                    if(target == 0 || target == curSize || target == 9 || (target > 0 && target < 7 && target < curSize)) {// 빈 공간, 같은 크기의 물고기, 출발한 공간, 먹을 수 있는 물고기
                        shark next = {cur.time+1, nextX, nextY};
                        visited[nextY][nextX] = true;
                        q.push(next);
                        // if(cur.x == 2 && cur.y == 0) {
                        //     cout << "!" << nextX << " " << nextY << "!" << endl;
                        // }
                        // if(cur.x == 3 && cur.y == 0) {
                        //     cout << "!" << nextX << " " << nextY << "!" << endl;
                        // }
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
        cout << startX << " " << startY << " " << huntTime << " " << curSize << endl;
        // if(startX == 1 && startY == 3) {
        //     for(int i = 0; i < n; i++) {
        //         for(int j = 0; j < n; j++) {
        //             cout << ocean[i][j] << " ";
        //         }
        //         cout << endl;
        //     }
        // }
        fishExist = findFishAndMove();
    }
    cout << huntTime << endl;
}

// bool isFishExist(int x, int y) {
    
//     return findFish(x, y);
// }

// void moveShark(int x, int y) {

// }

// void solve() {
//     while(true) {
//         if(!isFishExist(startX, startY)) { // 물고기가 없는 경우
//             cout << huntTime << endl;
//             return;
//         }
//         else { // 물고기가 있는 경우
//             moveShark(startX, startY);
//         }
//     }
    

//     if(fishCount == 0) {
//         cout << time << endl;
//     }

//     whereToMove();

//     queue<shark> move;
    


// }

int main() {
    init();
    solve();
}