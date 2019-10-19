#include <cstdio>
#include <queue>
#include <algorithm>
#define INF 1<<30
using namespace std;
struct S {
    int x, y, t, type;
    S(int x = 0, int y = 0, int t = 0, int type = 0):
        x(x), y(y), t(t), type(type){}
    bool operator < (S p) const {
        return t > p.t;
    }
};
priority_queue<S> hp;
queue<S> q;
int Q;
int r, c, n, T;
int x, y, t, type, xp, yp, nx, ny;
int s[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
char a[702][702];
bool isOK(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < r) && (y < c);
}
void solve() {
    int cnt = 0;
    q.push( S(xp, yp, 0, 1) );
    a[xp][yp] = 'P';
    cnt++;
    while(!hp.empty() && hp.top().t == 0) {
        x = hp.top().x;
        y = hp.top().y;
        if(a[x][y] == 'P')      cnt--;
        a[x][y] = 'G';
        q.push( hp.top() );
        hp.pop();
    }
    if(cnt == 0) {
        printf("NO -1\n");
        return;
    }
    for(int i = 1; i <= T; i++) {
        while(!hp.empty() && hp.top().t == i) {
            x = hp.top().x;
            y = hp.top().y;
            if(a[x][y] == 'P')      cnt--;
            a[x][y] = 'G';
            q.push( hp.top() );
            hp.pop();
        }
        while( !q.empty() ) {
            x = q.front().x;
            y = q.front().y;
            t = q.front().t;
            type = q.front().type;
            if(t >= i)      break;
            q.pop();
            for(int k = 0; k < 4; k++) {
                nx = x + s[k][0];
                ny = y + s[k][1];
                if( !isOK(nx, ny) )     continue;
                if(type == 1 && a[nx][ny] == '.') {
                    a[nx][ny] = 'P';
                    cnt++;
                    q.push( S(nx, ny, t+1, type) );
                } else if(type == 0 && a[nx][ny] != '#' && a[nx][ny] != 'G') {
                    if(a[nx][ny] == 'P')    cnt--;
                    a[nx][ny] = 'G';
                    q.push( S(nx, ny, t+1, type) );
                }
            }
        }
        if(cnt == 0) {
            printf("NO %d\n", i-1);
            return;
        }
    }
    printf("YES\n");
}
int main() {
    scanf("%d", &Q);
    while(Q--) {
        while( !hp.empty() )    hp.pop();
        while( !q.empty() )     q.pop();
        scanf("%d %d %d %d %d %d", &r, &c, &n, &T, &xp, &yp);
        for(int i = 0; i < n; i++) {
            scanf("%d %d %d", &t, &x, &y);
            hp.push( S(x, y, t) );
        }
        for(int i = 0; i < r; i++)
            scanf(" %s", a[i]);
        solve();
    }
    return 0;
}
