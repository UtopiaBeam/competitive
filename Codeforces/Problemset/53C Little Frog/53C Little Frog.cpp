#include <cstdio>
int n;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= (n+1)/2; i++) {
        printf("%d ", i);
        if(i != n+1-i)      printf("%d ", n+1-i);
    }
    return 0;
}
