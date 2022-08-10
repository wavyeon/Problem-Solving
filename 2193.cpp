#include <iostream>
#define MAX_VALUE 91

using namespace std;

int num;
long long pinaryNum[2][MAX_VALUE];

int main() {
    pinaryNum[1][1] = 1;
    for(int i = 2; i < MAX_VALUE; i++) {
        pinaryNum[0][i] = pinaryNum[0][i-1] + pinaryNum[1][i-1];
        pinaryNum[1][i] = pinaryNum[0][i-1];
    }
    cin >> num;
    cout << pinaryNum[0][num] + pinaryNum[1][num] << endl;    
}