#include<cstdio>
using namespace std;
int n,cnt=0,ans=1;
char a[25];
int main(){
    scanf("%d %s",&n,a);
    for(int i=0;a[i];i++)
        cnt++;
    while(n>0){
        ans*=n;
        n-=cnt;
    }
    printf("%d\n",ans);
    return 0;
}
