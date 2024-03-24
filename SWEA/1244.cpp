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
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

char cardStr[7];
int cardArr[7];
int oppertunity, cardLen;
int maxReward = 0;

void compareMax(int* cardArr) {
  int tmpReward = 0;
  for (int i = 0; i < cardLen; i++) {
    tmpReward += cardArr[i] * pow(10, cardLen - i - 1);
  }
  if (tmpReward > maxReward) maxReward = tmpReward;
}

void solve(int* cardArr, int cnt) {
  if (cnt == oppertunity) {
    compareMax(cardArr);
    return;
  }
  bool alreadyBiggest = true;
  for (int i = 0; i < cardLen - 1; i++) {
    int biggest = *max_element(cardArr + i + 1, cardArr + cardLen);
    if (biggest > cardArr[i]) {  // 바꿀 놈 있는 경우
      alreadyBiggest = false;
      for (int j = i + 1; j < cardLen; j++) {
        if (biggest == cardArr[j]) {
          int nextCardArr[7];
          copy_n(cardArr, cardLen, nextCardArr);
          nextCardArr[i] = cardArr[j];
          nextCardArr[j] = cardArr[i];
          solve(nextCardArr, cnt + 1);
        }
      }
      break;
    }
  }
  if (alreadyBiggest) {  // 바꿀 놈 없는 경우
    set<int> redundancyTest;
    bool redundancy = false;
    for (int i = 0; i < cardLen; i++) {
      if (redundancyTest.find(cardArr[i]) != redundancyTest.end()) {  // 이미 같은 값 나옴
        redundancy = true;
        break;
      } else {  // 처음 보는 값 -> set에 추가
        redundancyTest.insert(cardArr[i]);
      }
    }
    if (redundancy) {  // 배열에 같은 값 있는 경우
      compareMax(cardArr);
      return;
    } else {  // 배열에 같은 값 없는 경우
      if ((oppertunity - cnt) % 2 == 0) {
        compareMax(cardArr);
        return;
      } else {
        int nextCardArr[7];
        copy_n(cardArr, cardLen, nextCardArr);
        nextCardArr[cardLen - 2] = cardArr[cardLen - 1];
        nextCardArr[cardLen - 1] = cardArr[cardLen - 2];
        compareMax(nextCardArr);
        return;
      }
    }
  }
}

int main(int argc, char** argv) {
  int test_case;
  int T;
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
  scanf("%d", &T);
  /*
     여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
  */
  for (test_case = 1; test_case <= T; ++test_case) {
    scanf("%s %d", cardStr, &oppertunity);
    cardLen = strlen(cardStr);
    maxReward = 0;
    for (int i = 0; i < cardLen; i++) {
      cardArr[i] = cardStr[i] - '0';
    }
    solve(cardArr, 0);
    printf("#%d %d\n", test_case, maxReward);
  }
  return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}