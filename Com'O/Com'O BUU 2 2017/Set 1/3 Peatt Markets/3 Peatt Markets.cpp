#include <cstdio>
#include <queue>
#define L long long
using namespace std;
priority_queue<L> hp;
int q, n, m, op;
L k, t, cnt, ans;
int main() {
    scanf("%d", &q);
    while(q--) {
        cnt = 0;
        ans = 0;
        scanf("%d %d %lld", &n, &m, &k);
        while(n--) {
            scanf("%lld", &t);
            hp.push(-t);
        }
        while(m--) {
            scanf("%d", &op);
            if(op == 1) {
                scanf("%lld", &t);
                hp.push(-t + cnt);
            } else if(op == 2) {
                cnt += k;
            } else if(op == 3){
                if(!hp.empty())     hp.pop();
            }
        }
        printf("%d ", hp.size());
        while(!hp.empty()) {
            ans += -hp.top() + cnt;
            hp.pop();
        }
        printf("%lld\n", ans);
    }
    return 0;
}
