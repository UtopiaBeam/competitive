#include <cstdio>
#define L long long
#define MOD (L)(1e9 + 7)
char a[102];
L t = 0, ans = 1;
int main(){
    scanf(" %s", a);
    for(int i = 0; a[i+1]; i++){
        ans *= 2;    ans %= MOD;
    }
    for(int i = 0; a[i]; i++){
        t *= 2;   t %= MOD;
        t += a[i]-'0';
        t %= MOD;
    }
    printf("%I64d\n", (ans*t) % MOD);
    return 0;
}
