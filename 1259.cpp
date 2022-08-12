#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> yesorno;

void solve(string input) {
    int start = 0;
    int end = input.length()-1;
    string ans = "yes";
    while(!(start >= end)) {
        if(input[start] != input[end]) {
            ans = "no";
        }
        start++;
        end--;
    }
    yesorno.push_back(ans);
}

int main() {
    string input;
    while(true) {
        cin >> input;
        if(input == "0") {
            break;
        }
        solve(input);
    }
    for(int i = 0; i < yesorno.size(); i++) {
        cout << yesorno[i] << endl;
    }
}