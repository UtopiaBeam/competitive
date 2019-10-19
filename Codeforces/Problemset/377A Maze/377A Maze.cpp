#include <cstdio>
int r, c, k;
char a[502][502];
int s[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
bool chk[502][502];
void dfs(int x, int y) {
    if(chk[x][y])       return;
    chk[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int nx = x + s[i][0], ny = y + s[i][1];
        if(nx >= 0 && ny >= 0 && nx < r && ny < c && a[nx][ny] == '.' && !chk[nx][ny])
            dfs(nx, ny);
    }
    if(k > 0) {
        a[x][y] = 'X';
        k--;
    }
}
int main() {
    scanf("%d %d %d", &r, &c, &k);
    for(int i = 0; i < r; i++)
        scanf(" %s", a[i]);
    bool isAns = false;
    for(int i = 0; i < r && !isAns; i++)
        for(int j = 0; j < c && !isAns; j++)
            if(a[i][j] == '.') {
                dfs(i, j);
                isAns = true;
            }
    for(int i = 0; i < r; i++)
        printf("%s\n", a[i]);
    return 0;
}
