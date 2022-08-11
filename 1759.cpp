#include <iostream>
#include <stack>
#include <algorithm>
#define MAX_VALUE 16
#define Visited 1
#define notVisited 0

using namespace std;

int numOfAlphabet, passwordLength;
char alphabet[MAX_VALUE];
int isVisited[MAX_VALUE];
stack<char> password;
char output[MAX_VALUE];

void init() {
    scanf("%d %d", &passwordLength, &numOfAlphabet);
    for(int i = 0; i < numOfAlphabet; i++) {
        scanf(" %c", &alphabet[i]);
        // cin >> alphabet[i];
    }
    sort(alphabet, alphabet + numOfAlphabet);
}

void printPassword() {
    stack<char> tmp;
    tmp = password;
    for(int i = 0; i < passwordLength; i++) {
        output[passwordLength-1 - i] = tmp.top();
        tmp.pop();
    }
    for(int i = 0; i < passwordLength; i++) {
        printf("%c", output[i]);
    }
    cout << endl;
}

void solve(int index, int vowelCount, int consonantCount) {
    if(password.size() == passwordLength && vowelCount >= 1 && consonantCount >= 2) {
        printPassword();
        // cout << vowelCount << " " << consonantCount << endl;
    }
    else {
        for(int i = index; i < numOfAlphabet; i++) {
            if(isVisited[i] == notVisited) {
                isVisited[i] = Visited;
                password.push(alphabet[i]);
                if(alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' || alphabet[i] == 'u') {
                    solve(i+1, vowelCount+1, consonantCount);
                }
                else {
                    solve(i+1, vowelCount, consonantCount+1);
                }
                password.pop();
                isVisited[i] = notVisited;
            }
        }
    }    
}

int main() {
    init();
    solve(0,0,0);
}

//https://dbstndi6316.tistory.com/33