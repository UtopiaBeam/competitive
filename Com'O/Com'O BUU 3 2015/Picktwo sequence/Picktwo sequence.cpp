#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int sum=0,n,t,mx=0;
vector<int> v;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(sum+t>0)     sum+=t;
        else{
            v.push_back(-mx);
            sum=0;      mx=0;
        }
        mx=max(mx,sum);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        printf("%d ",-v[i]);
    return 0;
}
