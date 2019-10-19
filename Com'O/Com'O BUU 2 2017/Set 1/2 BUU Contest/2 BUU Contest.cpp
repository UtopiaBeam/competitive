#include <cstdio>
#include <queue>
#define L long long
using namespace std;
priority_queue<L> q;
int day, n, m;
L k, t, ans = 0;
int main() {
    scanf("%d %lld", &day, &k);
    for(int d = 0; d < day; d++) {
        scanf("%d %d", &n, &m);
        while(n--) {
            scanf("%lld", &t);
            q.push(t - k*d);
        }
        while(m--) {
            ans += q.top() + k*d;
            q.pop();
        }
    }
    printf("%lld\n", ans);
    return 0;
}
