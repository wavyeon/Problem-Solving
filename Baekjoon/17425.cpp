#include <iostream>
#define MAX 1000000

using namespace std;

long long fx[MAX+1] = {0, };
long long gx[MAX+1] = {0, };

void solve(int T) {
    for(int i = 1; i <= MAX; i++) {
        for(int j = 1; i * j <= MAX; j++) {
            fx[i*j] += i;
        }
    }
    for(int i = 1; i <= MAX; i++) {
        gx[i] = gx[i-1] + fx[i];
    }
    for(int i = 0; i < T; i++) {
        int num;
        scanf("%d", &num);
        printf("%lld\n", gx[num]);
    }
}

int main() {
    int T;
    cin >> T;
    solve(T);
}