#include <cstdio>
#define L long long
int n;
L t, sum = 0, mx = 0, mx_t = -1<<30;
int s, ans_s, ans_e;
bool chk = true, chp = false;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &t);
        if(t > 0)       chp = true;
        else if(!chp){
            if(mx_t < t) {
                mx_t = t;
                ans_s = i;
                ans_e = i;
            }
        }
        if(sum+t < 0) {
            sum = 0;    chk = true;
            continue;
        }
        if(chk) {
            s = i;
            chk = false;
        }
        sum += t;
        if(sum > mx) {
            mx = sum;
            ans_s = s;
            ans_e = i;
        }
    }
    printf("%d %d\n", ans_s, ans_e);
    if(chp)     printf("%lld\n", mx);
    else        printf("%lld\n", mx_t);
    return 0;
}
