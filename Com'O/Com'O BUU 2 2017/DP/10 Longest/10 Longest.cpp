#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int k, n, m;
char a[1002][1002];
int l[1002][1002], r[1002][1002], u[1002][1002], d[1002][1002];
int main() {
    scanf("%d", &k);
    while(k--) {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(u, 0, sizeof(u));
        memset(d, 0, sizeof(d));
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf(" %s", &a[i][1]);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i][j] == '0') {
                    r[i][j] = 0;
                    d[i][j] = 0;
                } else {
                    r[i][j] = r[i][j-1]+1;
                    d[i][j] = d[i-1][j]+1;
                }
            }
        }
        for(int i = n; i > 0; i--) {
            for(int j = m; j > 0; j--) {
                if(a[i][j] == '0') {
                    l[i][j] = 0;
                    u[i][j] = 0;
                } else {
                    l[i][j] = l[i][j+1]+1;
                    u[i][j] = u[i+1][j]+1;
                }
            }
        }
        int mx = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                if(a[i][j] == '0')      continue;
                mx = max(mx, l[i][j]+u[i][j]-1);
                mx = max(mx, r[i][j]+u[i][j]-1);
                mx = max(mx, l[i][j]+d[i][j]-1);
                mx = max(mx, r[i][j]+d[i][j]-1);
            }
        printf("%d\n", mx);
    }
    return 0;
}
