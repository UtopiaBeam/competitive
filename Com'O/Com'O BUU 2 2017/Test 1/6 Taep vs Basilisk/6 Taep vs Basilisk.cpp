#include <cstdio>
#define L long long
int q;
const L x = 900202009;
L n, r;
int main() {
    r = x % 1881;
    scanf("%d", &q);
    while(q--) {
        scanf("%lld", &n);
        if(n < x)   n += 1881 * ( (x-n)/1881 + ( (x-n)%1881 > 0) );
        printf("%lld\n", n-128);
    }
    return 0;
}
