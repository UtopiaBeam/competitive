#include <cstdio>
#include <algorithm>
#define INF 1<<30;
using namespace std;
int r, c, mx = 0;
int dp[1002][1002];
char a[1002][1002];
int main() {
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++)
        scanf(" %s", &a[i][1]);
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++) {
            if(a[i][j] == '#')      dp[i][j] = 0;
            else    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            mx = max(mx, dp[i][j]);
        }
    printf("%d\n", mx);
    return 0;
}
