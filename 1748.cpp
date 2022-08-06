#include <iostream>

using namespace std;

void solve() {
int num;
    int digit = 0;
    int changePoint = 10;
    int addedDIgit = 1;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++) {
        if(i == changePoint) {
            changePoint *= 10;
            addedDIgit++;
        }
        digit += addedDIgit;
    }
    printf("%d", digit);
}

int main() {
    solve();   
}