#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#define S second
using namespace std;
int n,k;
string a;
bool chk(int m){
    int mx=0;
    map<string,int> M;
    for(int i=0;i+m<=n;i++){
        M[a.substr(i,m)]++;
    }
    for(map<string,int>::iterator it=M.begin();it!=M.end();it++)
        mx=max(mx,it->S);
    return mx>=k;
}
int bs(int s,int e){
    if(s==e)    return s;
    int m=(s+e+1)/2;
    if(chk(m))      return bs(m,e);
    return bs(s,m-1);
}
int main(){
    cin >> n >> k >> a;
    cout << bs(0,n);
    return 0;
}
