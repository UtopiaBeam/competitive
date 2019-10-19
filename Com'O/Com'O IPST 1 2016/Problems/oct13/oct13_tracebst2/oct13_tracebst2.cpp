#include<iostream>
#include<algorithm>
#define P pair<string,pair<int,int>>
#define F first
#define S second
using namespace std;
int n;
P a[100002];
bool cmp(P x,P y){
    return x.S.F < y.S.F;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].F;
        a[i].S.F=i;
        for(int j=0;j<a[i].F.size();j++)
            if((a[i].F)[j]=='*')    (a[i].F)[j]='M';
    }
    sort(a,a+n);
    for(int i=0,cnt=1;i<n;i++){
        if(i>0 && a[i].F==a[i-1].F)     cnt--;
        a[i].S.S=cnt++;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)    cout << a[i].S.S << "\n";
    return 0;
}
