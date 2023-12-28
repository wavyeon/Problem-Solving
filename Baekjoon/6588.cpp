#include <iostream>
#include <cmath>
#define MAX_SCOPE 1000000
#define MAX_TESTCASE 100000
#define isPrime 0
#define notPRime 1

using namespace std;

void solve(int isPrimeNumber[MAX_SCOPE]);
void eratosthenes(int isPrimeNumber[MAX_SCOPE]);

int main() {
    int isPrimeNumber[MAX_SCOPE] = {isPrime, };
    solve(isPrimeNumber);
}

void solve(int isPrimeNumber[MAX_SCOPE]) {
    eratosthenes(isPrimeNumber);
    int input = 0;
    int i = 0;
    int allTestcase[MAX_TESTCASE] = {0, };
    while(true) {
        cin >> input;
        if(input == 0) {
            break;
        }
        else {
            allTestcase[i] = input;
            i++;
        }
    }
    for(int j = 0; j < i; j++) {
        for(int k = 3; k < MAX_SCOPE; k++) {
            if(isPrimeNumber[k] == isPrime && isPrimeNumber[allTestcase[j] - k] == isPrime) {
                printf("%d = %d + %d\n", allTestcase[j], k, allTestcase[j] - k);
                break;
            }
        }
    }
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

