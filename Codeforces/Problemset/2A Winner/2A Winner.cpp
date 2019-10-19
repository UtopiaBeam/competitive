#include<iostream>
#include<map>
#include<vector>
#define F first
#define S second
using namespace std;
map<string,int> m,c;
string a[1005];
int n,b[1005],mx=-1<<20;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        m[a[i]]+=b[i];
    }
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
        if((*it).S>mx)  mx=(*it).S;
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
        if((*it).S==mx)  c[(*it).F]=1;
    for(int i=0;i<n;i++){
        m[a[i]]-=b[i];
        if(m[a[i]]<=0 && c[a[i]]==1){
            cout << a[i] << endl;
            return 0;
        }
    }
}
