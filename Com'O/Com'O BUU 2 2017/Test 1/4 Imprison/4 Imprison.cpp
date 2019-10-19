#include <cstdio>
#include <algorithm>
#define INF 1<<30
using namespace std;
int r, c, n;
int x[12], y[12], cnt[12];
int d(int i, int j, int k) {
    return abs(i - x[k]) + abs(j - y[k]);
}
int main() {
    scanf("%d %d %d", &r, &c, &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", x+i, y+i);
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++) {
            int mn = INF, id;
            for(int k = 0; k < n; k++)
                if(mn > d(i, j, k) ) {
                    mn = d(i, j, k);
                    id = k;
                }
            cnt[id]++;
        }
    for(int i = 0; i < n; i++)
        printf("%d\n", cnt[i]);
    return 0;
}
