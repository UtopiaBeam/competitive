#include <cstdio>
#include <queue>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
priority_queue<P> q;
int n, l ,r, x, y;
int a[1000002];
char ch;
int main() {
    scanf("%d %d %d", &n, &l, &r);
    for(int i = 1; i <= n; i++)
        q.push(P(0, i));
    for(int i = 0; i < l+r; i++) {
        scanf(" %c", &ch);
        if(ch == 'L') {
            scanf("%d %d", &x, &y);
            a[y]++;
            q.push(P(a[y], y));
        } else if(ch == 'C') {
            scanf("%d %d", &x, &y);
            a[y] += 3;
            q.push(P(a[y], y));
        } else if(ch == 'R') {
            while(a[ q.top().S ] < 0)
                q.pop();
            printf("%d\n", q.top().S);
        } else {
            while(a[ q.top().S ] < 0)
                q.pop();
            a[ q.top().S ] = -1;
            q.pop();
        }
    }
    return 0;
}
