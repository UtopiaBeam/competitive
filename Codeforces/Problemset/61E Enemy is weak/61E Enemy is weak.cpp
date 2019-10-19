#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#define L long long
using namespace std;
map<int, int> mp;
int n, a[1000002], b[1000002];
L l[1000002], r[1000002];
L ans = 0, ft[1000002];
void ud(int x) {
    for(;x <= n; x += -x&x)     ft[x]++;
}
int qr(int x) {
    int sum = 0;
    for(;x ; x -= -x&x)     sum += ft[x];
    return sum;
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a+i);
        b[i] = a[i];
    }
    sort(b, b+n);
    for(int i = 0; i < n; i++)
        mp[ b[i] ] = i+1;
    for(int i = n-1; i > 0; i--) {
        int x = mp[ a[i] ];
        r[i] = qr(x);
        ud(x);
    }
    memset(ft, 0, sizeof(ft));
    for(int i = 0; i < n; i++) {
        int x = mp[ a[i] ];
        l[i] = i - qr(x);
        ud(x);
    }
    for(int i = 0; i < n; i++)
        ans += l[i] * r[i];
    printf("%I64d\n", ans);
    return 0;
}
