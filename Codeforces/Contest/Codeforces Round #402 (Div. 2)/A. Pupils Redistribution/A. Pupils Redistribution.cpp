#include <cstdio>
#include <algorithm>
int cnt[7];
int a[7], b[7];
int n, t, ans = 0;
int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&t);
        a[t]++;     cnt[t]++;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d",&t);
        b[t]++;     cnt[t]++;
    }
    for(int i = 1; i <= 5; i++) {
        if(cnt[i]&1) {
            printf("-1\n");
            return 0;
        }
        cnt[i] >>= 1;
    }
    for(int i = 1; i <= 5; i++)
        ans += abs(a[i]-cnt[i]);
    printf("%d\n",ans>>1);
    return 0;
}
