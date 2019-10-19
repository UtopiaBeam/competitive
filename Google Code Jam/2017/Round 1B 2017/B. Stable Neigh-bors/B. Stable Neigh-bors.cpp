#include <cstdio>
#include <algorithm>
using namespace std;
int q;
int n, a[10];
char ans[1002];
bool chk;
void fileIO() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
}
void f(int r, int y, int b, int nw) {
    if(nw == n) {
        ans[n+1] = '\0';
        printf("%s\n", ans+1);
        return;
    }
    int mx = 0;
    if(ans[nw] != 'R' && r > 0)        mx = max(mx, r);
    if(ans[nw] != 'Y' && y > 0)        mx = max(mx, y);
    if(ans[nw] != 'B' && b > 0)        mx = max(mx, b);
    if(ans[nw] != 'R' && mx == r) {
        ans[nw+1] = 'R';
        f(r-1, y, b, nw+1);
    } else if(ans[nw] != 'Y' && mx == y) {
        ans[nw+1] = 'Y';
        f(r, y-1, b, nw+1);
    } else {
        ans[nw+1] = 'B';
        f(r, y, b-1, nw+1);
    }
}
void solve(int q) {
    scanf("%d", &n);
    for(int i = 0; i < 6; i++)
        scanf("%d", a+i);
    //Small
    printf("Case #%d: ", q);
    for(int i = 0; i < 6; i += 2)
        if(a[i] > n/2) {
            printf("IMPOSSIBLE\n");
            return;
        }
    f(a[0], a[2], a[4], 0);
}
int main() {
//    fileIO();
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
        solve(i);
    return 0;
}
