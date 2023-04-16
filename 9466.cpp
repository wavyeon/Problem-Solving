// 그래프에서 사이클 판별
// 무방향 그래프 =>  DFS로 방문한 점 다시 방문했는지 여부 판단 / union-find
// 유방향 그래프 => 한 점에서의 DFS가 종료되기 전에 같은 점에서 DFS가 실행되었는지 여부 판단 (역방향 간선의 존재 여부 판단)
// DFS는 재귀로!!
// visited 배열과 finished 배열 사용 
// https://nicotina04.tistory.com/148

#include <iostream>
#include <string.h>
#define endl '\n'
#define MAX 100001

using namespace std;

int test, grouped;
int order = 1;
int nextNode[MAX];
int visitOrder[MAX]; // 0: 방문 안함, 자연수: 방문한 순서
bool finished[MAX];

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> test;
}

void dfs(int cur) {
	// cout << "방문: " << cur << endl; 
	visitOrder[cur] = order++;
	int next = nextNode[cur];
	if(!visitOrder[next]) { // 방문안했으면 dfs
		dfs(next);
	}
	else { // 방문했지만
		if(!finished[next]) {// 다음 방문할 노드가 이미 dfs 호출된 상태인 경우 (visit 했지만 finish되지 않은 경우)
			grouped += visitOrder[cur] - visitOrder[next] + 1; // dfs 호출한 동안 거쳐간 노드의 수 (사이클 형성한 노드 수)
			// 자기 자신 가리키는 경우도 처리 가능
		}
	}
	finished[cur] = true; // dfs 종료되었으므로 finished 처리
}

void solve() {
	int n;
	while(test--) {
		cin >> n;
		order = 1;
		grouped = 0;
		memset(visitOrder, 0, sizeof(visitOrder));
		memset(finished, 0, sizeof(finished));
		for(int i = 1; i <= n; i++) {
			cin >> nextNode[i];
		}
		for(int i = 1; i <= n; i++) {
			if(!visitOrder[i]) { // 아직 방문하지 않은 노드라면 dfs 탐색
				dfs(i);
			}
		}
		cout << n - grouped << endl; // 전체 학생 수에서 그룹지어진 학생 수 빼기
	}
}

int main() {
	init();
	solve();
}