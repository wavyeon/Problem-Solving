#include <iostream>
#include <math.h>
#define MAX_PEOPLE 21
#define START 1
#define LINK 0
#define Visited 1
#define notVisited 0

using namespace std;

int people;
int statusGap = 2147483647;
int status[MAX_PEOPLE][MAX_PEOPLE];
int teamInfo[MAX_PEOPLE];
int isVisited[MAX_PEOPLE];

void init() {
    scanf("%d", &people);
    for(int i = 0; i < people; i++) {
        for(int j = 0; j < people; j++) {
            scanf("%d", &status[i][j]);
            // cin >> status[i][j];
        }
    }
}

void solve(int index, int entry) {
    if(index >= people || entry >= people) {
        return;
    }
    for(int i = index; i < people; i++) {
        teamInfo[i] = START;
        int startSum = 0;
        int linkSum = 0;
        for(int i = 0; i < people; i++) {
            for(int j = 0; j < people; j++) {
                if(teamInfo[i] == START && teamInfo[j] == START) {
                    startSum += status[i][j];
                }
                if(teamInfo[i] == LINK && teamInfo[j] == LINK) {
                    linkSum += status[i][j];
                }
            }
        }
        if(statusGap > abs(startSum - linkSum)) {
            statusGap = abs(startSum - linkSum);
        }
        solve(i+1, entry+1);
        teamInfo[i] = LINK;
    }
}

int main() {
    init();
    solve(0, 0);
    cout << statusGap << endl;
}