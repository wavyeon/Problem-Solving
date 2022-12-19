// stack 두 개 이용한 풀이
#include <iostream>
#include <stack>
#define endl '\n'

using namespace std;

string input;
int inst;
stack<char> leftS, rightS;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> input;
    for(int i = 0; i < input.length(); i++) {
        leftS.push(input[i]);
    }
    cin >> inst;
}

void solve() {
    char type, alpha;
    for(int i = 0; i < inst; i++) {
        cin >> type;
        switch (type) {
            case 'L':
                if(!leftS.empty()) {
                    rightS.push(leftS.top());
                    leftS.pop();
                }
                break;
            case 'D':
                if(!rightS.empty()) {
                    leftS.push(rightS.top());
                    rightS.pop();
                }
                break;
            case 'B':
                if(!leftS.empty()) {
                    leftS.pop();
                }
                break;
            case 'P':
                cin >> alpha;
                leftS.push(alpha);
        }
    }
    while(!leftS.empty()) {
        rightS.push(leftS.top());
        leftS.pop();
    }
    while(!rightS.empty()) {
        cout << rightS.top();
        rightS.pop();
    }
}

int main() {
    init();
    solve(); 
}



// list 이용한 풀이
// #include <iostream>
// #include <string>
// #include <list>

// using namespace std;

// int main()
// {
//     int inst;
//     string s;
//     string ans;

//     cin >> s;
//     // 연결리스트에 원소 할당
//     list<char> li(s.begin(), s.end());

//     // 커서위치를 입력된 문자 제일 끝에 위치
//     auto cursor = li.end();
//     cin >> inst;

//     for (int i = 0; i < inst; i++)
//     {
//         char cmd, c;
//         cin >> cmd;
//         if (cmd == 'L')
//         {
//             if (cursor != li.begin())
//                 cursor--;
//         }
//         else if (cmd == 'D')
//         {
//             if (cursor != li.end())
//                 cursor++;
//         }
//         else if (cmd == 'B')
//         {
//             if (cursor != li.begin()) // 맨 왼쪽이 아니라면
//             {
//                 cursor--;
//                 cursor = li.erase(cursor); // 삭제
//             }
//         }
//         else if (cmd == 'P')
//         {
//             cin >> c;
//             li.insert(cursor, c); // 문자 c 삽입
//         }
//     }

//     // 연결리스트 출력
//     for (cursor = li.begin(); cursor != li.end(); cursor++)
//         cout << *cursor;
// }