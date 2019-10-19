#include <cstdio>
#include <queue>
#define L long long
#define PLI pair<L, int>
#define PII pair<int, int>
#define F first
#define S second
using namespace std;
priority_queue<PLI> hp;
priority_queue<PII> q;
PLI nw;
int hf[100002];
int k, t;
char op, type;
L x, ans = 0, mp[100002];
int main() {
    scanf("%d", &k);
    for(int i = 1; i <= k; i++) {
        while(!q.empty() && -q.top().F <= i) {
            t = q.top().S;
            q.pop();
            if(hf[t] == 0)      continue;
            mp[t] /= 2;
            if(mp[t] == 0)      continue;
            hp.push( PLI(mp[t], -t) );
            q.push( PII(-i-hf[t], t) );
        }
        while( !hp.empty() ) {
            if( mp[-hp.top().S] != hp.top().F )
                hp.pop();
            else        break;
        }
        scanf(" %c", &op);
        if(op == 'c') {
            scanf(" %c", &type);
            if(type == 'n') {
                scanf("%lld", &x);
                mp[i] = x;
                hp.push( PLI(x, -i) );
            } else {
                scanf("%lld %d", &x, &t);
                mp[i] = x;      hf[i] = t;
                hp.push( PLI(x, -i) );
                q.push( PII(-t-i, i) );
            }
        } else {
            while( !hp.empty() ) {
                x = hp.top().F;
                t = -hp.top().S;
                hp.pop();
                if(mp[t] == x) {
                    ans += mp[t];
                    hf[t] = 0;
                    break;
                }
            }
        }
    }
    int cnt = 0;
    while( !hp.empty() ) {
        if(mp[-hp.top().S] == hp.top().F)
            cnt++;
        hp.pop();
    }
    printf("%lld\n%d\n", ans, cnt);
    return 0;
}
