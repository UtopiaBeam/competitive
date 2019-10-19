#include <cstdio>
#include <algorithm>
int n, b, mx;
int a[500002];
bool chk(int m) {
    int t = b;
    for(int i = 0; i < n; i++)
        t -= a[i]/m + (a[i]%m > 0);
    return t >= 0;
}
int bs(int s, int e) {
    if(s == e)      return s;
    int m = (s+e)/2;
    if( chk(m) )    return bs(s, m);
    return bs(m+1, e);
}
int main() {
    scanf("%d %d", &n, &b);
    for(int i = 0; i < n; i++) {
        scanf("%d", a+i);
        mx = std::max(mx, a[i]);
    }
    printf("%d\n", bs(1, mx));
    return 0;
}
