#include <cstdio>
#include <queue>
using namespace std;
struct S {
    int x, y, d;
    S(int x = 0, int y = 0, int d = 0):
        x(x), y(y), d(d){}
}nw;
queue<S> q;
int cnt[250002], s[2][2] = { {1, 0}, {0, 1} };
int r, c;
int a[502][502];
int ans = 0;
int main() {
    q.push(S());
    scanf("%d %d", &r, &c);
    for(int i = r-1; i >= 0; i--)
        for(int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    while(!q.empty()) {
        nw = q.front();
        q.pop();
        if(nw.x < 0 || nw.y < 0 || nw.x >= r || nw.y >= c || a[nw.x][nw.y] != 0)
            continue;
        a[nw.x][nw.y] = -1;
        cnt[nw.d]++;
        for(int i = 0; i < 2; i++) {
            int nx = nw.x + s[i][0], ny = nw.y + s[i][1];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c || a[nx][ny] != 0)
                continue;
            q.push( S(nx, ny, nw.d+1) );
        }
    }
    for(int i = 0; i < r*c; i++)
        ans += cnt[i]*cnt[i];
    printf("%d\n", ans);
    return 0;
}
