#include <cstdio>
#define L long long
int l = 0;
L sum = 0, hs[30];
char s[100002];
int main() {
    for(int i = 0; i < 26; i++)
        scanf("%I64d", hs+i);
    scanf(" %s", s);
    for(int i = 0; s[i]; i++) {
        while()
        sum += hs[ s[i]-'a' ];
    }
}
