#include <cstdio>
#include <queue>
using namespace std;
struct S {
    int x, y, d;
    S(int x = 0, int y = 0, int d = 0):
        x(x), y(y), d(d){}
};
queue<S> q;
int r, c, cnt = 0;
int a[1002][1002];
int x, y, d, nx, ny, s[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int main() {
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0)    q.push( S(i, j) );
        }
    while( !q.empty() ) {
        x = q.front().x;
        y = q.front().y;
        d = q.front().d;
        q.pop();
        if(a[x][y] < d)     continue;
        a[x][y] = -1;
        for(int i = 0; i < 4; i++) {
            nx = x + s[i][0];
            ny = y + s[i][1];
            if(nx >=0 && ny >= 0 && nx < r && ny < c && a[nx][ny] > d+1)
                q.push( S(nx, ny, d+1) );
        }
    }
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(a[i][j] > 0)     cnt++;
    printf("%d\n", cnt);
    return 0;
}
