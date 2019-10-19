#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define L long long
using namespace std;
vector <int> g[300002];
int n, s, e, deg[300002];
L a[300002], mx = 0;
struct S {
    int x;
    S(int x = 0):   x(x){}
    bool operator < (S t) const {
        if(deg[x] != deg[t.x])
            return deg[x] < deg[t.x];
        return a[x] < a[t.x];
    }
}nw;
priority_queue <S> hp;
bool off[300002];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%I64d", a+i);
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &s, &e);
        g[s].push_back(e);
        g[e].push_back(s);
        deg[s]++;       deg[e]++;
    }
    for(int i = 1; i <= n; i++)
        hp.push( S(i) );
    while( !hp.empty() ) {
        nw = hp.top();
        hp.pop();
        s = nw.x;
        if(off[s])          continue;
        printf("(%d)\n", s);
        off[s] = true;
        deg[s] = -1;
        mx = max(mx, a[s]);
        for(int e : g[s]) {
            if(off[e])      continue;
            a[e]++;     deg[e]--;
            hp.push( S(e) );
            for(int v : g[e]) {
                if(off[v])      continue;
                a[v]++;
                hp.push( S(v) );
            }
        }
        for(int i = 1; i <= n; i++) {
            if(off[i])      printf("- ");
            else    printf("%I64d ", a[i]);
        }
        printf("\n");
    }
    printf("%I64d\n", mx);
    return 0;
}

