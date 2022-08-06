#include <iostream>
#include <cmath>
#define MAX_SCOPE 1000000
#define isPrime 0
#define notPRime 1

using namespace std;

void solve(int isPrimeNumber[MAX_SCOPE]);
void eratosthenes(int isPrimeNumber[MAX_SCOPE]);
void findPrimeNumber(int isPrimeNumber[MAX_SCOPE], int& M, int& N);

int main() {
    int isPrimeNumber[MAX_SCOPE] = {isPrime, };
    solve(isPrimeNumber);
}

void solve(int isPrimeNumber[MAX_SCOPE]) {
    eratosthenes(isPrimeNumber);
    int M, N;
    scanf("%d %d", &M, &N);
    findPrimeNumber(isPrimeNumber, M, N);
}

void eratosthenes(int isPrimeNumber[MAX_SCOPE]) {
    isPrimeNumber[1] = notPRime;
    for(int i = 2; i < sqrt(MAX_SCOPE); i++) {
        if(isPrimeNumber[i] ==  isPrime) {
            for(int j = i * 2; j < MAX_SCOPE; j += i) {
                isPrimeNumber[j] = notPRime;
            } 
        }
    }
}

void findPrimeNumber(int isPrimeNumber[MAX_SCOPE], int& M, int& N) {
    for(int i = M; i <= N; i++) {
        if(isPrimeNumber[i] == isPrime) {
            printf("%d\n", i);
        }
    }
}

