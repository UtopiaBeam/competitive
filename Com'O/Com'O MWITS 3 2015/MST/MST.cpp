#include<cstdio>
#include<vector>
#include<algorithm>
#define L long long
#define MOD (L)(1e9+7)
using namespace std;
struct S{
    int s,e;
    L w;
    S(int s=0,int e=0,L w=0):
        s(s),e(e),w(w){}
    bool operator<(const S &a)const{
        return w < a.w;
    }

}ed[100002];
int n,m,r[40002];
vector<S> v;
L cnt=1,ans=0;
int find(int x){
    if(x!=r[x])     r[x]=find(r[x]);
    return r[x];
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        r[i]=i;
    for(int i=0;i<m;i++)
        scanf("%d %d %lld",&ed[i].s,&ed[i].e,&ed[i].w);
    sort(ed,ed+m);
    for(int i=0;i<m;){
        L w=ed[i].w;
        int t=1;
        while(i<m && ed[i].w==w){
            int rs=find(ed[i].s),re=find(ed[i].e);
            if(rs!=re)      v.push_back(ed[i]);
            i++;
        }
        int rs[3]={},re[3]={};
        for(int j=0;j<v.size();j++){
            rs[j]=find(v[j].s),re[j]=find(v[j].e);
            if(rs[j]>re[j])     swap(rs[j],re[j]);
        }
        if(v.size()==2)
            if(rs[0]==rs[1] && re[0]==re[1])
                cnt*=2;
        if(v.size()==3){
            for(int j=0;j<3;j++)
                for(int k=0;k<2;k++)
                    if(rs[k]>rs[k+1] || rs[k]==rs[k+1] && re[k]>re[k+1])
                        swap(rs[k],rs[k+1]),swap(re[k],re[k+1]);
            if(rs[0]==rs[1] && re[0]==re[1] &&
               rs[1]==rs[2] && re[1]==re[2])
                cnt*=3;
            else if(rs[0]==rs[1] && re[0]==rs[2] &&
                    re[1]==re[2])
                cnt*=3;
            else if(rs[0]==rs[1] && re[0]==re[1] ||
                    rs[1]==rs[2] && re[1]==re[2])
                cnt*=2;
        }
        for(int j=0;j<v.size();j++){
            if(find(rs[j])!=find(re[j])){
                ans+=w;
                r[find(re[j])]=find(rs[j]);
            }
        }
        v.clear();
        cnt%=MOD;
    }
    printf("%lld %lld\n",ans,cnt);
    return 0;
}
