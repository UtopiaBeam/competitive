#include <cstdio>
#include <queue>
using namespace std;
int q;
void fileIO() {
    freopen("C-small-2-attempt0.in", "r", stdin);
    freopen("C-small-2-attempt0.out", "w", stdout);
}
void solve(int t) {
    priority_queue<int> hp;
    int n, k;
    scanf("%d %d", &n, &k);
    hp.push(n);
    while(--k) {
        n = hp.top();
        hp.pop();
        if( (n-1)/2 > 0 )   hp.push( (n-1)/2 );
        if( n/2 > 0 )       hp.push( n/2 );
    }
    if(hp.empty()) {
        printf("Case #%d: 0 0\n", t);
        return;
    }
    n = hp.top();
    printf("Case #%d: %d %d\n", t, n/2, (n-1)/2);
}
int main() {
    fileIO();
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
        solve(i);
    return 0;
}
