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

void solve(int count, int start) {
    if(count == m) {
        for(int i = 0; i < m; i++) {
            printf("%d ", output[i]);
        }
        printf("\n");
    }
    else {
        for(int i = start; i <= n; i++) {
            output[count] = i;
            solve(count+1, i);
        }
    }
}

int main() {
    init();
    solve(0, 1);
}