#include <cstdio>
#define INF 1<<30
int n;
int r[12], c[12];
int dp[12][12], pt[12][12];
int f(int s, int e) {
    if(s == e)      return dp[s][e] = 0;
    if(dp[s][e])    return dp[s][e];
    int ans = INF, tmp;
    for(int i = s; i < e; i++) {
        int ls, rs;
        if(dp[s][i])    ls = dp[s][i];
        else            ls = f(s, i);
        if(dp[i+1][e])  rs = dp[i+1][e];
        else            rs = f(i+1, e);
        tmp = ls + rs + r[s]*c[i]*c[e];
        if(ans > tmp) {
            ans = tmp;
            pt[s][e] = i;
        }
    }
    return dp[s][e] = ans;
}
void show(int s, int e) {
    if(s == e) {
        printf("A%d", s);
        return;
    }
    int m = pt[s][e];
    printf("(");
    show(s, m);
    printf(" x ");
    show(m+1, e);
    printf(")");
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", r+i, c+i);
    printf("%d\n", f(1, n));
    show(1, n);
    return 0;
}
