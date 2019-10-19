#include <cstdio>
#include <algorithm>
#define N (int)(1e7)
using namespace std;
int n, x, q, l, r;
int f[N+2], cnt[N+2];
bool chk[N+2];
int ans;
int main() {
    for(int i = 2; i*i <= N; i++) {
        if(chk[i])      continue;
        for(int j = i*i; j <= N; j += i)
            chk[j] = true;
    }
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for(int i = 2; i <= N; i++) {
        if(chk[i])      continue;
        for(int j = i; j <= N; j += i)
            f[i] += cnt[j];
    }
    for(int i = 2; i <= N; i++) {
        if(chk[i])      f[i] = 0;
        f[i] += f[i-1];
    }
    scanf("%d", &q);
    while(q--) {
        scanf("%d %d", &l, &r);
        l = min(l, N+1);
        r = min(r, N);
        printf("%d\n", f[r] - f[l-1]);
    }
    return 0;
}
