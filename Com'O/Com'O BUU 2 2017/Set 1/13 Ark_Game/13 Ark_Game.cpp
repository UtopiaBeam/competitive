#include <cstdio>
#include <algorithm>
using namespace std;
int n, k;
int a[100002];
bool chk(int m) {
    int cnt = 1, idx = 0;
    while(true) {
        idx = lower_bound(a, a+n, a[idx]+m) - a;
        if(idx < n)     cnt++;
        else        return cnt >= k;
    }
    return cnt >= k;
}
int bs(int s, int e) {
    if(s == e)      return s;
    int m = (s+e+1)/2;
    if(chk(m))      return bs(m, e);
    return bs(s, m-1);
}
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    sort(a, a+n);
    printf("%d\n", bs(0, (int)1e9));
    return 0;
}
