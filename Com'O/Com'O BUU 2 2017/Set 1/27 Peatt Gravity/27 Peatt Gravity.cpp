#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int r, c, n, mn = 1<<30;
int a[12], x[12], y[12], p[12];
int d[12][12];
int main() {
    scanf("%d %d %d", &r, &c, &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d %d", x+i, y+i, p+i);
        a[i] = i;
    }
    x[n+1] = r-1;   y[n+1] = c-1;
    a[n+1] = n+1;
    for(int i = 0; i <= n+1; i++)
        for(int j = 0; j <= n+1; j++)
            d[i][j] = (int)ceil( sqrt( pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2) ) );
    do {
        int t = 0;
        for(int i = 0; i <= n; i++) {
            mn = min(mn, t+d[a[i]][n+1]);
            t += d[a[i]][a[i+1]] - p[a[i+1]];
        }
    } while(next_permutation(a+1, a+n+1));
    printf("%d\n", mn);
    return 0;
}
