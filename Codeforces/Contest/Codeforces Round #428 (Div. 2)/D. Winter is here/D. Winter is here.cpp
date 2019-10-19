#include <cstdio>
#define L long long
#define MOD (L)(1e9 + 7)
#define N 1000000
int n, t;
int cnt[N+2];
L ans = 0;
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &t);
        cnt[t]++;
    }
    for(int i = 2; i <= N; i++) {
        if(cnt[i] == 0)       continue;
        int t = 0;
        for(int j = 2*i; j <= N; j += i)
            ;
    }
    printf("%I64d\n", ans);
    return 0;
}
