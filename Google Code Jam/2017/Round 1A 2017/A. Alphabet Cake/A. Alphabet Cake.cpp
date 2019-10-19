#include <cstdio>
int q;
int r, c;
char a[30][30];
void fileIO() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
}
void solve(int t) {
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++)
        scanf(" %s", a[i]);
    for(int i = 1; i < r; i++)
        for(int j = 0; j < c; j++)
            if(a[i][j] == '?')
                a[i][j] = a[i-1][j];
    for(int i = r-2; i >= 0; i--)
        for(int j = 0; j < c; j++)
            if(a[i][j] == '?')
                a[i][j] = a[i+1][j];
    for(int i = 0; i < r; i++)
        for(int j = 1; j < c; j++)
            if(a[i][j] == '?')
                a[i][j] = a[i][j-1];
    for(int i = 0; i < r; i++)
        for(int j = c-2; j >= 0; j--)
            if(a[i][j] == '?')
                a[i][j] = a[i][j+1];
    printf("Case #%d:\n", t);
    for(int i = 0; i < r; i++)
        printf("%s\n", a[i]);
}
int main() {
    fileIO();
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
        solve(i);
    return 0;
}
