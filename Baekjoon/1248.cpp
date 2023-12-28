#include <iostream>
#define MAX_VALUE 12

using namespace std;

int length;
char signMatrix[MAX_VALUE][MAX_VALUE];
int answer[MAX_VALUE];
bool answerFound = false;

void init() {
    scanf("%d", &length);
    for(int i = 1; i <= length; i++) {
        for(int j = i; j <= length; j++) {
            scanf(" %1c", &signMatrix[i][j]);
        }
    }
}

bool signCheck(int num, char sign) {
    // if(num <= 0 && sign == '+') return false;
    // if(num == 0 && sign != '0') return false;
    // if(num >= 0 && sign == '-') return false;
    // return true;
    if(num > 0 && sign == '+') return true;
    if(num == 0 && sign == '0') return true;
    if(num < 0 && sign == '-') return true;
    return false;
    // if( (num > 0 && sign == '+') || (num == 0 && sign == '0') || (num < 0 && sign == '-') ) {
    //     return true;
    // }
    // else {
    //     return false;
    // }
}

bool isAvaliableNum(int idx, int num) {
    bool avaliable = true;
    if(!signCheck(num, signMatrix[idx][idx])) {
        return false;
    }
    int rangeSum = num;
    for(int i = idx-1; i > 0; i--) {
        if(avaliable == false) {
            break;
        }
        rangeSum += answer[i];
        avaliable = signCheck(rangeSum, signMatrix[i][idx]);
    }
    return avaliable;    
}

void solve(int idx) {
    if(answerFound == true) {
        return;
    }
    else {
        if(idx == length+1) {
            for(int i = 1; i <= length; i++) {
                printf("%d ", answer[i]);
            }
            answerFound = true;
        }
        else {
            for(int i = -10; i <= 10; i++) {
                if(isAvaliableNum(idx, i) == true) { //idx번째에 i가 들어가는 것이 적합한가?
                    // cout << "@ " << "자릿수: " << idx << "숫자: " << i << endl;
                    answer[idx] = i;
                    solve(idx+1);
                }
            }
        }
    }
}

int main() {
    init();
    solve(1);
}