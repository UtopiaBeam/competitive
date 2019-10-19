#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define P pair<string,int>
#define F first
#define S second
using namespace std;
int n,k,v,ans=0;
string s;
map<string,vector<int> > m;
bool chk(string x){
    string y = x;
    reverse(y.begin(),y.end());
    return x == y;
}
string rev(string x){
    reverse(x.begin(),x.end());
    return x;
}
int main(){
    cin >> n >> k;
    while(n--){
        cin >> s >> v;
        m[s].push_back(v);
    }
    cout << ans << '\n';
    return 0;
}
