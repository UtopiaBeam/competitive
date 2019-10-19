#include<iostream>
#include<cstring>
#include<map>
using namespace std;
string s;
map<string,int> m;
int ft[30002],n,q,a[30002];
void ud(int x){
    for(;x<=n;x+=-x&x)  ft[x]++;
}
int gs(int x){
    int s=0;
    for(;x;x-=-x&x)     s+=ft[x];
    return s;
}
int main(){
    cin >> q;
    while(q--){
        memset(ft,0,sizeof(ft));
        int ans=0;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> s;
            m[s]=i;
        }
        for(int i=1;i<=n;i++){
            cin >> s;
            a[i]=m[s];
        }
        for(int i=n;i>0;i--){
            ans+=gs(a[i]);
            ud(a[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
