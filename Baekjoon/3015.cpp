#include <iostream>
#include <stack>
#define MAX 500001
#define endl '\n'

using namespace std;

int n;
long long cnt;
int people[MAX];
stack<pair<int,int>> st; // first는 키, second는 키가 같은 사람의 수

void init() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> people[i];
    }
}

void solve() {
    for(int i = 0; i < n; i++) {
        int now = people[i];
        int sameHeight = 1;
        while(!st.empty() && st.top().first < now) { // now보다 작은 st.top은 더이상 필요 없음
            cnt += st.top().second;
            st.pop();
        }
        if(!st.empty()) {
            if(st.top().first == now) { // now와 st.top이 키가 같으면
                cnt += st.top().second;
                sameHeight = st.top().second + 1;
                if(st.size() > 1) { // st.top의 앞에 now보다 큰 사람이 존재함, 그러나 그 중에서 가장 작은 사람과만 짝지을 수 있음
                    cnt++;
                }
                st.pop();
            }
            else { // st.top()이 now보다 크면 
                cnt++;
            }
        }
        st.push(make_pair(now, sameHeight));
    }

    cout << cnt << endl;

    // for(int i = 0; i < n; i++) {
    //     if(decr.empty()) {
    //         decr.push(people[i]);
    //     }
    //     else {
    //         if(decr.top() > people[i]) {
    //             cnt++;
    //             decr.push(people[i]);      
    //         }
    //         else if (decr.top() == people[i]) {
    //             stack<int> tmp = decr;
    //             rig = people[i];
    //             mid = tmp.top();
    //             cnt++;
    //             tmp.pop();
    //             while(!tmp.empty() && rig >= mid && tmp.top() >= mid) {
    //                 mid = tmp.top();
    //                 cnt++;
    //                 tmp.pop();
    //             }
    //             decr.push(people[i]);
    //         }
    //         else if (decr.top() < people[i]) {
    //             stack<int> tmp = decr;
    //             rig = people[i];
    //             mid = tmp.top();
    //             cnt++;
    //             tmp.pop();
    //             while(!tmp.empty() && rig >= mid && tmp.top() >= mid) {
    //                 mid = tmp.top();
    //                 cnt++;
    //                 tmp.pop();
    //             }
    //         }
    //     }
    // }
    // cout << cnt << endl;


    // for(int i = 0; i < n-1; i++) {
    //     if(!st.empty() && st.top() < people[i]) {
    //         while(!st.empty() && st.top() < people[i]) {
    //             st.pop();
    //         }
    //     }
    //     tallerLefter[i] = st.size();
    //     st.push(people[i]);
    // }
    // for(int i = 0; i < n-1; i++) {
    //     cout << tallerLefter[i] << " ";
    // }
    // cout << endl;
    // for(int i = 1; i < n; i++) {
    //     if(people[i] >= people[i-1]) {
    //         output += (tallerLefter[i-1] + 1);
    //         // cout << tallerLefter[i-1] + 1 << " ";
    //     }
    //     else {
    //         output += 1;
    //         // cout << 1 << " ";
    //     }
    // }
    // // cout << endl;
    // cout << output << endl;
}

int main() {
    init();
    solve();
}