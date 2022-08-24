#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int screen;
    int clipboard;
    int second; 
} status;

const int MAX = 10000;
queue<status> que;
bool visited[MAX][MAX] = {false, };

void copy(status cur) {
    status next;
    next.screen = cur.screen;
    next.clipboard = cur.screen;
    if(!visited[next.screen][next.clipboard]) {
        next.second = cur.second + 1;
        que.push(next);
        visited[next.screen][next.clipboard] = true;
    }
}

void paste(status cur) {
    if(cur.clipboard > 0) {
        status next;
        next.screen = cur.screen + cur.clipboard;
        next.clipboard = cur.clipboard;
        if(!visited[next.screen][next.clipboard]) {
            next.second = cur.second + 1;
            que.push(next);
            visited[next.screen][next.clipboard] = true;
        }
    }     
}

void erase(status cur) {
    if(cur.screen > 0) {
        status next;
        next.screen = cur.screen - 1;
        next.clipboard = cur.clipboard;
        if(!visited[next.screen][next.clipboard]) {
            next.second = cur.second + 1;
            que.push(next);
            visited[next.screen][next.clipboard] = true;
        }
    }
}

void solve(int target) {
    status start;
    start.screen = 1;
    start.clipboard = 0;
    start.second = 0;
    que.push(start);
    visited[start.screen][start.clipboard] = true;
    while(!que.empty()) {
        status cur = que.front();
        que.pop();
        if(cur.screen == target) {
            printf("%d\n", cur.second);
            return;
        }
        copy(cur);
        paste(cur);
        erase(cur);
    }
}

int main() {
    int target;
    scanf("%d", &target);
    solve(target);
}