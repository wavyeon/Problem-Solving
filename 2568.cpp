// LIS를 구하는 두가지 알고리즘
// DP => O(N^2)
// BINARY SEARCH(lower bound) => O(NlogN)
// 이진탐색은 정확히 같은 값이 있는 곳 찾는 것
// LOWER BOUND는 주어진 값보다 같거나 큰 값이 처음으로 나오는 위치 찾는 것
// UPPER BOUND는 주어진 값보다 큰 값이 처음으로 나오는 위치 찾는 것
// lower, upper bound는 중복된 값이 있을 때 주로 사용
// https://jackpot53.tistory.com/33

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define MAX 100001
#define endl "\n"

using namespace std;
 
struct line {
    int left;
    int right;
};
 
int n;
line lines[MAX];
vector<line> LIS;
int lowerBoundIdx[MAX]; // lowerBound로 요소 삽입하면서 삽입되는 "위치" 저장 (뒤에서부터 내림차순하면 LIS)
map<int,int> telepole; // 각 전깃줄의 전봇대 B에 연결된 위치(key)와 전봇대 B에 연결된 위치(value)를 매핑
set<int> haveToRemove; // 최소로 제거해야하는 전깃줄의 A 위치, 처음에는 모든 전깃줄의 A 위치 삽입 

bool cmp(line A, line B) {
    if (A.left < B.left) { // 왼쪽 전봇대 기준으로 정렬
        return true; // true => 순서바꾸지 않아도 됨
    }
    else {
        return false; // false => 순서 바꿔야 함
    }
}

void init() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> lines[i].left >> lines[i].right;
		telepole[lines[i].right] = lines[i].left;
		haveToRemove.insert(lines[i].left);
    }
	sort(lines + 1, lines + n + 1, cmp); // 왼쪽 전봇대 기준으로 정렬
}

void solve() {
	LIS.push_back({0,-1});
	for(int i = 1; i <= n; i++) {
		int rightVal = lines[i].right;
		if(rightVal > LIS[LIS.size()-1].right) { // LIS 벡터의 마지막 요소보다 큰 경우 => 뒤에 삽입
			LIS.push_back(lines[i]);
			lowerBoundIdx[i] = LIS.size()-1; // LIS 배열에 삽입되는 위치 (== LIS.size()-1)를 저장
		}
		else { // LIS 벡터의 마지막 요소보다 작은 경우 => lower bound로 값을 교체할 위치 찾기 
			int low = 0;
			int high = LIS.size();
			while(low < high) {
				int mid = low + ((high - low) / 2);
				if(rightVal >= LIS[mid].right) {
					low = mid + 1;
				}
				else if (rightVal < LIS[mid].right) {
					high = mid;
				}
			}
			LIS[low] = lines[i];
			lowerBoundIdx[i] = low; // LIS 배열에 삽입되는 위치 (== low)를 저장 
		}
	}

	cout << "lowerbound" << endl;
	for(int i = 1; i <= n; i++) {
		cout << lowerBoundIdx[i] << " ";
	}
	cout << endl;

	cout << n - (LIS.size()-1) << endl;
	// for(int i = 0; i < LIS.size(); i++) {
	// 	cout << LIS[i].left << " " << LIS[i].right << endl;
	// }

	int lisIdx = LIS.size()-1; // LIS.size()와 같음	
	// lines[n].right == 남아있어야하는 전깃줄의 B 위치
	// telepole[lines[n].right] == 남아있어야하는 전깃줄의 A 위치
	// 남아있어야하는 전깃줄이므로 제거해야하는 전깃줄 리스트에서 제거해줘야 함
	for(int i = n; i >= 1; i--) {
		if(lowerBoundIdx[i] == lisIdx) {
			haveToRemove.erase(telepole[lines[i].right]);
			// cout << "지울놈: " << lines[i].right << endl;
			lisIdx--;
		}
	}
	for (set<int>::iterator it = haveToRemove.begin(); it != haveToRemove.end(); it++) {
		cout << *it << endl;
	}
}

int main(void) {
    init();
    solve();
}
