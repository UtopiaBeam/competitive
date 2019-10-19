#include<cstdio>
#include<vector>
using namespace std;
int q,n,a[10002];
vector<int> p,ans;
int main(){
    p.push_back(2);
    for(int i=3;i<=10000;i+=2)  a[i]=1;
    for(int i=3;i*i<=10000;i+=2)
        if(a[i])
            for(int j=i*i;j<=10000;j+=i)  a[j]=0;
    for(int i=3;i<=10000;i+=2)
        if(a[i])    p.push_back(i);
    for(int i=1;i<p.size();i++)     p[i]+=p[i-1];
    scanf("%d",&q);
    while(q--){
        ans.clear();
        scanf("%d",&n);
        for(int i=2;i<=p.size();i++)
            for(int j=0;j<p.size()-i;j++)
                if(p[j+i-1]-(j>0)*p[j-1]==n){
                    ans.push_back(i);   break;
                }
        printf("%d ",ans.size());
        for(int i=0;i<ans.size();i++)   printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
