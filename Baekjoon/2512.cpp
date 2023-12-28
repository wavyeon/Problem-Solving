#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define MAX 1000000001

using namespace std;

int region, budget;
vector<int> request;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> region;
    for(int i = 0; i < region; i++) {
        int tmp;
        cin >> tmp;
        request.push_back(tmp);
    }
    // sort(request, request + region);
    // 배열 sort할 때 배열 크기에 변수가 들어가면 에러?
    sort(request.begin(), request.end());
    cin >> budget;
}

void solve() {
    int start = 0;
    int end = request[request.size()-1];
    int sum, limit;
    while(start <= end) {
        limit = (start + end) / 2; 
        sum = 0;
        for(int i = 0; i < request.size(); i++) {
            sum += min(request[i], limit);
        }
        if(sum <= budget) { // 예산이 남음 -> 상한액을 올려야함, 실행 가능함(예산액을 최대한 썼는 지 체크)
            start = limit + 1;
            // answer = limit 이 왜 필요할까???
        }
        else if(sum > budget) { // 예산이 부족함 -> 상한액을 내려야함, 실행 불가능함
            end = limit - 1;
        }
    }
    cout << limit << endl;
}   

int main() {
    init();
    solve();
}