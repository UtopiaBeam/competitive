#include <cstdio>
#define N 100
#define M 10
#define L long long
#define INF (L)(1e18)

L dp[N+2][M+2], c[M+2];
int p[N+2], cnt[M+2];
L n;

int main() {
    scanf("%lld", &n);
    for (int i = 1; i < M; i++)
        scanf("%lld", c+i);
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j < M; j++)
            dp[i][j] = INF;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j < M; j++)
            for (int k = 1; k < M; k++)
                if (dp[i][j] >= dp[i-1][k] + c[j]) {
                    dp[i][j] = dp[i-1][k] + c[j];
                    p[i] = k;
                }
    return 0;
}