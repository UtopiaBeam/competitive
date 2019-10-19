#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int n;
string a[100002],b[100002];
map<string,int> m;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        for(int j=0;j<a[i].size();j++)
            if(a[i][j]=='*')    a[i][j]='M';
        b[i]=a[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++)    m[b[i]]=i+1;
    for(int i=0;i<n;i++)    cout << m[a[i]] << "\n";
    return 0;
}
