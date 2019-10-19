#include <cstdio>
#include <cstring>
#define MOD (L)(1e9 + 7)
#define L long long
L cnt = 0, ans = 0;
int n;
char a[1000002];
int main() {
    scanf(" %s", a);
    n = strlen(a);
    for(int i = n-1; i >= 0; i--) {
        if(a[i] == 'b')     cnt++;
        else {
            ans = (ans + cnt) % MOD;
            cnt = (cnt * 2) % MOD;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
