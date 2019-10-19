#include <cstdio>
#include <algorithm>
using namespace std;
int q, n, mx = 0;
int a[1002];
int ls[1002], l[1002], r[1002];
int bs(int s, int e, int x) {
    if(s == e)      return s;
    int m = (s+e+1)/2;
    if(ls[m] < x)   return bs(m, e, x);
    return bs(s, m-1, x);
}
int main() {
    a[0] = -1<<30;
    scanf("%d", &q);
    while(q--) {
        for(int i = 1; i <= n; i++)
            ls[i] = 0;
        mx = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", a+i);
        for(int i = 1; i <= n; i++) {
            int len = bs(0, mx, a[i])+1;
            ls[len] = a[i];
            l[i] = len;
            mx = max(mx, len);
        }
        mx = 0;
        for(int i = 1; i <= n; i++)
            ls[i] = 0;
        for(int i = n; i > 0; i--) {
            int len = bs(0, mx, a[i])+1;
            ls[len] = a[i];
            r[i] = len;
            mx = max(mx, len);
        }
        mx = 0;
        for(int i = 1; i <= n; i++)
            mx = max(mx, l[i]+r[i]-1);
        printf("%d\n", mx);
    }
    return 0;
}
