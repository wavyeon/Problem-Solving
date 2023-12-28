#include <iostream>
#include <string>
#define MAX_LENGTH 1000001

using namespace std;

string input;
int count;

int main() {
    getline(cin, input);
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == ' ') {
            count++;
        }
    }
    if(input[0] == ' ') count--;
    if(input[input.length()-1] == ' ') count--;
    cout << count+1 << endl;
}