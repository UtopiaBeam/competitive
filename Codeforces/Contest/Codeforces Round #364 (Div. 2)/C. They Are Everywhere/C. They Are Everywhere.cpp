#include<cstdio>
#include<cstring>
#include<algorithm>
#define in f(a[i])
using namespace std;
int n,p=0,mn=1<<30,cnt=0,h[60];
char a[100002];
int f(char x){
    if('a'<=x && x<='z')    return x-'a';
    return x-'A'+30;
}
int main(){
    scanf("%d %s",&n,a);
    for(int i=0;i<n;i++){
        if(!h[in])      cnt++;
        h[in]++;
    }
    memset(h,0,sizeof(h));
    for(int i=0;i<n;i++){
        while(p<n && cnt){
            if(!h[f(a[p])])      cnt--;
            h[f(a[p])]++;
            p++;
        }
        if(!cnt)    mn=min(mn,p-i);
        h[in]--;
        if(!h[in])      cnt++;
    }
    printf("%d\n",mn);
    return 0;
}
