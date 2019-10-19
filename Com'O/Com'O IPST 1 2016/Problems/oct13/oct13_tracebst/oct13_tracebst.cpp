#include<iostream>
#include<algorithm>
#define P pair<string,int>
#define F first
#define S second
using namespace std;
int n,ans[100002];
P a[100002];
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].F;
        (a[i].F).back()='M';
        a[i].S=i;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
        ans[a[i].S]=i+1;
    for(int i=0;i<n;i++)
        cout << ans[i] << "\n";
    return 0;
}
