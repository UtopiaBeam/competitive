#include <cstdio>
int n, p;
char s[1002];
int main() {
    scanf("%d %d %s", &n, &p, s);
    int nw = n-1;
    s[nw]++;
    while(nw >= 0 && nw < n) {
        if(s[nw] == 'a'+p)      s[nw] = 'a', s[--nw]++;
        else if(nw > 0 && s[nw] == s[nw-1] || nw > 1 && s[nw] == s[nw-2])
            s[nw]++;
        else        nw++;
    }
    if(nw < 0)      printf("NO\n");
    else            printf("%s\n", s);
    return 0;
}
