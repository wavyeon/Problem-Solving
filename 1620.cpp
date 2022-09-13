#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

const int MAX = 100001;
int idx, question;
unordered_map<string,int> strToNum;
string numToStr[MAX];

void input() {
    cin >> idx >> question;
    for(int i = 1; i <= idx; i++) {
        string name;
        cin >> name;
        numToStr[i] = name;
        strToNum.insert(make_pair(name, i));
    }
}

void solve() {
    for(int i = 0; i < question; i++) {
        string tmp;
        cin >> tmp;
        if(strToNum.find(tmp) != strToNum.end()) {
            cout << strToNum.find(tmp)->second << "\n";
        }
        else {
            int num = stoi(tmp);
            cout << numToStr[num] << "\n";
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    input();
    solve();
}
