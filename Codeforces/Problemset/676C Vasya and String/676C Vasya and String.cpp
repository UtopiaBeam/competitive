#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,s,e,cnt,mx=0;
char a[100002];
int main(){
    scanf("%d %d %s",&n,&k,a);
    s=0,cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]=='b'){
            cnt++;
            while(cnt>k){
                if(a[s++]=='b')   cnt--;
            }
        }
        mx=max(mx,i-s+1);
    }
    s=0,cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]=='a'){
            cnt++;
            while(cnt>k){
                if(a[s++]=='a')   cnt--;
            }
        }
        mx=max(mx,i-s+1);
    }
    printf("%d\n",mx);
    return 0;
}
