#include <cstdio>
int n;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        if(i%4 < 2)     printf("a");
        else            printf("b");
    }
    return 0;
}
