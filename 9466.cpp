// 그래프에서 사이클 판별
// 무방향 그래프 =>  DFS로 방문한 점 다시 방문했는지 여부 판단 / union-find
// 유방향 그래프 => 한 점에서의 DFS가 종료되기 전에 같은 점에서 DFS가 실행되었는지 여부 판단 (역방향 간선의 존재 여부 판단)
// DFS는 재귀로!!
// visited 배열과 finished 배열 사용 

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

void solve() {
	int n;
	while(test--) {
		cin >> n;
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
	}
}

int main() {
	init();
	solve();
}




// #include <iostream>	
// #include <queue>
// #include <cstring>
// #define MAX 100001
// using namespace std;

// int t, n;
// int graph[MAX];
// bool visited[MAX];
// bool done[MAX];
// int cnt;
// void hasCycle( int node) {

// 	visited[node] = true;
// 	int next = graph[node];

	
// 	if (!visited[next]) {
// 		hasCycle( next);
// 	}
// 	else if (!done[next]) {//방문은 했지만 아직 사이클이 아니라면 next까지 포함해서 사이클 완성
// 		//자기 자신을 포함한 팀의 멤버를 카운트
// 		for (int i = next; i != node; i = graph[i]) {
// 			cnt++;
// 		}
// 		cnt++;
// 	}
// 	done[node] = true;
// }


// int main() {

// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);
// 	cin >> t;
// 	while (t--) {
// 		cin >> n;
// 		for (int i = 1; i <= n; i++) {
// 			cin >> graph[i];
// 		}
// 		for (int i = 1; i <= n; i++) {
// 			if (!visited[i]) {
// 				hasCycle(i);
// 			}
// 		}
// 		cout << n-cnt << '\n';
// 		cnt = 0;
// 		memset(visited, false, sizeof(visited));
// 		memset(done, false, sizeof(done));
// 	}


// 	return 0;
// }