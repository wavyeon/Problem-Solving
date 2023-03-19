#include <iostream>
#include <queue>
#include <algorithm>
#define endl '\n'
#define MAX 300001

using namespace std;

struct info {
    int value;
    int weight;
};

struct comp { // value 높은 거 우선, value 같다면 weight 작은 거 우선
    bool operator()(info x, info y) {
        if (y.value > x.value) {
            return true;
        }
        else if (x.value == y.value) {
            return x.weight >= y.weight; 
        }
        else {
            return false;
        }
    }
};

int jewelry, bag, filledBag, maxValue;
priority_queue< info, vector<info>, comp > pq; // 비교 기준이 여러개라 comp 구조체 이용
// https://zoosso.tistory.com/993
int bags[MAX];
int isFilled[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> jewelry >> bag;
    int weight, value;
    for(int i = 0; i < jewelry; i++) {
        cin >> weight >> value;
        pq.push({value, weight});
    }
    for(int i = 0; i < bag; i++) {
        cin >> bags[i];
    }
    sort(bags, bags+bag);
    // for(int i = 0; i < bag; i++) {
    //     cout << bags[i] << endl;
    // }
}

void putInBag(int curWeight, int curValue) {
    for(int i = 0; i < bag; i++) {
        if(bags[i] >= curWeight && isFilled[i] == 0) {
            filledBag++;
            isFilled[i]++;
            maxValue += curValue;
            return;
        }
    }
}

void solve() {
    int curWeight, curValue;
    while(!pq.empty() && filledBag != bag) { // 모든 보석을 따져보았거나, 더이상 넣을 가방이 없으면 종료
        curWeight = pq.top().weight;
        curValue = pq.top().value;
        putInBag(curWeight, curValue);
        pq.pop();
    }
    cout << maxValue << endl;
}

int main() {
    init();
    solve();
}