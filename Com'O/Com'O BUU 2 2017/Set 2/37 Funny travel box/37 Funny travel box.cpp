#include <cstdio>
int r, c, s[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
char a[32][32];
bool ans = false;
bool isOK(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < r-1) && (y < c-1)
        &&  (a[x][y] == '.') && (a[x+1][y] != '#') && (a[x][y+1] != '#') && (a[x+1][y+1] != '#');
}
void dfs(int x, int y) {
    if(ans || a[x][y] == 'x' || !isOK(x, y) )       return;
    if(x == r-2) {
        ans = true;
        return;
    }
    a[x][y] = 'x';
    for(int i = 0; i < 4; i++) {
        int nx = x + s[i][0], ny = y + s[i][1];
        if( isOK(nx, ny) )      dfs(nx, ny);
    }
    a[x][y] = '.';
}
int main() {
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++)
        scanf(" %s", a[i]);
    for(int j = 0; j < c-1; j++) {
        if( isOK(0, j) ) {
            dfs(0, j);
            if(ans) {
                printf("yes\n");
                return 0;
            }
        }
    }
    printf("no\n");
    return 0;
}
