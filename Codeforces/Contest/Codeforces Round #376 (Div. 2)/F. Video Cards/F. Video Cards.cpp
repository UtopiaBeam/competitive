#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int n,b[200002];
long long ans=0,t=0,a[200002],mn=1<<30;
int main(){
    b[2]=1;
    for(int i=3;i<=200000;i+=2)
        b[i]=1;
    for(int i=3;i*i<=200000;i+=2){
        if(b[i]){
            for(int j=i*i;j<=200000;j++)
                b[j]=0;
        }
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%I64d",a+i);
        mn=min(mn,a[i]);
        if(b[a[i]])     v.push_back(a[i]);
    }
    if(v.empty()){
        for(int i=0;i<n;i++)
            ans+=a[i]/mn*mn;
    }
    else{
        for(int i=0;i<v.size();i++){
            t=0;
            for(int j=0;j<n;j++)
                t+=a[j]/v[i]*v[i];
            ans=max(ans,t);
//            printf("%I64d: %I64d\n",v[i],t);
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
