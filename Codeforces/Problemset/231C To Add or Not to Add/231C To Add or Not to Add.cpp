#include <cstdio>
#include <algorithm>
#define L long long
#define INF 1<<30
int n, k;
L a[100002];
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%I64d", a+i);
    std::sort(a, a+n);
    int l = 0;
    int mx = 0;
    L sum = 0, mn = INF;
    for(int i = 0; i < n; i++) {
        while(l < i && a[i]*(i-l) - sum > k)
            sum -= a[l++];
        if(mx < i+1-l) {
            mx = i+1-l;
            mn = a[i];
        }
        sum += a[i];
    }
    printf("%d %I64d\n", mx, mn);
    return 0;
}
