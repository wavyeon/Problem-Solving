#include <iostream>
#include <stack>

using namespace std;

stack<int> st;
int call, num, numSum;

void solve() {
    scanf("%d", &call);
    for(int i = 0; i < call; i++) {
        scanf("%d", &num);
        if(num != 0) {
            st.push(num);
        }
        else {
            st.pop();
        }
    }
    while(!st.empty()) {
        numSum += st.top();
        st.pop();
    }
    printf("%d\n", numSum);
}

int main() {
    solve();    
}