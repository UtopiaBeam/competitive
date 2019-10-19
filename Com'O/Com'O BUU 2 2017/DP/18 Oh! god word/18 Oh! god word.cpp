#include <cstdio>
#include <cstring>
int dp[1005][1005];
char a[1005];
bool chk[1005][1005];
int mx = 1, mx_s;
int main() {
    scanf(" %s", a);
    int n = strlen(a);
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
        chk[i][i] = true;
    }
    for(int i = 1; i < n; i++) {
        if(a[i-1] == a[i]) {
            chk[i-1][i] = true;
            dp[i-1][i] = 2;
            if(mx < dp[i-1][i]) {
                mx = dp[i-1][i];
                mx_s = i-1;
            }
        }
    }
    for(int k = 3; k <= n; k++)
        for(int i = 0; i < n-k+1; i++) {
            int j = i+k-1;
            if(a[i] == a[j] && chk[i+1][j-1]) {
                dp[i][j] = dp[i+1][j-1]+2;
                chk[i][j] = true;
                if(mx < k) {
                    mx = k;
                    mx_s = i;
                }
            }
        }
    for(int i = mx_s; i < mx_s+mx; i++)
        printf("%c", a[i]);
    return 0;
}
