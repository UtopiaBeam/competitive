#include <cstdio>
#include <stack>
#include <algorithm>
#define L long long
using namespace std;
int r, c, mn;
L dp[102][102];
int main() {
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%lld", &dp[i][j]);
    for(int j = c-2; j >= 0; j--)
        for(int i = 0; i < r; i++)
            dp[i][j] += min(dp[i][j+1], min(dp[(i+1)%r][j+1], dp[(i+r-1)%r][j+1]));
    for(int i = 0; i < r; i++)
        if(dp[mn][0] > dp[i][0])
            mn = i;
    printf("%lld\n%d ", dp[mn][0], mn+1);
    int nw = mn;
    for(int j = 1; j < c; j++) {
        if(dp[(mn+r-1)%r][j] < dp[nw][j])
            nw = (mn+r-1)%r;
        else if(dp[(mn+r-1)%r][j] == dp[nw][j])
            nw = min(nw, (mn+r-1)%r);
        if(dp[(mn+1)%r][j] < dp[nw][j])
            nw = (mn+1)%r;
        else if(dp[(mn+1)%r][j] == dp[nw][j])
            nw = min(nw, (mn+1)%r);
        printf("%d ", nw+1);
        mn = nw;
    }
    return 0;
}
