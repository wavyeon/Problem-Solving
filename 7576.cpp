#include <iostream>
#include <queue>
#define MAX_SCOPE 1001
#define ALL_DIR 4
// #define ripped 1
// #define unripped 0
// #define empty 

using namespace std;

enum status {
    empty = -1, unripped = 0, ripped = 1
};

// enum Xdir {
//     Xup = 0, Xright = 1, Xdown = 0, Xleft = -1
// };

// enum Ydir {
//     Yup = -1, Yright = 0, Ydown = 1, Yleft = 0
// };

int XDir[ALL_DIR] = {0,1,0,-1};
int YDIr[ALL_DIR] = {-1,0,1,0};
int day = 1;

typedef struct {
    int x;
    int y;
} coordinate;

int box[MAX_SCOPE][MAX_SCOPE]= {-1, };
queue<coordinate> rippedTomato;

void init(int M, int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &box[i][j]);
        }
    }
}

void bfs(int M, int N) {
    int nextX, nextY;
    coordinate front;
    while(!rippedTomato.empty()) {
        front = rippedTomato.front();
        rippedTomato.pop();
        for(int i = 0; i < ALL_DIR; i++) {
            nextX = front.x + XDir[i];
            nextY = front.y + YDIr[i];
            if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N && box[nextY][nextX] == 0) {
                box[nextY][nextX] = box[front.y][front.x] + 1;
                // cout << "[" << nextY << ", " << nextX << "] = " << box[nextY][nextX] << endl;
                coordinate next;
                next.x = nextX;
                next.y = nextY;
                rippedTomato.push(next);
            }
        }
    }
}

void ripping(int M, int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(box[i][j] == ripped) {
                coordinate cur;
                cur.x = j;
                cur.y = i; 
                rippedTomato.push(cur);
            }
        }
    }
    bfs(M,N);
}

void boxCheck(int M, int N) {
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++) {
    //         cout << box[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int max = 0;
    int avaliable = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(box[i][j] > max) {
                max = box[i][j];
            }
            if(box[i][j] == unripped) {
                avaliable = 0;
                break;
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
    int M, N;
    cin >> M >> N;
    init(M, N);
    ripping(M, N);
    boxCheck(M, N);
}

// 전체 돌면서 익은 애들 push
// while(큐가 차있는 동안)
// pop하고 주위에 있는 안익은 애들 push