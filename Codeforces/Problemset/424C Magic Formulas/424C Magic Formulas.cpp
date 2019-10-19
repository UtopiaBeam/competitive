#include <cstdio>
#define N 1000000
int n, x;
int ans = 0, f[N+2];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        f[i] = f[i-1] ^ i;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if( (n/i) % 2 )
            ans ^= x ^ f[i-1] ^ f[n%i];
        else        ans ^= x ^ f[n%i];
    }
    printf("%d\n", ans);
    return 0;
}
