#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> a,b,c,d;
int n,t,ans=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&t);
            if(i%2){
                if(j%2)     d.push_back(t);
                else        c.push_back(t);
            }
            else{
                if(j%2)     b.push_back(t);
                else        a.push_back(t);
            }
        }
    sort(a.begin(),a.end());    sort(b.begin(),b.end());
    sort(c.begin(),c.end());    sort(d.begin(),d.end());
    for(int i=0;i<a.size();i++)
        ans+=a[i]*b[i]*c[i]*d[i];
    printf("%d\n",ans);
    return 0;
}
