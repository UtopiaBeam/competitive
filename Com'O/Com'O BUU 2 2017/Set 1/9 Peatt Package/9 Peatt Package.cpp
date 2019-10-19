#include <cstdio>
#include <cstring>
#include <algorithm>
int hs[100002], w[100002], c[100002];
int t, n, k, mx;
bool chk(int m) {
    int cnt = 1, sum = 0;
    memset(hs, 0, sizeof(hs));
    for(int i = 0; i < n; i++) {
        if(sum+w[i] > m || hs[c[i]] == cnt) {
            cnt++;      sum = 0;
        }
        sum += w[i];
        hs[c[i]] = cnt;
    }
    return cnt <= k;
}
int bs(int s, int e) {
    if(s == e) {
        if(s > (int)1e8)    return -1;
        return s;
    }
    int m = (s+e)/2;
    if( chk(m) )    return bs(s, m);
    return bs(m+1, e);
}
int main() {
    scanf("%d", &t);
    while(t--) {
        mx = 0;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", w+i, c+i);
            mx = std::max(mx, w[i]);
        }
        printf("%d\n", bs(mx, (int)2e8));
    }
    return 0;
}
