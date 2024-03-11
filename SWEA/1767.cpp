/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX_LENGTH 13

using namespace std;

int test_case;
int T, N, coreCnt;
int processor[MAX_LENGTH][MAX_LENGTH];
vector<pair<int, int>> core;
int maxConnected = 0;
int minLength = 2147483647;

bool isLeftConnected(int idx, int now[][MAX_LENGTH]) {
  for (int i = core[idx].second - 1; i >= 0; i--) {
    if (now[core[idx].first][i] == 1) {
      return false;
    }
  }
  return true;
}

bool isDownConnected(int idx, int now[][MAX_LENGTH]) {
  for (int i = core[idx].first + 1; i < N; i++) {
    if (now[i][core[idx].second] == 1) {
      return false;
    }
  }
  return true;
}

bool isRightConnected(int idx, int now[][MAX_LENGTH]) {
  for (int i = core[idx].second + 1; i < N; i++) {
    if (now[core[idx].first][i] == 1) {
      return false;
    }
  }
  return true;
}

bool isUpConnected(int idx, int now[][MAX_LENGTH]) {
  for (int i = core[idx].first - 1; i >= 0; i--) {
    if (now[i][core[idx].second] == 1) {
      return false;
    }
  }
  return true;
}

void solve(int idx, int now[][MAX_LENGTH], int connected, int length) {
  if (idx == coreCnt) {
    if (connected > maxConnected) {
      maxConnected = connected;
      minLength = length;
    } else if (connected == maxConnected) {
      if (length < minLength) {
        minLength = length;
      }
    }
    return;

  } else {
    if (core[idx].first == 0 || core[idx].first == N - 1 || core[idx].second == 0 || core[idx].second == N - 1) {  // 가장자리 코어인 경우
      solve(idx + 1, now, connected + 1, length);
    } else {
      if (isLeftConnected(idx, now)) {
        int next[MAX_LENGTH][MAX_LENGTH];
        copy(&now[0][0], &now[0][0] + MAX_LENGTH * MAX_LENGTH, &next[0][0]);
        for (int i = core[idx].second - 1; i >= 0; i--) {
          next[core[idx].first][i] = 1;
        }
        solve(idx + 1, next, connected + 1, length + core[idx].second);
      }
      if (isDownConnected(idx, now)) {
        int next[MAX_LENGTH][MAX_LENGTH];
        copy(&now[0][0], &now[0][0] + MAX_LENGTH * MAX_LENGTH, &next[0][0]);
        for (int i = core[idx].first + 1; i < N; i++) {
          next[i][core[idx].second] = 1;
        }
        solve(idx + 1, next, connected + 1, length + (N - core[idx].first - 1));
      }
      if (isRightConnected(idx, now)) {
        int next[MAX_LENGTH][MAX_LENGTH];
        copy(&now[0][0], &now[0][0] + MAX_LENGTH * MAX_LENGTH, &next[0][0]);
        for (int i = core[idx].second + 1; i < N; i++) {
          next[core[idx].first][i] = 1;
        }
        solve(idx + 1, next, connected + 1, length + (N - core[idx].second - 1));
      }
      if (isUpConnected(idx, now)) {
        int next[MAX_LENGTH][MAX_LENGTH];
        copy(&now[0][0], &now[0][0] + MAX_LENGTH * MAX_LENGTH, &next[0][0]);
        for (int i = core[idx].first - 1; i >= 0; i--) {
          next[i][core[idx].second] = 1;
        }
        solve(idx + 1, next, connected + 1, length + core[idx].first);
      }
      int next[MAX_LENGTH][MAX_LENGTH];
      copy(&now[0][0], &now[0][0] + MAX_LENGTH * MAX_LENGTH, &next[0][0]);
      solve(idx + 1, next, connected, length);  // 현재 노드에는 전원 연결하지 않는 경우
    }
  }
};

int main(int argc, char** argv) {
  /*
     아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
     앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
     //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
     freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
     따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
     freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
     단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
  */
  // freopen("input.txt", "r", stdin);
  cin >> T;
  /*
     여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
  */

  for (test_case = 1; test_case <= T; ++test_case) {
    /////////////////////////////////////////////////////////////////////////////////////////////
    core.clear();
    core.reserve(MAX_LENGTH);

    maxConnected = 0;
    minLength = 2147483647;
    coreCnt = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &processor[i][j]);
        if (processor[i][j] == 1) {
          core.push_back({i, j});
          coreCnt++;
        }
      }
    }

    int now[MAX_LENGTH][MAX_LENGTH];
    copy(&processor[0][0], &processor[0][0] + MAX_LENGTH * MAX_LENGTH, &now[0][0]);
    solve(0, now, 0, 0);
    printf("#%d %d\n", test_case, minLength);
    /////////////////////////////////////////////////////////////////////////////////////////////
  }
  return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}