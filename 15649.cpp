#include <iostream>
#define MAX_VALUE 9
#define isVisited 1
#define notVisited 0

using namespace std;

int n, m;
int input[MAX_VALUE];
int output[MAX_VALUE];
int visited[MAX_VALUE];

void init() {
    scanf("%d %d", &n, &m);
}

void solve(int count) {
    if(count == m) {
        for(int i = 0; i < m; i++) {
            printf("%d ", output[i]);
        }
        printf("\n");
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(visited[i] == notVisited) {
                output[count] = i;
                visited[i] = isVisited;
                solve(count+1);
                visited[i] = notVisited;
            }
        }
    }
}

int main() {
    init();
    solve(0);
}