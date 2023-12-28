#include <iostream>
#include <string.h>
#include <stack>
#define MAX 1001
#define endl "\n"

using namespace std;

int test;
char sentence[MAX];
stack<char> st;

void reverseSentence() {
    for(int i = 0; i <= strlen(sentence); i++) {
        if(i == strlen(sentence) || sentence[i] == ' ') {
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << " ";
        }
        else {
            st.push(sentence[i]);
        }
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> test;
    cin.ignore();
    while(test--) {
        cin.getline(sentence, MAX);
        reverseSentence();
    }
}