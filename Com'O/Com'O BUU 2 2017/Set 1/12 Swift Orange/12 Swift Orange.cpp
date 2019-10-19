#include <cstdio>
int n, p;
int a[1000002];
bool chk(int m) {
    int cnt = 0;
    for(int i = 0;i < n; i++)
        cnt += a[i]/m;
    return cnt >= p;
}
int bs(int s, int e) {
    if(s == e)      return s;
    int m = (s+e+1)/2;
    if(chk(m))      return bs(m, e);
    return bs(s, m-1);
}
int main() {
    scanf("%d %d", &n, &p);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    int ans = bs(1, (int)1e9), cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += a[i]/ans;
    if(cnt == p)    printf("YES\n");
    else            printf("NO\n");
    printf("%d\n", ans);
    return 0;
}
