#include <cstdio>
#include <algorithm>
#define L long long
int n;
L k;
L h[1000002];
bool chk(L m) {
    L cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += std::max(h[i]-m, 0LL);
    return cnt >= k;
}
L bs(L s, L e) {
    if(s == e)      return s;
    int m = (s+e+1)/2;
    if(chk(m))      return bs(m, e);
    return bs(s, m-1);
}
int main() {
    scanf("%d %lld", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%lld", h+i);
    printf("%lld\n", bs(0, (L)2e9));
    return 0;
}
