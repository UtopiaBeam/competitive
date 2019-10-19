#include <cstdio>
#include <cstring>
#include <algorithm>
int q, n, k;
char a[1002];
void fileIO() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
}
void solve(int t) {
    scanf(" %s %d", a, &k);
    n = strlen(a);
    int cnt = 0;
    for(int i = 0; i <= n-k; i++) {
        if(a[i] == '-') {
            cnt++;
            for(int j = i; j < i+k; j++)
                if(a[j] == '+')     a[j] = '-';
                else                a[j] = '+';
        }
    }
    bool chk = true;
    for(int i = 0; i < n; i++)
        if(a[i] == '-')     chk = false;
    printf("Case #%d: ", t);
    if(chk)     printf("%d\n", cnt);
    else        printf("IMPOSSIBLE\n");
}
int main() {
    fileIO();
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
        solve(i);
    return 0;
}
