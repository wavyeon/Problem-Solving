#include <iostream>
#include <cmath>

using namespace std;

int N, x, y, blockSize, index;

void init() {
    cin >> N >> y >> x;
    blockSize = pow(2,N);
}

void solve() {
    int halfLength = blockSize/2;
    for(int i = 0; i < N; i++) {
        if(x / halfLength == 0 && y / halfLength == 0) {
            // cout << "1사분면" << " " << halfLength << endl;
        }
        else if(x / halfLength == 1 && y / halfLength == 0) {
            // cout << "2사분면" << " " << halfLength << endl;
            index += pow(halfLength, 2);
        }
        else if(x / halfLength == 0 && y / halfLength == 1) {
            // cout << "3사분면" << " " << halfLength << endl;
            index += (2 * pow(halfLength, 2));
        }
        else if(x / halfLength == 1 && y / halfLength == 1) {
            // cout << "4사분면" << " " << halfLength << endl;
            index += (3 * pow(halfLength, 2));
        }
        x %= halfLength;
        y %= halfLength;
        halfLength /= 2;
    }
}

int main() {
    init();
    solve();
    cout << index << endl;
}