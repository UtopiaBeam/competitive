#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
struct S {
    int hd, ad, hk, ak;
    int cnt;
    S() {}
    S(int hd, int ad, int hk, int ak, int cnt) :
        hd(hd), ad(ad), hk(hk), ak(ak), cnt(cnt) {}
}nw;
struct M {
    int hd, ad, hk, ak;
    M() {}
    M(int hd, int ad, int hk, int ak) :
        hd(hd), ad(ad), hk(hk), ak(ak) {}
    bool operator < (M x) const {}
};
queue<S> q;
map<M, int> mp;
int Q;
int hd, ad, hk, ak, b, d;
void solve(int t) {
    scanf("%d %d %d %d %d %d", &hd, &ad, &hk, &ak, &b, &d);
    printf("Case #%d: ", t);
    q.push( S(hd, ad, hk, ak, 1) );
    while( !q.empty() ) {
        nw = q.front();
        q.pop();
        if(nw.hd == 0)      continue;
        M tmp = M(nw.hd, nw.ad, nw.hk, nw.ak);
        if(mp[tmp] != 0 && mp[tmp] <= nw.cnt)
            continue;
        if(nw.hk == 0) {
            printf("%d\n", nw.cnt);
            return;
        }
        mp[tmp] = nw.cnt;
        if( !(nw.cnt&1) ) {      //Knight's turn
            q.push( S(max(nw.hd-nw.ak, 0), nw.ad, nw.hk, nw.ak, nw.cnt+1) );    //Attack
            q.push( S(nw.hd, nw.ad, nw.hk, nw.ak+b, nw.cnt+1) );                //Buff
            q.push( S(nw.hd, nw.ad, hk, nw.ak, nw.cnt+1) );                     //Cure
            q.push( S(nw.hd, max(nw.ad-d, 0), nw.hk, nw.ak, nw.cnt+1) );        //Debuff
        } else {                //Dragon's turn
            q.push( S(nw.hd, nw.ad, max(nw.hk-nw.ad, 0), nw.ak, nw.cnt+1) );    //Attack
            q.push( S(nw.hd, nw.ad+b, nw.hk, nw.ak, nw.cnt+1) );                //Buff
            q.push( S(hd, nw.ad, nw.hk, nw.ak, nw.cnt+1) );                     //Cure
            q.push( S(nw.hd, nw.ad, nw.hk, max(nw.ak-d, 0), nw.cnt+1) );        //Debuff
        }
    }
    printf("IMPOSSIBLE\n");
}
int main() {
    scanf("%d", &Q);
    for(int i = 1; i <= Q; i++)
        solve(i);
    return 0;
}
