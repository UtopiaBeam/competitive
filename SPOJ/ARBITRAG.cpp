#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int l=1,n,m;
double dp[32][32],w;
string s,e;
map<string,int> M;
int main(){
    for(int t=1;;t++){
        cin >> n;
        if(n==0)    return 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i==j)    dp[i][j]=1.00;
                else        dp[i][j]=0.00;
        for(int i=1;i<=n;i++){
            cin >> s;
            M[s]=i;
        }
        cin >> m;
        while(m--){
            cin >> s >> w >> e;
            dp[M[s]][M[e]]=w;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dp[i][j]=max(dp[i][j],dp[i][k]*dp[k][j]);
        bool chk=false;
        for(int i=1;i<=n;i++)
            chk|=dp[i][i]>1.00;
        cout << "Case " << t << ": ";
        if(chk)     cout << "Yes\n";
        else        cout << "No\n";
    }
}
