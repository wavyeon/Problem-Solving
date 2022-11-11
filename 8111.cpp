#include <iostream>
#include <queue>
#include <string.h> // memset 필요
#define MAX 20001
#define endl '\n'
#define Visited 1
#define notVisited 0

using namespace std;

typedef struct {
    int parent;
    char binary;    
} choice;

int test, num;
bool isVisited[MAX] = {notVisited, };
choice record[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> test;
}

bool bfs() {
    memset(isVisited, notVisited, sizeof(isVisited)); // 초기화 함수 따로 만들지 말고 memset 사용
    queue<int> q; // 큐도 매번 초기화 할 필요없이 풀 때마다 선언
    q.push(1);
    isVisited[1] = Visited;
    record[1].parent = -1; // 맨 처음이라는 의미
    record[1].binary = '1'; // 맨 처음 숫자는 1일 수 밖에 없음
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int option[2]; 
        option[0] = (cur*10 + 0) % num;
        option[1] = (cur*10 + 1) % num;
        for(int i = 0; i < 2; i++) {
            if(isVisited[option[i]] == Visited) {
                // 방문하려는 나머지 값을 이미 방문했다는 것은 같은 나머지 값이 반복되는 경우, 즉 방문할 의미가 없음 
                // 어차피 무한히 반복돼서 정답이 존재하지 않거나 다른 정답을 찾을 수도 있음
                // 순환소수 같은 느낌...? 
                continue;
            }
            record[option[i]].parent = cur;
            record[option[i]].binary = i + '0'; // 숫자를 문자로 바꾸는 방법
            if(option[i] == 0) { 
                //record에 기록 후에 0인지 판단해야 backtracking이 가능함!!
                //printAnswer()에서 역추적을 record[0]부터 할 것이기 때문
                return true;
            }
            isVisited[option[i]] = Visited;
            q.push(option[i]);
        }
    }
    return false;
}


void printAnswer(int cur) { // 재귀함수 구현 중요!!
    if(cur == -1) {
        return;
    }
    printAnswer(record[cur].parent);
    cout << record[cur].binary;
}

void solve() {
    while(test--) {
        cin >> num;
        if(num == 1) {
            cout << 1 << endl;
            continue;
        }
        if(!bfs()) {
            cout << "BRAK" << endl;
        }
        else {
            printAnswer(0);
            cout << endl;
        }
    }
}

int main() {
    init();
    solve();
}
