#include <cstdio>
char a[102];
int main() {
    scanf(" %s", a);
    for(int i = 0; a[i]; i++)
        for(int j = i; a[j]; j++)
            for(int k = j; a[k]; k++) {
                int tmp = a[i]-'0';
                if(i != j)      tmp = 10*tmp + (a[j]-'0');
                if(j != k)      tmp = 10*tmp + (a[k]-'0');
                if( tmp % 8 == 0 ) {
                    printf("YES\n");
                    printf("%d\n", tmp);
                    return 0;
                }
            }
    printf("NO\n");
    return 0;
}
