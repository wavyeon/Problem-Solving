#include <iostream>

using namespace std;

int subject;
const int MAX = 10001;
double score[MAX];

int main() {
    scanf("%d", &subject);
    for(int i = 0; i < subject; i++) {
        scanf("%lf", &score[i]);
    }
    double maxScore = score[0];
    double scoreSum = 0;
    for(int i = 0; i < subject; i++) {
        if(maxScore < score[i]) {
            maxScore = score[i];
        }
        scoreSum += score[i];
    }
    scoreSum = scoreSum / maxScore * 100;
    printf("%lf", scoreSum / subject);


}