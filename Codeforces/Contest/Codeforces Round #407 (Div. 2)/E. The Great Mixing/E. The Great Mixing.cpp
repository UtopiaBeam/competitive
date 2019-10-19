#include <cstdio>
int n, k, x;
bool dp[1002][1002];
int main() {
    dp[0][0] = true;
    scanf("%d %d", &n, &k);
    while(k--) {
        scanf("%d", &x);
        for(int i = 1; i <= n; i++)
            for(int j = x; j <= k; j++) {
                ;
            }
    }
    return 0;
}
