#include <cstdio>
#include <algorithm>
using namespace std;
int n, p, cnt = 0, mn = 1<<30, mx;
char a[1000002];
int main() {
    scanf("%d %d %s", &n, &p, a+1);
    if(p > n/2)     p = n + 1 - p;
    for(int i = 1; i <= n/2; i++) {
        cnt += min( (a[n+1-i]-a[i]+26) % 26, (a[i]-a[n+1-i]+26) % 26 );
        if(a[i] != a[n+1-i]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    if(mn == 1<<30)     printf("0\n");
    else {
        if(p < mn)          cnt += mx - p;
        else if(p > mx)     cnt += p - mn;
        else        cnt += (mx - mn) + min(p-mn, mx-p);
        printf("%d\n", cnt);
    }
    return 0;
}
