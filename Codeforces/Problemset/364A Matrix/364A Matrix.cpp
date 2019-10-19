#include <cstdio>
#include <cstring>
#define L long long
#define N 40000
using namespace std;
L x, a[4005];
char s[4005];
L hs[N+2];
int main() {
    scanf("%I64d %s", &x, s);
    int n = strlen(s);
    for(int i = 0; s[i]; i++)
        a[i+1] = (L)(s[i] - '0');
    for(int i = 1; i <= n; i++)
        a[i] += a[i-1];
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < i; j++)
            hs[ a[i]-a[j] ]++;
    L cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(hs[i] == 0)      continue;
        if(x%i == 0 && x/i <= N)
            cnt += hs[i] * hs[x/i];
    }
    if(x == 0)      cnt += hs[0] * (n * (n+1)) / 2;
    printf("%I64d\n", cnt);
    return 0;
}
