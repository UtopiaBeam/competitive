#include <cstdio>
#include <algorithm>
using namespace std;
int n, k;
int a[100002];
int cnt = 0;
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", a+i);
        a[i] *= -1;
    }
    sort(a, a+n);
    for(int i = 0; i < n; i++) {
        a[i] *= -1;
        cnt += a[i]/(2*k);
        if(a[i]%(2*k) > k) {
            cnt++;
        } else if (a[i]%(2*k) > 0) {
            cnt++;
            a[i+1] += k;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
