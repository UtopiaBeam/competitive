#include <cstdio>
int n;
int main() {
    scanf("%d", &n);
    for(int i = 0; i <= n/4; i++) {
        if( (n-4*i) % 7 == 0 ) {
            for(int j = 0; j < i; j++)
                printf("4");
            for(int j = 0; j < (n-4*i) /7; j++)
                printf("7");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
