#include <cstdio>
#include <queue>
#define INF 1<<30
using namespace std;
struct S {
    int type, val, die, trans;
    S(int type, int val, int die, int trans = INF):
        type(type), val(val), die(die), trans(trans){}
    bool operator <(const S &x) const {
        if(val != x.val)    return val > x.val;
        return type > x.type;
    }
};
priority_queue<S> hp;
int n, t, a, b, c;
int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&t);
        if(t == 1) {
            scanf("%d %d",&a,&b);
            hp.push(S(2, a, b));
        } else if(t == 2) {
            scanf("%d", &a);
            hp.push(S(3, a, INF));
        } else if(t == 3) {
            scanf("%d %d %d",&a,&b,&c);
            hp.push(S(1, a, b, c));
        } else {
            while(!hp.empty() && hp.top().die <= i) {
                if(hp.top().type == 1)      hp.push(S(3, hp.top().trans, INF));
                hp.pop();
            }
            if(hp.empty())      printf("GREAN\n");
            else {
                printf("%d\n", hp.top().val);
                hp.pop();
            }
        }
    }
    return 0;
}

