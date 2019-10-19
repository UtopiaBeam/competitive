#include <cstdio>
int q;
int n, p;
int r[10], a[4][10], mn[4][10], mx[4][10];
void fileIO() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out","w", stdout);
}
void solve(int t) {
    int ans = 0;
    scanf("%d %d", &n, &p);
    for(int i = 0; i < n; i++)
        scanf("%d", r+i);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++)
            scanf("%d", &a[i][j]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++) {
            mn[i][j] = (10*a[i][j])/(11*r[i]) + ( (10*a[i][j])%(11*r[i]) > 0 );
            mx[i][j] = (10*a[i][j])/(9*r[i]);
            if(mn[i][j] > mx[i][j])     mx[i][j] = -1;
        }
    if(n == 1) {
        for(int i = 0; i < p; i++)
            if(mx[0][i] > 0)        ans++;
    } else {
        for(int i = 0; i < p; i++)
            for(int j = 0; j < p; j++)
                if(mn[0][i] <= mx[1][j] && mn[1][j] <= mx[0][i])
                    ans++;
    }
    printf("Case #%d: %d\n", t, ans);
}
int main() {
    fileIO();
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
        solve(i);
    return 0;
}
