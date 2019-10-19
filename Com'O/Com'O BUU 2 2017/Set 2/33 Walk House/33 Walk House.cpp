#include <cstdio>
#include <queue>
using namespace std;
struct S {
    int x, y, d;
    S(int x = 0, int y = 0, int d = 0):
        x(x), y(y), d(d){}
};
queue<S> q;
int r, c;
int xs, ys, xe, ye, x, y, d, nx, ny;
int chk[1002][1002], s[8][2] = { {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1} };
char a[1002][1002];
int main() {
    scanf("%d %d", &r ,&c);
    for(int i = 1; i <= r; i++)
        scanf(" %s", &a[i][1]);
    scanf("%d %d", &xs, &ys);
    scanf("%d %d", &xe, &ye);
    q.push( S(xs, ys) );
    while( !q.empty() ) {
        x = q.front().x;
        y = q.front().y;
        d = q.front().d;
        q.pop();
        if(x < 1 || y < 1 || x > r || y > c || a[x][y] == 'X' || chk[x][y])
            continue;
        chk[x][y] = 1;
        if(x == xe && y == ye) {
            printf("%d\n", d);
            return 0;
        }
        for(int i = 0; i < 8; i++) {
            nx = x + s[i][0];
            ny = y + s[i][1];
            if(nx < 1 || ny < 1 || nx > r || ny > c || a[nx][ny] == 'X' || chk[nx][ny])
                continue;
            q.push( S(nx, ny, d+1) );
        }
    }
    printf("-1\n");
    return 0;
}
