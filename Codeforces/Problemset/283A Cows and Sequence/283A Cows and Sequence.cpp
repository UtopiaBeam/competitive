#include <cstdio>
#include <vector>
#include <algorithm>
#define D double
using namespace std;
vector <D> v;
int q, op, k;
int n = 1;
D x, sum = 0, ls;
int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d %lf", &k, &x);
            if(k >= n)      ls += x;
            else        v[k-1] -= x;
            sum += x * min(k, n);
        }
        if(op == 2) {
            scanf("%lf", &x);
            v.push_back(x - ls);
            ls = x;
            sum += x;
            n++;
        }
        if(op == 3 && n > 1) {
            sum -= ls;
            ls -= v.back();
            v.pop_back();
            n--;
        }
        printf("%lf\n", sum/n);
    }
    return 0;
}
