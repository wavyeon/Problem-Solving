#include <iostream>
#include <vector>
#include <cmath>
#define MAX_VALUE 10
#define Selected 1
#define notSelected 0

using namespace std;

char inequalitySign[MAX_VALUE];
int numberOfSign;
int blankNumber[MAX_VALUE];
bool isSelected[MAX_VALUE];
vector<string> answers;
int answer, sizeOrder;

void init() {
    scanf("%d", &numberOfSign);
    for(int i = 1; i <= numberOfSign; i++) {
        scanf(" %c", &inequalitySign[i]);
    }
}

void selectNumber(int index) {
    // cout << index << ": " << blankNumber[index] << endl;
    if(index == numberOfSign+1) {
        //test
        // for(int i = 0; i <= numberOfSign; i++) {
        //     cout << blankNumber[i] << " ";
        // }
        // cout << endl;
        char ans[MAX_VALUE];
        for(int i = 0; i <= numberOfSign; i++) {
            ans[i] = blankNumber[i] + '0';
        }
        string str(ans);
        answers.push_back(str);
    }
    else {
        for(int i = 0; i < 10; i++) {
            if(isSelected[i] == notSelected) {
                if(inequalitySign[index] == '<' && blankNumber[index-1] < i) {
                    blankNumber[index] = i;
                    isSelected[i] = Selected;
                    selectNumber(index+1);
                    isSelected[i] = notSelected;
                }
                else if(inequalitySign[index] == '>' && blankNumber[index-1] > i) {
                    blankNumber[index] = i;
                    isSelected[i] = Selected;
                    selectNumber(index+1);
                    isSelected[i] = notSelected;
                }
            }
        }   
    }
    
}

void solve() {
    for(int i = 0; i < 10; i++) {
        blankNumber[0] = i;
        isSelected[i] = Selected;
        selectNumber(1);
        isSelected[i] = notSelected;
    }
}

void print() {
    for(int i = 0; i <= numberOfSign; i++) {
        cout << answers[answers.size()-1][i];
    }
    cout << endl;
    for(int i = 0; i <= numberOfSign; i++) {
        cout << answers[0][i];
    }
    cout << endl;
}

int main() {
    init();
    solve();
    print();
}