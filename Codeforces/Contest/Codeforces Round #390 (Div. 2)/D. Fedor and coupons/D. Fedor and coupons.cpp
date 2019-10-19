#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define P pair<int, int>
#define F first
#define S second
#define N 300000
using namespace std;
struct St {
    int val;
    int mark;
    int id;
    St(int val, int mark, int id):
        val(val), mark(mark), id(id){}
};
int n,k;
int l,r;
bool chk = false;
P a[N+2];
set<int> s;
set<int>::iterator sit;
map<set<int>, int> mp;
map<set<int>, int>::iterator it;
vector<St> v;
vector<int> ans;
bool cmp(St x, St y) {
    if(x.val != y.val)      return x.val < y.val;
    return x.mark > y.mark;
}
long long d(int l, int r) {
    return (long long)r-l+1;
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d",&l,&r);
        a[i]=P(l, r);
        v.push_back(St(l, 1, i));
        v.push_back(St(r, -1, i));
    }
    sort(v.begin(), v.end(), cmp);
    l = 1<<30;
    r = -1<<30;
    for(int i = 0; i < v.size()-1; i++) {
        if(v[i].mark == 1)      s.insert(v[i].id);
        else        s.erase(s.find(v[i].id));
        mp[s] += d(v[i].val, v[i+1].val);
        chk = chk || (s.size() >= k);
    }
    if(!chk) {
        printf("0\n");
        for(int i = 1; i <= k; i++)
            printf("%d ",i);
        return 0;
    }
    int mx = 0;
    for(it = mp.begin(); it != mp.end(); it++) {
        if(mx < it->S && (it->F).size() >= k) {
            mx = it->S;
            s = it->F;
        }
    }
    printf("%d\n",mx);
    int cnt = 0;
    for(sit = s.begin(); sit != s.end() && cnt < k; sit++, cnt++)
        printf("%d ",(*sit)+1);
    return 0;
}
