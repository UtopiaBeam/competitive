#include <cstdio>
#include <queue>
#define L long long
using namespace std;
priority_queue<L> hp;
int r, c, k;
L a[1002][1002];
int main() {
    scanf("%d %d %d", &r, &c, &k);
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++) {
            scanf("%lld", &a[i][j]);
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    for(int i = k; i <= r; i++)
        for(int j = k; j <= c; j++)
            hp.push( a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k] );
    L mx = hp.top();
    printf("%lld ", mx);
    while(!hp.empty() && hp.top() == mx)
        hp.pop();
    printf("%lld\n", hp.top());
    return 0;
}
