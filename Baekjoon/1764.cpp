#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int notHeard, notSeen, cnt;
string name;
map<string, bool> list;
vector<string> dbj;

void solve() {
    // scanf("%d %d", &notHeard, &notSeen);
    cin >> notHeard >> notSeen;
    for(int i = 0; i < notHeard; i++) {
        cin >> name;
        list.insert(make_pair(name, true));
    }
    for(int i = 0; i < notSeen; i++) {
        cin >> name;
        if(list[name] == true) {
            dbj.push_back(name);
            cnt++;
        }
    }
    sort(dbj.begin(), dbj.end());
    // cout << dbj.size() << '\n';
    cout << cnt << '\n';
    for(int i = 0; i < dbj.size(); i++) {
        cout << dbj[i] << '\n';
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
}

