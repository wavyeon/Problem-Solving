#include <iostream>
#include <queue>
#define MAX 21

using namespace std;

typedef struct {
    int x;
    int y;
    int time;
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

// 더 이상 먹을 물고기가 있는 지 판단
// fishCount == 0 이거나 그래프 탐색을 마쳤는데도 먹을 물고기가 없는 경우임

bool findFishAndMove() {
    if(fishCount == 0) {
        return false;
    }
    queue<shark> q;
    bool visited[MAX][MAX] = {false, };
    shark start = {startX, startY, huntTime};
    visited[startY][startX] = true;
    q.push(start);
    while(!q.empty()) {
        shark cur = q.front();
        q.pop();
        int nextX, nextY;
        for(int i = 0; i < 4; i++) {
            nextX = cur.x + dx[i];
            nextY = cur.y + dy[i];
            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
                if(visited[nextY][nextX] == false) {
                    if(ocean[nextY][nextX] > 0 && ocean[nextY][nextX] < 7 && ocean[nextY][nextX] < curSize) { // 먹을 수 있는 물고기 발견
                        startX = nextX;
                        startY = nextY;
                        huntTime = cur.time+1;
                        ocean[nextY][nextX] = 0;
                        if(ocean[cur.y][cur.x] = 9) {
                            ocean[cur.y][cur.x] = 0;
                        }
                        eatenFish++;
                        if(eatenFish == curSize) {
                            curSize++;
                            eatenFish = 0;
                        }
                        return true;
                    }
                    if(ocean[nextY][nextX] == 0 || ocean[nextY][nextX] == curSize) { // 갈 수 있는 공간 발견
                        shark next = {nextX, nextY, cur.time+1};
                        visited[nextY][nextX] = true;
                        q.push(next);
                        if(ocean[cur.y][cur.x] = 9) {
                            ocean[cur.y][cur.x] = 0;
                        }
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
        cout << startX << " " << startY << " " << curSize << endl;
        if(startX == 1 && startY == 3) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cout << ocean[i][j] << " ";
                }
                cout << endl;
            }
        }
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