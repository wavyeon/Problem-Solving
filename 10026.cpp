#include <iostream>
#include <queue>
#include <string.h>
#define endl '\n'
#define MAX 101

using namespace std;

typedef struct {
    int x;
    int y;
} coo;

int n, normalCnt, weakCnt;
char normal[MAX][MAX];
char colorWeakness[MAX][MAX];
bool isVisited[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<coo> q;

void init() {
    scanf("%d", &n);
    char pixel;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // scanf 사용 후 scanf로 붙여서 입력 받을 때는 반드시 맨 앞 띄워쓰기!!
            scanf(" %1c", &pixel);
            normal[i][j] = pixel;
            if(pixel == 'G') {
                pixel = 'R';
            }
            colorWeakness[i][j] = pixel;
        }
    }
}   

bool check(coo next, char color, char picture[][MAX]) {
    // 2차원 배열 매개변수로 쓸 때는 2차원의 크기가 "상수로" 정의되어야 함!!
    if(next.x >= 0 && next.y >= 0 && next.x < n && next.y < n) {
        if(!isVisited[next.y][next.x] && picture[next.y][next.x] == color) {
            return true;
        }
    }
    return false;
}

void bfs(char picture[][MAX]) {
    while(!q.empty()) {
        coo cur = q.front();
        q.pop();
        char color = picture[cur.y][cur.x];
        for(int i = 0; i < 4; i++) {
            int nextX = cur.x + dx[i];
            int nextY = cur.y + dy[i];
            if(check({nextX, nextY}, color, picture)) {
                q.push({nextX, nextY});
                isVisited[nextY][nextX] = true;
            }
        }
    }   
}

void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!isVisited[i][j]) {
                normalCnt++;
                q.push({j,i});
                isVisited[i][j] = true;
                bfs(normal);
            }
        }
    }

    // queue 초기화는 queue 생성자 이용!
    q = queue<coo>();
    // 2차원 배열도 0, -1로 초기화할 때는 memset 이용!
    memset(isVisited, false, sizeof(isVisited));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!isVisited[i][j]) {
                weakCnt++;
                q.push({j,i});
                isVisited[i][j] = true;
                bfs(colorWeakness);                
            }
        }
    }
    cout << normalCnt << " " << weakCnt << endl;
}

int main() {
    init();
    solve();
}