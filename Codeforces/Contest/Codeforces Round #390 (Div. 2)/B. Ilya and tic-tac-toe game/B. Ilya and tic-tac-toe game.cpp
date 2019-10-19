#include <cstdio>
char a[5][5];
bool win = false;
bool chk(char x, char y, char z) {
    if(x == 'o' || y == 'o' || z == 'o')
        return false;
    int cnt = 0;
    if(x == 'x')    cnt++;
    if(y == 'x')    cnt++;
    if(z == 'x')    cnt++;
    return (cnt == 2);
}
int main() {
    for(int i = 0; i < 4; i++)
        scanf(" %s",a[i]);
    for(int i = 0; i < 4; i++)
        if(chk(a[i][0], a[i][1], a[i][2]) || chk(a[i][1], a[i][2], a[i][3]))
            win = true;
    for(int j = 0; j < 4; j++)
        if(chk(a[0][j], a[1][j], a[2][j]) || chk(a[1][j], a[2][j], a[3][j]))
            win = true;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            if(chk(a[i][j], a[i+1][j+1], a[i+2][j+2]) || chk(a[i+2][j], a[i+1][j+1], a[i][j+2]))
                win = true;
    if(win)     printf("YES\n");
    else        printf("NO\n");
    return 0;
}
