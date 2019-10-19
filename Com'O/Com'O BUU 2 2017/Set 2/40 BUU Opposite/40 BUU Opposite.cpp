#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 1<<30
using namespace std;
struct S {
    int xa, ya, xb, yb, cnt;
    S(int xa = 0, int ya = 0, int xb = 0, int yb = 0, int cnt = 0):
        xa(xa), ya(ya), xb(xb), yb(yb), cnt(cnt){}
};
queue<S> q;
int t, r, c;
int xa, ya, xb, yb, cnt, mn_d, mn_stp, nxa, nya, nxb, nyb;
int x, y, nx, ny;
int s[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int d[32][32][32][32], stp[32][32][32][32];
char a[32][32];
bool isOK(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < r) && (y < c) && (a[x][y] == '.');
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &r, &c);
        for(int i = 0; i < r; i++) {
            scanf(" %s", a[i]);
            for(int j = 0; j < c; j++) {
                if(a[i][j] == 'A')      xa = i, ya = j, a[i][j] = '.';
                if(a[i][j] == 'B')      xb = i, yb = j, a[i][j] = '.';
            }
        }
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                for(int k = 0; k < r; k++)
                    for(int l = 0; l < c; l++)
                        d[i][j][k][l] = stp[i][j][k][l] = INF;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                q.push( S(i, j) );
                while( !q.empty() ) {
                    x = q.front().xa;
                    y = q.front().ya;
                    cnt = q.front().cnt;
                    q.pop();
                    if(d[i][j][x][y] <= cnt)
                        continue;
                    d[i][j][x][y] = cnt;
                    for(int k = 0; k < 4; k++) {
                        nx = x + s[k][0];
                        ny = y + s[k][1];
                        if(isOK(nx, ny) && d[i][j][nx][ny] > cnt+1)
                            q.push( S(nx, ny, 0, 0, cnt+1) );
                    }
                }
            }
        }
        q.push( S(xa, ya, xb, yb, 0) );
        while( !q.empty() ) {
            xa = q.front().xa;
            ya = q.front().ya;
            xb = q.front().xb;
            yb = q.front().yb;
            cnt = q.front().cnt;
            q.pop();
            if( !isOK(xa, ya) || !isOK(xb, yb) || stp[xa][ya][xb][yb] <= cnt)
                continue;
            stp[xa][ya][xb][yb] = cnt;
            for(int i = 0; i < 4; i++) {
                nxa = xa + s[i][0];
                nya = ya + s[i][1];
                nxb = xb - s[i][0];
                nyb = yb - s[i][1];
                if( !isOK(nxa, nya) )   nxa = xa, nya = ya;
                if( !isOK(nxb, nyb) )   nxb = xb, nyb = yb;
                if(stp[nxa][nya][nxb][nyb] > cnt+1)
                    q.push( S(nxa, nya, nxb, nyb, cnt+1) );
            }
        }
        mn_d = mn_stp = INF;
        bool isCon = false;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                for(int k = 0; k < r; k++)
                    for(int l = 0; l < c; l++) {
                        if(stp[i][j][k][l] >= INF)    continue;
                        if(d[i][j][k][l] < mn_d) {
                            isCon = true;
                            mn_d = d[i][j][k][l];
                            mn_stp = stp[i][j][k][l];
                        } else if(d[i][j][k][l] == mn_d)
                            mn_stp = min(mn_stp, stp[i][j][k][l]);
                    }
        if(isCon)       printf("%d %d\n", mn_d, mn_stp);
        else            printf("-1 0\n");
    }
    return 0;
}
