#include <cstdio>
#include <algorithm>
int n, k;
int t, r = 0;
int main() {
    bool chk = true;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t);
        if(chk) {
            t += r;
            r = 0;
        }
        if(t > 8) {
            r += t - 8;
            t = 8;
        }
        if(r + t >= 8) {
            r -= 8 - t;
            t = 8;
        }
        if(k <= t || t == 8) {
            k -= t;
            chk = false;
        }
        else {
            r += t;
            chk = true;
        }
        if(k <= 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
