#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000001;
priority_queue< pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > pq;
int n, cor;
long long int value;
int output[MAX];

void init() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &value);
        pq.push(make_pair(value, cor));
        cor++;
    }
    
}

void solve() {
    long long int prev = -10000000001;
    int count = -1;
    while(!pq.empty()) {
        if(pq.top().first > prev) {
            count++;
        }
        output[pq.top().second] = count;
        prev = pq.top().first;
        pq.pop();
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }
}

int main() {
    init();
    solve();
}