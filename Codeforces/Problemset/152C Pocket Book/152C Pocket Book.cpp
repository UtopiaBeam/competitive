#include <cstdio>
#include <cstring>
#define L long long
#define MOD (L)(1e9 + 7)
int n, m;
L ans = 1;
bool chk[30];
char a[102][102];
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf(" %s", a+i);
    for(int j = 0; j < m; j++) {
        memset(chk, false, sizeof(chk));
        L cnt = 0;
        for(int i = 0; i < n; i++)
            if( !chk[a[i][j]-'A'] ) {
                cnt++;
                chk[a[i][j]-'A'] = true;
            }
        ans = (ans * cnt) % MOD;
    }
    printf("%I64d\n", ans);
    return 0;
}
