#include <cstdio>
#include <algorithm>
#define INF 1<<30
using namespace std;
int r, c;
int a[502], dp[502];
int main() {
    scanf("%d %d", &r, &c);
    dp[0] = dp[c+1] = INF;
    while(r--) {
        for(int i = 1; i <= c; i++) {
            scanf("%d", a+i);
            a[i] += min(dp[i-1], min(dp[i], dp[i+1]) );
        }
        for(int i = 1; i <= c; i++)
            dp[i] = a[i];
    }
    int mn = INF;
    for(int i = 1; i <= c; i++)
        mn = min(mn, dp[i]);
    printf("%d\n", mn);
    return 0;
}
