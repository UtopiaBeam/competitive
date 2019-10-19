#include <cstdio>
#include <queue>
#include <algorithm>
#define INF 1<<30
using namespace std;
struct S {
    int x, y, d;
    S(int x = 0, int y = 0, int d = 0):
        x(x), y(y), d(d){}
};
queue<S> q;
char a[52][52];
int r, c, mn = INF, s[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int xs, ys, xe, ye, x, y, d, b[2502][52][52];
bool chk[52][52];
int main() {
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        scanf(" %s", &a[i][1]);
        for(int j = 1; j <= c; j++) {
            b[0][i][j] = INF;
            if(a[i][j] == '*')      b[0][i][j] = 0;
            if(a[i][j] == 'S')      xs = i, ys = j;
            if(a[i][j] == 'D')      xe = i, ye = j;
        }
    }
    for(int k = 1; k < r*c; k++) {
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                b[k][i][j] = b[k-1][i][j];
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                if(b[k][i][j] == k-1) {
                    for(int l = 0; l < 4; l++) {
                        int ni = i+s[l][0], nj = j+s[l][1];
                        if(a[ni][nj] != 'D' && a[ni][nj] != 'X')
                            b[k][ni][nj] = min(k, b[k][ni][nj]);
                    }
                }
    }
    q.push( S(xs, ys, 0) );
    while( !q.empty() ) {
        x = q.front().x;
        y = q.front().y;
        d = q.front().d;
        q.pop();
        if(chk[x][y] || b[d][x][y] <= d)
            continue;
        if(x == xe && y == ye) {
            mn = min(mn, d);
            break;
        }
        chk[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int nx = x+s[i][0], ny = y+s[i][1];
            if(nx > 0 && ny > 0 && nx <= r && ny <= c && a[nx][ny] != 'X' && b[d+1][nx][ny] > d+1 && !chk[nx][ny])
            q.push( S(nx, ny, d+1) );
        }
    }
    if(mn == INF)   printf("KAKTUS\n");
    else            printf("%d\n", mn);
    return 0;
}
