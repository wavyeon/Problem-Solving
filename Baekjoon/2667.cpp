#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX_SIZE 26
#define isVisited 1
#define notVisited 0

const int ALL_DIR = 4;

using namespace std;

typedef struct {
    int x;
    int y;
} coordinate;

char map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int Xdir[ALL_DIR] = {0,1,0,-1};
int Ydir[ALL_DIR] = {-1,0,1,0};
vector<int> sizeOfAllApart;
stack<coordinate> st;

void init(int N) {
    string line;
    for(int i = 0; i < N; i++) {
        cin >> line;
        for(int j = 0; j < N; j++) {
            map[i][j] = line[j];        
        }
    }
}

void dfs(coordinate cur, int sizeOfApart) {
    visited[cur.y][cur.x] = isVisited;
    st.push(cur);
    while(!st.empty()) {
        int nextX, nextY;
        coordinate top = st.top();
        st.pop();
        sizeOfApart++;
        for(int i = 0; i < ALL_DIR; i++) {
            nextX = top.x + Xdir[i];
            nextY = top.y + Ydir[i];
            if(map[nextY][nextX] == ('1' - 0) && visited[nextY][nextX] == notVisited) {
                coordinate next;
                next.x = nextX;
                next.y = nextY;
                visited[nextY][nextX] = isVisited;
                st.push(next);
            }
        }
    }
    sizeOfAllApart.push_back(sizeOfApart);
}

void solve(int N) {
    coordinate cur;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == ('1' - 0) && visited[i][j] == notVisited) {
                cur.x = j; cur.y = i;
                int sizeOfApart = 0;
                dfs(cur, sizeOfApart);
                
            }
        }
    }
    sort(sizeOfAllApart.begin(), sizeOfAllApart.end());
    cout << sizeOfAllApart.size() << endl;
    for(int i = 0; i < sizeOfAllApart.size(); i++) {
        cout << sizeOfAllApart[i] << endl;
    }
}

int main() {
    int N;
    cin >> N;
    
    init(N);
    solve(N);

}