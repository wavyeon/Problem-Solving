#include <iostream>
#include <stack>
#define MAX 500001
#define endl '\n'

using namespace std;

int n, cnt, mid, rig;
int people[MAX];
stack<int> decr;

void init() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> people[i];
    }  
}

void solve() {
    

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