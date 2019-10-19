#include <cstdio>
#define N 100
int n;
int cnt = 0;
int a[N+2];
int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",a+i);
        if(a[i] != 0)   cnt++;
    }
    if(cnt == 0) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n%d\n",cnt);
    int nw = 0;
    while(a[nw] == 0)
        nw++;
    for(int i = nw; i < n; i++) {
        if(nw != 0 && i == nw) {
            printf("1 ");
        }
        else    printf("%d ",i+1);
        while(i < n-1 && a[i+1] == 0)
            i++;
        printf("%d\n",i+1);
    }
    return 0;
}
