#include <cstdio>
#define L long long
#define MOD (L)(1e9 + 7)
#define N (int)(1e6)
L a, b, n;
L f[N+2] = {1};
bool isGood(L x) {
    if(x == 0)      return true;
    return (x % 10 == a || x % 10 == b) && isGood(x/10);
}
L pow(L a, L b) {
    if(b == 0)      return 1;
    L x = pow(a, b/2);
    if(b % 2)       return (a * ((x*x) % MOD) % MOD + MOD) % MOD;
    return ((x*x) % MOD + MOD) % MOD;
}
L nCr(L n, L k) {
    return ((f[n] * pow( (f[k] * f[n-k] % MOD + MOD) % MOD, MOD-2)) % MOD + MOD) % MOD;
}
int main() {
    scanf("%I64d %I64d %I64d", &a, &b, &n);
    for(int i = 1; i <= n; i++)
        f[i] = (i * f[i-1]) % MOD;
    L ans = 0;
    for(int i = 0; i <= n; i++)
        if(isGood(a*i + b*(n-i)))
            ans = (ans + nCr(n, i) ) % MOD;
    printf("%I64d\n", ans);
    return 0;
}
