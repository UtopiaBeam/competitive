#include <cstdio>
int k, w, l;
char a[202];
void f(int nw, int w, int l) {
    if(w >= k || l >= k) {
        for(int i = 0; i < nw; i++)
            printf("%c ",a[i]);
        printf("\n");
        return ;
    }
    a[nw] = 'W';
    f(nw+1, w+1, l);
    a[nw] = 'L';
    f(nw+1, w, l+1);
}
int main() {
    scanf("%d %d %d", &k, &w, &l);
    f(0, w, l);
    return 0;
}
