#include <cstdio>
#define L long long
int m;
L n, t[1000002];
bool chk(L x) {
    L cnt = 0;
    for(int i = 0; i < m; i++)
        cnt += x/t[i];
    return cnt >= n;
}
L bs(L s, L e) {
    if(s == e)      return s;
    L md = (s+e)/2;
    if(chk(md))     return bs(s, md);
    return bs(md+1, e);
}
int main() {
    scanf("%d %lld",&m,&n);
    for(int i = 0; i < m; i++)
        scanf("%lld",t+i);
    printf("%lld\n",bs(0, (L)1e18));
    return 0;
}
