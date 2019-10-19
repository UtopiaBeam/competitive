#include <cstdio>
#include <map>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
map<P, int> mp;
int r, c, n, x, y, xt, yt, nw, nx, ny;
int cnt = 0;
int s[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
char str[5]="NESW", ch;
int main() {
    scanf("%d %d", &c, &r);
    scanf("%d %d", &x, &y);
    scanf(" %c", &ch);
    for(nw = 0; nw < 4; nw++)
        if(str[nw] == ch)       break;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &xt, &yt);
        mp[ P(xt, yt) ]++;
    }
    scanf("%d", &n);
    while(n--) {
        scanf(" %c", &ch);
        if(ch == 'F') {
            nx = x + s[nw][0], ny = y + s[nw][1];
            if(nx < 1 || ny < 1 || nx > c || ny > r) {
                continue;
            }
            x += s[nw][0];
            y += s[nw][1];
        }
        if(ch == 'B') {
            nx = x - s[nw][0], ny = y - s[nw][1];
            if(nx < 1 || ny < 1 || nx > c || ny > r) {
                continue;
            }
            x -= s[nw][0];
            y -= s[nw][1];
        }
        if(ch == 'L') {
            nw = (nw + 3) % 4;
        }
        if(ch == 'R') {
            nw = (nw + 1) % 4;
        }
        if(mp[ P(x, y) ]) {
            cnt++;
            mp[ P(x, y) ]--;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
