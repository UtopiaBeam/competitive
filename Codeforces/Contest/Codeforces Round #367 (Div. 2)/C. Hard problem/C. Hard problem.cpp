#include<iostream>
#include<algorithm>
using namespace std;
string s[100002],r[100002];
int n;
long long a[100002],dp[100002][2];
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++){
        cin >> s[i];
        r[i]=s[i];
        reverse(r[i].begin(),r[i].end());
    }
    dp[0][1]=a[0];
    for(int i=1;i<n;i++){
        int chk=1;
        dp[i][0]=dp[i][1]=1e18;
        if(s[i]>=s[i-1])    dp[i][0]=min(dp[i][0],dp[i-1][0]);
        if(s[i]>=r[i-1])    dp[i][0]=min(dp[i][0],dp[i-1][1]);
        if(r[i]>=s[i-1])    dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
        if(r[i]>=r[i-1])    dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
    }
    if(min(dp[n-1][0],dp[n-1][1])>=1e18)
        cout << "-1\n";
    else    cout << min(dp[n-1][0],dp[n-1][1]) << "\n";
    return 0;
}
