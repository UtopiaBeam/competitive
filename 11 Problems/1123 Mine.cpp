//2D Segment tree
#include <cstdio>
#include <algorithm>
#define N 1000
using namespace std;
int n, k;
int a[5][N+2][N+2];
int st[5][4*N+2][4*N+2];
int mx = 0;
void udy(int t, int s, int e, int x, int nw, int v) {
    ;
}
void udx(int t, int s, int e, int nw, int y, int v) {
    if(s == e) {
        udy(t, 1, n, nw, y, v);
        return;
    }

}
int main() {
    scanf("%d %d", &n, &k);
    for(int t = 0; t < 3; t++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                scanf("%d", &a[t][i][j]);
                a[t][i][j] += a[t][i-1][j] + a[t][i][j-1] - a[t][i-1][j-1];
            }
    for(int t = 0; t < 3; t++) {
        for(int i = k; i <= n; i++)
            for(int j = k; j <= n; j++)
                ud(t, 1, n, i, j, a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k]);
    }
    return 0;
}
