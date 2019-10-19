#include<cstdio>
#include<algorithm>
using namespace std;
char a[102],nw='a';
int cnt=0;
int main(){
    scanf(" %s",a);
    for(int i=0;a[i];i++){
        cnt+=min((a[i]-nw+26)%26,(nw-a[i]+26)%26);
        nw=a[i];
    }
    printf("%d\n",cnt);
    return 0;
}
