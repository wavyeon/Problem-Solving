#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numOfMeeting;
vector<pair<int, int>> schedule;

void init() {
    scanf("%d", &numOfMeeting);
    for(int i = 0; i < numOfMeeting; i++) {
        int begin, end;
        scanf("%d %d", &begin, &end);
        schedule.push_back(make_pair(end, begin)); // sort는 first를 기준으로 정렬하므로 end를 first에 넣기
    }
    sort(schedule.begin(), schedule.end());
}

void solve() {
    int exFinish = 0;
    int meetingCount = 0;
    for(int i = 0; i < schedule.size(); i++) {
        if(schedule[i].second >= exFinish) {
            meetingCount++;
            exFinish = schedule[i].first;
        }
    }
    printf("%d\n", meetingCount);
}

int main() {
    init();
    solve();
}