#include <cstdio>
#define L long long
char a[102];
int cnt[5], n[5];
L p[5], r;
bool chk(L x) {
    L sum = 0;
    for(int i = 0; i < 3; i++)
        if(x*cnt[i] > n[i])
            sum += p[i] * (x*cnt[i] - n[i]);
    return sum <= r;
}
L bs(L s, L e) {
    if(s == e)      return s;
    L m = (s+e+1)/2;
    if( chk(m) )        return bs(m, e);
    return bs(s, m-1);
}
int main() {
    scanf(" %s", a);
    for(int i = 0; a[i]; i++) {
        if(a[i] == 'B')     cnt[0]++;
        if(a[i] == 'S')     cnt[1]++;
        if(a[i] == 'C')     cnt[2]++;
    }
    for(int i = 0; i < 3; i++)
        scanf("%d", n+i);
    for(int i = 0; i < 3; i++)
        scanf("%I64d", p+i);
    scanf("%I64d", &r);
    printf("%I64d\n", bs(0, (L)(1e15) ) );
    return 0;
}
