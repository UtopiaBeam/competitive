#include <cstdio>
#include <cstring>
#define N 200
#define L long long

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
char wz[N+2][N+2][8];
int turned[N+2][N+2][4][8];
L spent[N+2][N+2][4][8];

int n, m;
int x, y;
L k;

int main() {
    memset(wz, 'S', sizeof(wz));
    scanf("%d %lld", &n, &k);
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &x, &y);
        scanf(" %s", wz[x][y]);
    }

    int dir = 0;
    L day = 0, cnt = 0;
    for (x = 1, y = 1;; day++) {
        if (wz[x][y][day % 7] == 'L') {
            dir = (dir + 3) % 4;
            cnt++;
        }
        if (wz[x][y][day % 7] == 'R') {
            dir = (dir + 1) % 4;
            cnt++;
        }
        if (x+dx[dir] < 1 || x+dx[dir] > n || y+dy[dir] < 1 || y+dy[dir] > n) {
            dir = (dir + 2) % 4;
            cnt++;
        }
        if (spent[x][y][dir][day % 7] > 0) {
            L cycle = cnt - turned[x][y][dir][day % 7];
            L left = k - cnt;
            day += (left / cycle) * (day - spent[x][y][dir][day % 7]);
            cnt += (left / cycle) * cycle;
        }

        spent[x][y][dir][day % 7] = day;
        turned[x][y][dir][day % 7] = cnt;
        if (cnt >= k)       break;
        x += dx[dir];       y += dy[dir];
    }
    printf("%lld\n", day);
    return 0;
}