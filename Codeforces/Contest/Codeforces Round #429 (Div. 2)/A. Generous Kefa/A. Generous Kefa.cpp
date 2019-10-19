#include <cstdio>
int cnt[30];
int n, k;
char ch;
int main() {
    scanf("%d %d", &n, &k);
    while(n--) {
        scanf(" %c", &ch);
        cnt[ch - 'a']++;
    }
    for(int i = 0;i < 26; i++)
        if(cnt[i] > k) {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}
