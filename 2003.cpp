#include <iostream>
#include <vector>
#define endl '\n'
#define MAX 10001

using namespace std;

int n, m, cnt;
int arr[MAX];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int* start;
    int* end;
    int cur = arr[0];
    for(start = &arr[0], end = &arr[0]; start != &arr[n];) {
        // cout << *start << " " << *end << endl;
        if(cur > m) { // 이미 목표치 넘김, start를 한 칸 뒤로
            cur -= *start;
            start++;
        }
        else if(cur == m) { // 딱 목표치임, cnt 늘려주고 start를 한 칸 뒤로
            cnt++;
            cur -= *start;
            start++;
        }
        else { // 아직 목표치 못 옴, end를 한 칸 뒤로
            end++;
            if(end == &arr[n]) { // end 끝까지 왔는데 아직 목표치 못 옴 => 더 이상의 탐색 무의미 (start 뒤로 보내봤자 합은 줄어듬)
                break;
            }
            cur += *end;
        }
    }
    cout << cnt << endl;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
}