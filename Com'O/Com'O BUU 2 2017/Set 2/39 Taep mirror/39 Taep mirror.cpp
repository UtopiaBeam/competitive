#include <cstdio>
#include <queue>
#define INF 1<<30
using namespace std;
struct S {
    int x, y, cnt, dir;
    S(int x = 0, int y = 0, int cnt = 0, int dir = -1):
        x(x), y(y), cnt(cnt), dir(dir){}
};
queue<S> q;
int r, c, xs = -1, ys = -1, xe, ye;
int px, py, x, y, nx, ny, cnt, dir, d, chk[102][102];
int s[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
char a[102][102];
int main() {
    scanf("%d %d", &c, &r);
    for(int i = 0; i < r; i++) {
        scanf(" %s", a[i]);
        for(int j = 0; j < c; j++) {
            if(a[i][j] == 'M') {
                if(xs < 0) {
                    xs = i;     ys = j;
                } else {
                    xe = i;     ye = j;
                }
                a[i][j] = '.';
            }
            chk[i][j] = INF;
        }
    }
    q.push( S(xs, ys) );
    while( !q.empty() ) {
        x = q.front().x;
        y = q.front().y;
        cnt = q.front().cnt;
        dir = q.front().dir;
        q.pop();
        if(chk[x][y] < cnt || a[x][y] != '.')
            continue;
        chk[x][y] = cnt;
        for(int i = 0; i < 4; i++) {
            nx = x + s[i][0];
            ny = y + s[i][1];
            if(i == dir || dir == -1)   d = 0;
            else        d = 1;
            if(nx >= 0 && ny >= 0 && nx < r && ny < c && a[nx][ny] == '.' && chk[nx][ny] >= cnt+d)
                q.push( S(nx, ny, cnt+d, i) );
        }
    }
    printf("%d\n", chk[xe][ye]);
    return 0;
}
