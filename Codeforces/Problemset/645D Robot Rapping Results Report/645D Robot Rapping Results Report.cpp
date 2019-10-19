#include <cstdio>
#include <vector>
#include <queue>
#define P pair<int, int>
#define F first
#define S second
#define N 100000
using namespace std;
vector <P> g[N+2];
queue <int> q;
int n, m;
int s, e;
bool chk(int x) {
    int inDeg[N+2] = {};
    while( !q.empty() )     q.pop();
    for(int i = 1; i <= n; i++)
        for(P u : g[i])
            if(u.S <= x)    inDeg[u.F]++;
    for(int i = 1; i <= n; i++)
        if(inDeg[i] == 0)
            q.push(i);
    while( !q.empty() ) {
        if(q.size() > 1)    return false;
        int u = q.front();
        q.pop();
        for(P v : g[u])
            if(v.S <= x) {
                inDeg[v.F]--;
                if(inDeg[v.F] == 0)
                    q.push(v.F);
            }
    }
    return true;
}
int bs(int s, int e) {
    if(s == e) {
        if(s > m)       return -1;
        return s;
    }
    int m = (s+e)/2;
    if( chk(m) )    return bs(s, m);
    return bs(m+1, e);
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &s, &e);
        g[s].push_back( P(e, i) );
    }
    printf("%d\n", bs(1, m+1));
    return 0;
}
