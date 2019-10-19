#include <cstdio>
#include <algorithm>
#define INF 1<<30
int q, x[5], y[5], a[5], b[5];
int cnt[5], nx[5], ny[5];
int mn;
int d(int i, int j) {
    return (nx[i] - nx[j]) * (nx[i] - nx[j]) + (ny[i] - ny[j]) * (ny[i] - ny[j]);
}
int dot(int i, int j, int k) {
    return (nx[j] - nx[i]) * (nx[k] - nx[i]) + (ny[j] - ny[i]) * (ny[k] - ny[i]);
}
void f(int n) {
    if(n == 4) {
        int sum = 0;
        for(int i = 0; i < 4; i++) {
            nx[i] = x[i];
            ny[i] = y[i];
            sum += cnt[i];
            for(int j = 0; j < cnt[i]; j++) {
                int tx = nx[i], ty = ny[i];
                nx[i] = a[i] + b[i] - ty;
                ny[i] = b[i] - a[i] + tx;
            }
        }
        bool chk = false;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                for(int k = 0; k < 4; k++)
                    if( d(i, j) == d(i, k) && d(i, j) > 0 && dot(i, j, k) == 0 ) {
                        for(int l = 0; l < 4; l++) {
                            if(l == i || l == j || l == k)      continue;
                            if(nx[i] == nx[l] && ny[i] == ny[l])
                                continue;
                            if(d(l, j) == d(l, k) && d(l, j) > 0 && dot(l, j, k) == 0 )
                                chk = true;
                        }
                    }
        if(chk)     mn = std::min(mn, sum);
        return;
    }
    for(int i = 0; i < 4; i++) {
        cnt[n] = i;
        f(n+1);
    }
}
int main() {
    scanf("%d", &q);
    while(q--) {
        mn = INF;
        for(int i = 0; i < 4; i++)
            scanf("%d %d %d %d", x+i, y+i, a+i, b+i);
        f(0);
        if(mn < INF)        printf("%d\n", mn);
        else                printf("-1\n");
    }
    return 0;
}
