    #include <iostream>
    #include <vector>

    using namespace std;

    int gcd(int M, int N) {
        while(N != 0) {
            int r = M % N;
            M = N;
            N = r;
        }
        return M;
    }

    int lcm(int M, int N) {
        return M*N / gcd(M,N);
        
    }

    int main() {
        int testCase;
        scanf("%d", &testCase);
        vector<int> output;
        int M, N, x, y;
        for(int i = 0; i < testCase; i++) {
            scanf("%d %d %d %d", &M, &N, &x, &y);
            int selectedQuotient;
            int selectedRemainder;
            int unselectedQuotient;
            int unselectedRemainder;
            int found = 0;
            int max;
            if(M >= N) {
                selectedQuotient = M;
                selectedRemainder = x;
                unselectedQuotient = N;
                unselectedRemainder = y;
                max = lcm(M, N);
            }
            else {
                selectedQuotient = N;
                selectedRemainder = y;
                unselectedQuotient = M;
                unselectedRemainder = x;
                max = lcm(N, M);
            }
            for(int j = 0; selectedQuotient * j + selectedRemainder <= max; j++) {
                if( ((selectedQuotient*j+selectedRemainder)-unselectedRemainder) % unselectedQuotient == 0) {
                    output.push_back(selectedQuotient * j + selectedRemainder);
                    found = 1;
                    break;
                }
            }
            if(found != 1) {
                output.push_back(-1);
            }
        }
        for(int i = 0; i < testCase; i++) {
            printf("%d\n", output[i]);
        }
    }