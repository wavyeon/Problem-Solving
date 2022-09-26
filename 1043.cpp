#include <iostream>
#include <vector>

using namespace std;

const int MAX = 51;
vector<vector<int>> meetingPeople(MAX);
vector<vector<int>> partyPeopleIdx(MAX);
bool knownCheck[MAX];
int people, party, known, idx;

void init() {
    cin >> people >> party;
    cin >> known;
    for(int i = 0; i < known; i++) {
        cin >> idx;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    init();
    solve();
}
