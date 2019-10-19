#include <cstdio>
#include <cstring>
char str[200002], a[200002];
int n, la;
int q[200002], hs[200002];
bool chk(int m) {
    memset(hs, 0, sizeof(hs));
    for(int i = 0; i < m; i++)
        hs[q[i]-1] = 1;
    int na = 0;
    for(int i = 0; i < n; i++) {
        if(na == la)    break;
        if(hs[i])   continue;
        if(str[i] == a[na])   na++;
    }
    return na == la;
}
int bs(int s, int e) {
    if(s == e)  return s;
    int m = (s+e+1)/2;
    if(chk(m))      return bs(m, e);
    return bs(s, m-1);
}
int main() {
    scanf(" %s %s",str,a);
    n = strlen(str);
    la = strlen(a);
    for(int i = 0; i < n; i++)
        scanf("%d",q+i);
    printf("%d\n",bs(0, n));
    return 0;
}
