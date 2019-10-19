#include<iostream>
#include<algorithm>
using namespace std;
int n,k,cnt=0,ans=0,mn,mx;
string s[102],cd;
bool cmp(string x,string y){
    return x.size()<y.size();
}
int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> s[i];
    cin >> cd;
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++){
        ans++;
        if(s[i].size()==cd.size() && !mn)
            mn=ans;
        if(i==n-1 || s[i+1].size()>cd.size()){
            mx=ans;     break;
        }
        if(++cnt==k)  cnt=0,ans+=5;
    }
    cout << mn << " " << mx << "\n";
    return 0;
}
