
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int k, n, m;
int a[1002][1002];
int l[1002][1002], r[1002][1002], u[1002][1002], d[1002][1002];
int main() {
    scanf("%d", &k);
    while(k--) {
        memset(a, 0, sizeof(a));
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(u, 0, sizeof(u));
        memset(d, 0, sizeof(d));
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i][j] >= a[i-1][j])
                    d[i][j] = d[i-1][j]+1;
                else    d[i][j] = 1;
                if(a[i][j] >= a[i][j-1])
                    r[i][j] = r[i][j-1]+1;
                else    r[i][j] = 1;
            }
        }
        for(int i = n; i > 0; i--) {
            for(int j = m; j > 0; j--) {
                if(a[i][j] >= a[i+1][j])
                    u[i][j] = u[i+1][j]+1;
                else    u[i][j] = 1;
                if(a[i][j] >= a[i][j+1])
                    l[i][j] = l[i][j+1]+1;
                else    l[i][j] = 1;
            }
        }
        int mx = 0, mx_r, mx_c;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                int t = 1;
                if(i > 1)   t += d[i][j]-1;
                if(i < n)   t += u[i][j]-1;
                if(j > 1)   t += r[i][j]-1;
                if(j < m)   t += l[i][j]-1;
                if(mx < t) {
                    mx = t;
                    mx_r = i, mx_c = j;
                }
            }
        printf("%d\n%d %d\n", mx, mx_r, mx_c);
    }
    return 0;
}
