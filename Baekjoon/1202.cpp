// Greedy하게! 가방에 최대한 비싼 보석을 담는 방법
// 1. 비싸면서 무게가 적은 보석부터 확인?
// 2. 용량이 작은 가방부터 확인?
// 둘다 가능할듯함, 시간 복잡도 줄이는게 핵심 -> 2번 방법 채택

// 1번 방법 사용 -> 시간 초과
// #include <iostream>
// #include <queue>
// #include <algorithm>
// #define endl '\n'
// #define MAX 300001

// using namespace std;

// struct info {
//     int value;
//     int weight;
// };

// struct comp { // value 높은 거 우선, value 같다면 weight 작은 거 우선
//     bool operator()(info x, info y) {
//         if (y.value > x.value) {
//             return true;
//         }
//         else if (x.value == y.value) {
//             return x.weight >= y.weight; 
//         }
//         else {
//             return false;
//         }
//     }
// };

// int jewelry, bag, filledBag, maxValue;
// priority_queue< info, vector<info>, comp > pq; // 비교 기준이 여러개라 comp 구조체 이용
// // https://zoosso.tistory.com/993
// int bags[MAX];
// int isFilled[MAX];

// void init() {
//     cin.tie(0);
//     cout.tie(0);
//     ios::sync_with_stdio(false);
//     cin >> jewelry >> bag;
//     int weight, value;
//     for(int i = 0; i < jewelry; i++) {
//         cin >> weight >> value;
//         pq.push({value, weight});
//     }
//     for(int i = 0; i < bag; i++) {
//         cin >> bags[i];
//     }
//     sort(bags, bags+bag);
// }

// void putInBag(int curWeight, int curValue) {
//     for(int i = 0; i < bag; i++) {
//         if(bags[i] >= curWeight && isFilled[i] == 0) {
//             filledBag++;
//             isFilled[i]++;
//             maxValue += curValue;
//             return;
//         }
//     }
// }

// void solve() {
//     int curWeight, curValue;
//     while(!pq.empty() && filledBag != bag) { // 모든 보석을 따져보았거나, 더이상 넣을 가방이 없으면 종료
//         curWeight = pq.top().weight;
//         curValue = pq.top().value;
//         putInBag(curWeight, curValue);
//         pq.pop();
//     }
//     cout << maxValue << endl;
// }

// int main() {
//     init();
//     solve();
// }

// 2번 방법 -> 통과
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 300001
#define endl '\n'
#define pii pair<int,int>

using namespace std;

// struct info {   // 구조체 배열 sort가 안먹힘...
//     int weight;
//     int value;
// };

int bag, jewelry;
long long valueSum; // 항상 최대값 고려하자!!
// struct info jewelryList[MAX]; // 구조체 배열 선언할 때는 struct 붙여줘야함!
pii jewelryList[MAX];
int bagList[MAX];
priority_queue<int> pq; // pq를 굳이 pair형으로 선언하지 않아도 된다! 가방에 넣을 수 있는 보석들 중 가장 비싼 보석만 찾으면 됨


void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> jewelry >> bag;
    int weight, value;
    for(int i = 0; i < jewelry; i++) {
        cin >> jewelryList[i].first >> jewelryList[i].second;
    }
    for(int i = 0; i < bag; i++) {
        cin >> bagList[i];
    }
    sort(jewelryList, jewelryList+jewelry); // first(weight) 기준으로 정렬
    sort(bagList, bagList+bag); // weight 기준으로 정렬
}

void solve() {
    int jewelryIdx = 0;
    for(int bagIdx = 0; bagIdx < bag; bagIdx++) { // 용량이 작은 가방부터 돌면서 담을 수 있는 모든 보석(의 가치)을 pq에 push  
        while(bagList[bagIdx] >= jewelryList[jewelryIdx].first && jewelryIdx < jewelry) {
            pq.push(jewelryList[jewelryIdx++].second);
            // 다음 보석 탐색을 위해 ++
            // jewelryIdx는 for문에 관계없이 유지되므로 다음 가방에서 같은 보석을 중복해서 탐색할 일이 없음!
        }
        if(!pq.empty()) {
            valueSum += pq.top(); // 해당 가방에 담을 수 있는 가장 비싼 보석을 찾고
            pq.pop();             // 그 보석만 pop해줌. 나머지 보석들은 다음 가방 탐색에서 재활용하는 식으로 시간 절약!
        }
    }
    cout << valueSum << endl;
}

int main() {
    init(); 
    solve();
}
