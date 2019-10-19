#include <cstdio>
int n;
int a[20];
void f(int nw) {
    if(nw > n)      return;
    if(nw == n) {
        for(int i = 0; i < n; i++) {
            if(a[i] == 0)   printf("--\n");
            else {
                printf("||\n");
                i++;
            }
        }
        printf("E\n");
        return;
    }
    a[nw] = 0;          f(nw+1);
    a[nw] = 1;          f(nw+2);
}
int main() {
    scanf("%d", &n);
    f(0);
    return 0;
}
