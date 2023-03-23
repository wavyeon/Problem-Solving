// https://yabmoons.tistory.com/592
#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define MAX 2501

using namespace std;

int length;
char str[MAX];
int dp[MAX]; // dp[i] = i번째 문자까지 팰린드롬 문자열로 분할 할 수 있는 최소 횟수
bool palindrome[MAX][MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> str;
}

void isPalindrome() {
    for(int i = 0; i < length; i++) { // 길이가 1인 부분문자열
        palindrome[i][i] = true;
    }
    for(int i = 0; i < length-1; i++) { // 길이가 2인 부분문자열
        if(str[i] == str[i+1]) {
            palindrome[i][i+1] = true;
        }
    }
    for(int part = 3; part <= length; part++) { // 길이가 3 이상인 부분문자열
        for(int start = 0; start < length - part + 1; start++) { // 길이 1씩 증가시켜가며 확인 
            int end = start + length - 1; 
            if(str[start] == str[end] && palindrome[start+1][end-1] == true) {
                // 팰린드롬 조건
                // 1. 첫 문자와 마지막 문자가 같다
                // 2. 중간 문자열 역시 팰린드롬이다
                palindrome[start][end] = true;
            }
        }
    }
}

void countMinDivision() {
    // dp[i] 값을 순차적으로 채워나감 (길이가 1인 문자열부터 길이가 length인 문자열까지)
    for(int end = 0; end <= length; end++) { // end값이 사실상 문자열의 길이를 의미
        dp[end] = 2e9;
        for(int start = 0; start <= end; start++) {
            // palindrome[0][end], palindrome[1][end], ... palindrome[end][end] 를 확인
            // palindrome 값이 true라면 index ~ end 문자열을 하나의 팰린드롬 문자열로 볼수있음
            // palindrome 값이 false라면 index ~ end 문자열이 팰린드롬 문자열이 아니므로 따져볼 필요 없음 
            if(palindrome[start][end] == true) {
                dp[end] = min(dp[end], dp[start-1] + 1);
                // dp[start-1]은 0 ~ start-1 문자열을 팰린드롬 문자열로 분할할 수 있는 최소 횟수 의미 
            }
        }
    }
    cout << dp[length-1] << endl;
}

void solve() {
    length = strlen(str);
    isPalindrome();
    countMinDivision();
}

int main() {
    init();
    solve();
}