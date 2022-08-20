#include <iostream>
#include <string>
#define MAX_VALUE 21

using namespace std;

int numOfInst;
// bool set[MAX_VALUE];
int bit;

void action () {
    string instruction;
    cin >> instruction;
    if(instruction == "add") {
        int idx;
        cin >> idx;
        bit |= (1 << idx-1);
    }
    else if(instruction == "remove") {
        int idx;
        cin >> idx;
        bit &= ~(1 << idx-1);
    }
    else if(instruction == "check") {
        int idx;
        cin >> idx;
        int mask = (1 << idx-1);
        if( (bit & mask) != 0) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
    else if(instruction == "toggle") {
        int idx;
        cin >> idx;
        int mask = (1 << idx-1);
        // int preserve = bit & (~mask);  //변하는 부분 0으로 죽여놓고 나머지 부분 살려놓음
        // int change = (~bit) & mask; //변하는 부분 | 나머지 부분 | 0   
        // bit = preserve | change; 
        bit ^= mask;
    }
    else if(instruction == "all") {
        bit |= ~0;
    }
    else if(instruction == "empty") {
        bit = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> numOfInst;
    for(int i = 0; i < numOfInst; i++) {
        action();
    }
}