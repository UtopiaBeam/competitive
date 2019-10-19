#include <cstdio>
#include <algorithm>
#define N 10000000
using namespace std;
bool chk[N+2];
int q, n, cnt, dp[N+2];
int main() {
    for(int i = 3; i <= N; i += 2)
        chk[i] = true;
    for(int i = 3; i*i < N; i += 2)
        if(chk[i]) {
            for(int j = i*i; j <= N; j += i)
                chk[j] = false;
        }
    dp[1] = dp[2] = 1;
    for(int i = 3; i <= N; i++) {
        if(chk[i])      dp[i] = dp[i-2]+1;
        else            dp[i] = dp[i-1]+1;
    }
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}
