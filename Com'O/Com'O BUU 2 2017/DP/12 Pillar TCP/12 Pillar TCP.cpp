#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int q, n;
int a[100002], p[100002];
int dp[100002][4];
int main() {
    scanf("%d", &q);
    while(q--) {
        int mx = 0, idx = 0;
        memset(p, 0, sizeof(p));
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", a+i);
        dp[n][0] = dp[n][1] = 1;
        for(int i = n-1; i > 0; i--) {
            if(a[i] < a[i+1])
        }
    }
    return 0;
}
