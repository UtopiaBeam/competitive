#include <cstdio>
#include <vector>
#define L long long
using namespace std;
vector<L> p, m, x;
int n;
L t, ans = 0;
char op;
bool chk = true;
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf(" %c %lld", &op, &t);
        if(op == '+')   p.push_back(t);
        if(op == '-')   m.push_back(t);
        if(op == 'x') {
            if(t == 0)      chk = false;
            else        x.push_back(t);
        }
    }
    for(int i = 0; i < p.size(); i++)
        ans += p[i];
    for(int i = 0; i < x.size(); i++)
        ans *= x[i];
    if(chk) {
        for(int i = 0; i < m.size(); i++)
            ans -= m[i];
    }
    printf("%lld\n", ans);
    return 0;
}
