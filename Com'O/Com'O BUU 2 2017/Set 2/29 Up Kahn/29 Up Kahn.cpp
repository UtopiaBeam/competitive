#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> g[100002], tp;
priority_queue<int> hp;
int q, n, m;
int s, e;
int inDeg[100002];
bool chk;
int main() {
    scanf("%d", &q);
    while(q--) {
        chk = true;
        tp.clear();
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++) {
            g[i].clear();
            inDeg[i] = 0;
        }
        while(m--) {
            scanf("%d %d", &s, &e);
            g[s].push_back(e);
            inDeg[e]++;
        }
        for(int i = 1; i <= n; i++)
            if(inDeg[i] == 0)
                hp.push(-i);
        while( !hp.empty() ) {
            s = -hp.top();
            hp.pop();
            tp.push_back(s);
            while( !g[s].empty() ) {
                e = g[s].back();
                inDeg[e]--;
                g[s].pop_back();
                if(inDeg[e] == 0)       hp.push(-e);
            }
        }
        for(int i = 1; i <= n; i++)
            if( !g[i].empty() ) {
                printf("No\n");
                chk = false;
                break;
            }
        if(chk) {
            printf("Yes ");
            for(int i = 0; i < tp.size(); i++)
                printf("%d ",tp[i]);
            printf("\n");
        }
    }
    return 0;
}
