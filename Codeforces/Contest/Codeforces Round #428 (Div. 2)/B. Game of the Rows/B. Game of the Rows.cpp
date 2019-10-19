#include <cstdio>
#include <algorithm>
#define N 10000
int n, k;
int a[N+2];
int sum = 0;
bool cmp(int x, int y) {
    return (x % 2) > (y % 2);
}
int main() {
    scanf("%d %d", &n, &k);
    int t2 = 2*n, t4 = n;
    for(int i = 0; i < k; i++) {
        scanf("%d", a+i);
        if(t4 > 0) {
            if(t4 >= a[i]/4) {
                t4 -= a[i]/4;
                a[i] %= 4;
            }
            else {
                a[i] -= t4 * 4;
                t4 = 0;
            }
        }
    }
    std::sort(a, a+k, cmp);
    for(int i = 0; i < k; i++) {
        if(t4 > 0) {
            if(a[i] == 1)       t2++;
            t4--;
        }
        else        t2 -= (a[i]+1)/2;
    }
    if(t2 < 0)      printf("NO\n");
    else            printf("YES\n");
    return 0;
}
