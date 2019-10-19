#include <cstdio>
#include <algorithm>
#define INF 1<<30
using namespace std;
int n, mx = -INF;
int dp[1002], a[1002];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            scanf("%d", a+j);
            if(j == 1)          a[j] += dp[j];
            else if(j == i)     a[j] += dp[j-1];
            else                a[j] += max(dp[j-1], dp[j]);
        }
        for(int j = 1; j <= i; j++)
            dp[j] = a[j];
    }
    for(int i = 1; i <= n; i++)
        mx = max(mx, dp[i]);
    printf("%d\n", mx);
    return 0;
}
