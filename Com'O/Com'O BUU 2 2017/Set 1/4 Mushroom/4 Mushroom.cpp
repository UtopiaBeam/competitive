#include <cstdio>
#include <queue>
#define L long long
using namespace std;
priority_queue<L> hp;
int n, m;
L l ,h, t, x, y, s;
int main() {
    scanf("%d %lld %lld", &m, &l, &h);
    while(m--) {
        scanf("%d", &n);
        while(n--) {
            scanf("%lld", &x);
            hp.push(x);
        }
        scanf("%lld %lld", &x, &y);
        s = l + (x*h)/y + ((x*h)%y > 0)*(x >= 0);
        while(!hp.empty() && hp.top() >= s)
            hp.pop();
        printf("%d\n", hp.size());
    }
    return 0;
}
