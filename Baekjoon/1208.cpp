// 부분 수열 문제 Backtracking 대신 재귀 두 번씩 쓰는 방식 사용
// 이분 탐색으로 시간 복잡도 줄이기
// 이분 탐색의 핵심은 n개의 데이터를 (n/2) * 2 로 나누어 탐색하는 것에 있음
// 적절한 mid 값을 찾으려는 식의 접근 ㄴㄴ
#include <iostream>
#include <map>
#define endl '\n'

using namespace std;
 
int n, s;
int arr[41];
map<int, int> subsum;
long long cnt;
 
void rightPart(int mid, int sum){
    if(mid == n){
        subsum[sum]++;
        return;
    }
    rightPart(mid + 1, sum + arr[mid]); // 현재 탐색 값 선택
    rightPart(mid + 1, sum);            // 현재 탐색 값 건너뛰기
}
 
void leftPart(int start, int sum){
    if(start == n/2){
        cnt += subsum[s-sum];
        return;
    }
    leftPart(start + 1, sum + arr[start]);    // 현재 탐색 값 선택
    leftPart(start + 1, sum);              // 현재 탐색 값 건너뛰기
}
 
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    rightPart(n/2, 0);
    leftPart(0, 0);
    
    if(s == 0) {  // left, right에서 모두 sum이 0이면 크기가 양수인 부분수열이 아니므로 공집합인 경우 빼주기
        cout << cnt-1 << endl;
    }
    else {
        cout << cnt << endl;
    }
}