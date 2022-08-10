#include <iostream>
#define MAX_HEIGHT 1000
#define MAX_WIDTH 500

using namespace std;

int paper[MAX_HEIGHT][MAX_WIDTH];
int sum = 0;

void init(int N, int M) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> paper[i][j]; 
        }
    }
}

void firstTetromino(int N, int M) {
    for(int i = 0; i < N-3; i++) {          // 1번 세로
        for(int j = 0; j < M; j++) {
            int verSum = 0;
            for(int k = i; k < i+4; k++) {
                verSum += paper[k][j];
            }
            if(verSum > sum) {
                sum = verSum;
            }
        }
    }
    for(int i = 0; i < N; i++) {           // 1번 가로
        for(int j = 0; j < M-3; j++) {
            int horSum = 0;
            for(int k = j; k < j+4; k++) {
                horSum += paper[i][k];
            }
            if(horSum > sum) {
                sum = horSum;
            }
        }
    }
}

void secondTetromino(int N, int M) {
    for(int i = 0; i < N-1; i++) {          // 2번
        for(int j = 0; j < M-1; j++) {
            int tmpSum = 0;
            tmpSum = paper[i][j] + paper[i+1][j] + paper[i][j+1] + paper[i+1][j+1];
            if(tmpSum > sum) {
                sum = tmpSum;
            }
        }
    }
}

void thirdTetromino(int N, int M) {
    for(int i = 0; i < N-2; i++) {          
        for(int j = 0; j < M; j++) {
            int verSum = 0;
            for(int k = i; k < i+3; k++) {
                verSum += paper[k][j];
            }
            if(j-1 >= 0) {                              
                int verNWSUM = verSum + paper[i][j-1];      //3번 세로 NW
                if(verNWSUM > sum) {
                    sum = verNWSUM;
                }
                int verSWSUm = verSum + paper[i+2][j-1];    //3번 세로 SW
                if(verSWSUm > sum) {
                    sum = verSWSUm;
                }
            }
            if(j+1 < M) {
                int verNESUM = verSum + paper[i][j+1];      //3번 세로 NE
                if(verNESUM > sum) {
                    sum = verNESUM;
                }
                int verSESUM = verSum + paper[i+2][j+1];    //3번 세로 SE
                if(verSESUM > sum) {
                    sum = verSESUM;
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M-2; j++) {
            int horSum = 0;
            for(int k = j; k < j+3; k++) {
                horSum += paper[i][k];
            }
            if(i-1 >= 0) {                              
                int horNWSUM = horSum + paper[i-1][j];      //3번 가로 NW
                if(horNWSUM > sum) {
                    sum = horNWSUM;
                }
                int horNESUm = horSum + paper[i-1][j+2];    //3번 가로 NE
                if(horNESUm > sum) {
                    sum = horNESUm;
                }
            }
            if(i+1 < N) {
                int horSWSUM = horSum + paper[i+1][j];      //3번 가로 SW
                if(horSWSUM > sum) {
                    sum = horSWSUM;
                }
                int horSESUM = horSum + paper[i+1][j+2];    //3번 가로 SE
                if(horSESUM > sum) {
                    sum = horSESUM;
                }
            }
        }
    }
}

void fourthTetromino(int N, int M) {
    for(int i = 0; i < N-1; i++) {
        for(int j = 1; j < M-1; j++) {
            int verSum = paper[i][j] + paper[i+1][j];                   
            int verUpSum = paper[i][j-1] + verSum + paper[i+1][j+1];    //4번 세로 위
            if(verUpSum > sum) {
                sum = verUpSum;
            }
            int verDownSum = paper[i+1][j-1] + verSum + paper[i][j+1];  //4번 세로 아래
            if(verDownSum > sum) {
                sum = verDownSum;
            }
        }
    }
    for(int i = 1; i < N-1; i++) {
        for(int j = 0; j < M-1; j++) {
            int horSum = paper[i][j] + paper[i][j+1];
            int horLeftSum = paper[i-1][j] + horSum + paper[i+1][j+1];  //4번 가로 왼
            if(horLeftSum > sum) {
                sum = horLeftSum;
            }
            int horRightSum = paper[i+1][j] + horSum + paper[i-1][j+1];   //4번 가로 오른
            if(horRightSum > sum) {
                sum = horRightSum;
            }
        }
    }
}

void fifthTetromino(int N, int M) {
    for(int i = 0; i < N-2; i++) {
        for(int j = 0; j < M; j++) {
            int verSum = 0;
            for(int k = i; k < i+3; k++) {
                verSum += paper[k][j];
            }
            if(j-1 >= 0) {                  // 5번 세로 왼
                int verLeftSum = verSum + paper[i+1][j-1];
                if(verLeftSum > sum) {
                    sum = verLeftSum;
                } 
            }
            if(j+1 < M) {                   // 5번 세로 오른
                int verRightSum = verSum + paper[i+1][j+1];
                if(verRightSum > sum) {
                    sum = verRightSum;
                } 
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M-2; j++) {
            int horSum = 0;
            for(int k = j; k < j+3; k++) {
                horSum += paper[i][k];
            }
            if(i-1 >= 0) {              // 5번 가로 위
                int horUpSum = horSum + paper[i-1][j+1];
                if(horUpSum > sum) {
                    sum = horUpSum;
                } 
            }
            if(i+1 < N) {               // 5번 가로 아래
                int horDownSum = horSum + paper[i+1][j+1];
                if(horDownSum > sum) {
                    sum = horDownSum;
                }
            }
        }
    }
}

void solve(int N, int M) {
    firstTetromino(N,M);
    secondTetromino(N,M);
    thirdTetromino(N,M);
    fourthTetromino(N,M);
    fifthTetromino(N,M);
    cout << sum;
}

int main() {
    int N, M;
    cin >> N >> M;
    init(N,M);
    solve(N,M);
}