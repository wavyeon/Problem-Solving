#include <iostream>
#define used 1
#define notUsed 0

using namespace std;

const int MAX = 101;
int mapLength, slopeLength, count;
int map[MAX][MAX];
bool isUsedHorizon[MAX][MAX];
bool isUsedVertical[MAX][MAX];

void init() {
    scanf("%d %d", &mapLength, &slopeLength);
    for(int i = 0; i < mapLength; i++) {
        for(int j = 0; j < mapLength; j++) {
            scanf("%d", &map[i][j]);
        }
    }
}

bool isBuildableHorizon(int y, int x, int scope) {
    if(scope > 0) { //작아지는 경우
        if(x + scope > mapLength) {
            return false;
        }
        else if(x + scope <= mapLength) {
            for(int i = x; i < x + scope; i++) {
                if(map[y][i] == map[y][x-1]-1 && isUsedHorizon[y][i] == notUsed) {
                    continue;
                }
                else {
                    return false;
                }
            }
            for(int i = x; i < x + scope; i++) {
                isUsedHorizon[y][i] = used;
            }
            return true;
        }
    }
    else if(scope < 0) { //커지는 경우
        if(x+scope < 0) {
            return false;
        }
        else if(x+scope >= 0) {
            for(int i = x-1; i >= x + scope; i--) {
                if(map[y][i] == map[y][x]-1 && isUsedHorizon[y][i] == notUsed) {
                    continue;
                }
                else {
                    return false;
                }
            }
            for(int i = x-1; i >= x + scope; i--) {
                isUsedHorizon[y][i] = used;
            }
            return true;
        }
    }
    
}

bool isBuildableVertical(int y, int x, int scope) {
    if(scope > 0) { //작아지는 경우
        if(y + scope > mapLength) {
            return false;
        }
        else if(y + scope <= mapLength) {
            for(int i = y; i < y + scope; i++) {
                if(map[i][x] == map[y-1][x]-1 && isUsedVertical[i][x] == notUsed) {
                    continue;
                }
                else {
                    return false;
                }
            }
            for(int i = y; i < y + scope; i++) {
                isUsedVertical[i][x] = used;
            }
            return true;
        }
    }
    else if(scope < 0) { //커지는 경우
        if(y+scope < 0) {
            return false;
        }
        else if(y+scope >= 0) {
            for(int i = y-1; i >= y + scope; i--) {
                if(map[i][x] == map[y][x]-1 && isUsedVertical[i][x] == notUsed) {
                    continue;
                }
                else {
                    return false;
                }
            }
            for(int i = y-1; i >= y + scope; i--) {
                isUsedVertical[i][x] = used;
            }
            return true;
        }
    }
    
}

bool isPassableHorizon(int idx) {
    int prev = map[idx][0];
    for(int i = 1; i < mapLength; i++) {
        if(map[idx][i] == prev) {
            continue;
        }
        else {
            if(abs(map[idx][i] - prev) > 1)
                return false;
            else {
                if(map[idx][i] > prev) {
                    if(!isBuildableHorizon(idx, i, -slopeLength)) {
                        return false;
                    }
                }
                else if (map[idx][i] < prev) {
                    if(!isBuildableHorizon(idx, i, slopeLength)) {
                        return false;
                    }
                }
            }
        }
        prev = map[idx][i];
    }
    return true;
}

bool isPassableVertical(int idx) {
    int prev = map[0][idx];
    for(int i = 1; i < mapLength; i++) {
        if(map[i][idx] == prev) {
            continue;
        }
        else {
            if(abs(map[i][idx] - prev) > 1)
                return false;
            else {
                if(map[i][idx] > prev) {
                    if(!isBuildableVertical(i, idx, -slopeLength)) {
                        return false;
                    }
                }
                else if (map[i][idx] < prev) {
                    if(!isBuildableVertical(i, idx, slopeLength)) {
                        return false;
                    }
                }
            }
        }
        prev = map[i][idx];
    }
    return true;
}

void solve() {
    for(int i = 0; i < mapLength; i++) {
        if(isPassableHorizon(i)) {
            count++;
        }
        if(isPassableVertical(i)) {
            count++;
        }
    }
    printf("%d\n", count);
}
int main() {
    init();
    solve();    
}