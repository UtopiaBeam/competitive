#include <cstdio>
int cnt = 0, len = 0, ans = 0;
int k;
char s[15];
int main() {
    scanf(" %s %d",s,&k);
    for(int i = 0; s[i]; i++, len++)
        if(s[i] == '0')
            cnt++;
    if(cnt < k)     printf("%d\n", len-1);
    else {
        cnt = 0;
        for(int i = len-1; i > 0 && cnt < k; i--)
            if(s[i] == '0')     cnt++;
            else    ans++;
        printf("%d\n",ans);
    }
    return 0;
}
