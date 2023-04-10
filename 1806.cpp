#include <iostream>
#define endl '\n'
#define MAX 100001

using namespace std;

int n, s, cnt;
int arr[MAX];

void solve() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int* start;
    int* end;
    int cur = arr[0];
    int shortest = MAX;
    for(start = &arr[0], end = &arr[0]; start != &arr[n];) {
        if(cur > s) { // 이미 목표치 넘김, start를 한 칸 뒤로
            if(end - start < shortest) {
                shortest = end - start + 1;
            }
            cnt++;
            cur -= *start;
            start++;   
        }
        else if(cur == s) { // 딱 목표치임, cnt 늘려주고 start를 한 칸 뒤로
            if(end - start < shortest) {
                shortest = end - start + 1;
            }
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
    if(cnt == 0) { // s 넘기는 경우 없음
        cout << 0 << endl;
    }
    else {
        cout << shortest << endl;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
}