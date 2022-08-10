#include <iostream>
#include <string>
#define MAX_SCOPE 10001

using namespace std;

int instNum, start, endd;
int queue[MAX_SCOPE];

void action(string inst) {
    if(inst == "push") {
        int num;
        scanf("%d", &num);
        queue[endd] = num;
        endd++;
    }
    else if(inst == "pop") {
        if(endd == start) {
            printf("%d\n", -1);
        }
        else {
            printf("%d\n", queue[start]);
            queue[start] = 0;
            start++;
        }
    }
    else if(inst == "size") {
        printf("%d\n", endd-start);
    }
    else if(inst == "empty") {
        if(endd-start == 0) {
            printf("%d\n", 1);
        }
        else {
            printf("%d\n", 0);
        }
    }
    else if(inst == "front") {
        if(endd-start == 0) {
            printf("%d\n", -1);
        }
        else {
            printf("%d\n", queue[start]);
        }
    }
    else if(inst == "back") {
        if(endd-start == 0) {
            printf("%d\n", -1);
        }
        else {
            printf("%d\n", queue[endd-1]);
        }
    }
}

int main() {
    cin >> instNum;
    // cin.ignore();
    for(int i = 0; i < instNum; i++) {
        // string inst;
        char inst[100000];
        scanf("%s", inst);
        string inst_string(inst);
        // cin >> inst;
        // getline(cin, inst);
        // cout << inst_string << endl;
        action(inst_string);
    }
}