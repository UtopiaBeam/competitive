#include <cstdio>
#include <algorithm>
int n, m, mx = 0;
int t[102];
bool chk(int x) {
    int cnt = 1, sum = 0;
    for(int i = 0; i < n; i++) {
        if(sum + t[i] > x) {
            sum = 0;
            cnt++;
        }
        sum += t[i];
    }
    return cnt <= m;
}
int bs(int s, int e) {
    if(s == e)      return s;
    int md = (s+e)/2;
    if(chk(md))     return bs(s, md);
    return bs(md+1, e);
}
int main() {
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", t+i);
        mx = std::max(mx, t[i]);
    }
    printf("%d\n", bs(mx, (int)1e9));
    return 0;
}
