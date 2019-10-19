#include <cstdio>
#include <queue>
#include <algorithm>
#define P pair<int, int>
#define PP pair<P, int>
#define F first
#define S second
using namespace std;
priority_queue<P> hp;
PP a[300002];
int n, k;
int ans = 0, mx = 0;
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].F.F, &a[i].F.S);
        a[i].S = i;
    }
    sort(a, a+n);
    if(k == 1) {
        for(int i = 0; i < n; i++) {
            if(mx < a[i].F.S-a[i].F.F+1) {
                mx = a[i].F.S-a[i].F.F+1;
                ans = a[i].S;
            }
        }
        printf("%d\n%d\n", mx, ans+1);
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(hp.size() == k-1) {
            mx = max(mx, min(-hp.top().F, a[i].F.S) -a[i].F.F+1);
            if(-hp.top().F < a[i].F.S) {
                hp.pop();
                hp.push( P(-a[i].F.S, a[i].S) );
            }
        }
        else        hp.push( P(-a[i].F.S, a[i].S) );
    }
    printf("%d\n", mx);
    if(mx == 0) {
        for(int i = 1; i <= k; i++)
            printf("%d ", i);
        return 0;
    }
    while(!hp.empty())
        hp.pop();
    for(int i = 0; i < n; i++) {
        if(hp.size() == k-1) {
            if( mx == min(-hp.top().F, a[i].F.S) -a[i].F.F+1 ) {
                while(!hp.empty()) {
                    printf("%d ", hp.top().S+1);
                    hp.pop();
                }
                printf("%d\n", a[i].S+1);
                return 0;
            }
            if(-hp.top().F < a[i].F.S) {
                hp.pop();
                hp.push( P(-a[i].F.S, a[i].S) );
            }
        }
        else       hp.push( P(-a[i].F.S, a[i].S) );
    }
    return 0;
}
