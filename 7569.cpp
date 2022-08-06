#include <iostream>
#include <queue>
#define MAX_SCOPE 101
#define ALL_DIR 4
#define UP_DOWN 2

using namespace std;

enum status {
    empty = -1, unripped = 0, ripped = 1
};

int XDir[ALL_DIR] = {0,1,0,-1};
int YDIr[ALL_DIR] = {-1,0,1,0};
int ZDir[UP_DOWN] = {-1,1};
int day = 1;

typedef struct {
    int x;
    int y;
    int z;
} coordinate;

int box[MAX_SCOPE][MAX_SCOPE][MAX_SCOPE]= {-1, };
queue<coordinate> rippedTomato;

void init(int H, int M, int N) {
    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                scanf("%d", &box[k][i][j]);
            }
        }
    }
}

void bfs(int H, int M, int N) {
    int nextX, nextY, nextZ;
    coordinate front;
    while(!rippedTomato.empty()) {
        front = rippedTomato.front();
        rippedTomato.pop();
        for(int i = 0; i < ALL_DIR; i++) {
            nextX = front.x + XDir[i];
            nextY = front.y + YDIr[i];
            nextZ = front.z;
            if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N && box[nextZ][nextY][nextX] == 0) {
                box[nextZ][nextY][nextX] = box[front.z][front.y][front.x] + 1;
                coordinate next;
                next.x = nextX;
                next.y = nextY;
                next.z = nextZ;
                rippedTomato.push(next);
            }
        }
        for(int j = 0; j < UP_DOWN; j++) {
            nextX = front.x;
            nextY = front.y;
            nextZ = front.z + ZDir[j];
            if(nextZ >= 0 && nextZ < H && box[nextZ][nextY][nextX] == 0) {
                box[nextZ][nextY][nextX] = box[front.z][front.y][front.x] + 1;
                coordinate next;
                next.x = nextX;
                next.y = nextY;
                next.z = nextZ;
                rippedTomato.push(next);
            }
        }
    }
}

void ripping(int H, int M, int N) {
    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(box[k][i][j] == ripped) {
                    coordinate cur;
                    cur.x = j;
                    cur.y = i;
                    cur.z = k;
                    rippedTomato.push(cur);
                }
            }
        }
    }
    bfs(H, M,N);
}

void boxCheck(int H, int M, int N) {
    int max = 0;
    int avaliable = 1;
    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(box[k][i][j] > max) {
                    max = box[k][i][j];
                }
                if(box[k][i][j] == unripped) {
                    avaliable = 0;
                    break;
                }
            }
        }
    }
    if(avaliable == 0) {
        cout << -1 << endl;
    }
    else{
        cout << max-1 << endl;
    }
}

int main() {
    int M, N, H;
    cin >> M >> N >> H;
    init(H, M, N);
    ripping(H, M, N);
    boxCheck(H, M, N);
}
