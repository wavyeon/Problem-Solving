#include <iostream>
#include <vector>

using namespace std;

typedef struct{
    int index;
    int dist;
} node;

const int MAX = 100001;
int vertex;
vector<node> graph[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> vertex;
    int from, to, dist;
    for(int i = 1; i <= vertex; i++) {
        cin >> from;
        while(true) {
            cin >> to;
            if(to == -1) {
                break;
            }
            cin >> dist;
            graph[from].push_back({to, dist});
        }
    }
}

void solve() {
    
}

int main() {
    init();
    solve()
}