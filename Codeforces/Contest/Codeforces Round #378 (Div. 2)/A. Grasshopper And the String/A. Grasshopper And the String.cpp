#include<cstdio>
#include<algorithm>
using namespace std;
char s[102];
int idx=-1,mx=0,l=0;
int main(){
    scanf(" %s",s);
    for(int i=0;s[i];i++,l++)
        if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            mx=max(mx,i-idx),idx=i;
    printf("%d\n",max(mx,l-idx));
    return 0;
}
