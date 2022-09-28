#include <iostream>
#include <vector>

using namespace std;

int people, party, knowing, knowingPerson, partyPerson, participant, count, pre, cur;
const int MAX = 51;
vector<int> knowingPeople;
int parent[MAX];
vector<vector<int>> partyPeople(MAX);

int Find(int x) {
    if(parent[x] == x) {
        return x;
    }
    else {
        return Find(parent[x]);
    }
}

void Union(int x, int y) {
    x = Find(x); //x가 소속된 트리의 루트 찾기
    y = Find(y);
    parent[x] = y; //x가 소속된 트리를 y가 소속된 트리 밑에 붙이기 (합친다)
}

void init() {
    cin >> people >> party;
    cin >> knowingPerson;
    for(int i = 0; i < knowing; i++) {
        cin >> knowingPerson;
        knowingPeople.push_back(knowingPerson);
    }
    for(int i = 1; i < MAX; i++) {
        parent[i] = i;
    }
    for(int i = 0; i < party; i++) {
        cin >> participant;
        for(int j = 0; j < participant; j++) {
            cin >> partyPerson;
            if(j == 0) {
                pre = partyPerson;
            }
            else {
                cur = partyPerson;
                Union(Find(pre), Find(cur));
                pre = cur;
            }
            partyPeople[i].push_back(partyPerson);
        }
    }
    count = party;
}

void solve() {
    for(int i = 0; i < party; i++) {
        bool liable = true;
        for(int j = 0; j < partyPeople[i].size(); j++) {
            for(int k = 0; k < knowingPeople.size(); k++) {
                if(Find(partyPeople[i][j]) == Find(knowingPeople[k])) {
                    liable = false;
                    break;
                }
            }
        }
        if(liable == false) {
                count--;
            }
    }
    cout << count << "\n";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    init();
    solve();
}