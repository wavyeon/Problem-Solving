#include <iostream>
#include <stack>
#define MAX 101
#define endl '\n'
#define coor pair<int,int>
#define All_DIR 4
#define In 0
#define Out 1
#define Visited 1
#define notVisited 0

using namespace std;

int n, m, cheese;
int container[MAX][MAX];
int inout[MAX][MAX];
stack<coor> st;
int dx[All_DIR] = {0,1,0,-1};
int dy[All_DIR] = {-1,0,1,0};
int isVisited[MAX][MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> container[i][j];
            if(container[i][j] == 1) {
                cheese++;
            }
        }
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << container[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void check_inout() {
    coor start = {0,0};
    st.push(start);
    isVisited[0][0] = Visited;
    inout[0][0] = Out;
    while(!st.empty()) {
        coor cur = st.top();
        st.pop();
        int startX = cur.first;
        int startY = cur.second;
        for(int i = 0; i < All_DIR; i++) {
            int nextX = startX + dx[i];
            int nextY = startY + dy[i];
            if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                if(container[nextY][nextX] == 0 && isVisited[nextY][nextX] == notVisited) {
                    coor next = {nextX, nextY};
                    st.push(next);
                    isVisited[nextY][nextX] = Visited;
                    inout[nextY][nextX] = Out;
                }
            }
        }
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << inout[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void count_exposed() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(container[i][j] == 1 && isVisited[i][j] == notVisited) { // 치즈이면서, 체크하지 않은 경우
                for(int k = 0; k < All_DIR; k++) {
                    int exposedPart = 0;
                    if(inout[i+dy[k]][j+dx[k]] == Out && container[i+dy[k]][j+dx[k]] == 0) { // 상하좌우에 외부 공기가 있으면 카운팅
                        exposedPart++;
                    }
                }
                if(exposedPart >= 2) {
                    
                }
            }
        }
    }
}

void solve() {
    while(true) {
        // isVisited isout 초기화
        check_inout();
        // isVisited 초기화
        count_exposed();
    }
    

}

int main() {
    init();
    solve();
}