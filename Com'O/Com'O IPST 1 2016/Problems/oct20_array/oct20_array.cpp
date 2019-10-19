#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
#define L long long
using namespace std;
unordered_map<int,int> hs;
vector<L> v;
bool chk[400002];
int n=0,q,op[100002],s[100002],e[100002];
L st[600002],lz[600002],val[100002];
void ud(int s,int e,int nw,int l,int r,L val){
    if(chk[nw]){
        st[nw]=(v[e]-v[s]+1)*lz[nw];
        if(s!=e){
            lz[nw<<1]=lz[nw];   chk[nw<<1]=true;
            lz[nw<<1|1]=lz[nw]; chk[nw<<1|1]=true;
        }
        chk[nw]=false;
    }
    if(l>e || r<s || s>e)   return ;
    if(l<=s && e<=r){
        st[nw]=(v[e]-v[s]+1)*val;
        if(s!=e){
            lz[nw<<1]=val;   chk[nw<<1]=true;
            lz[nw<<1|1]=val; chk[nw<<1|1]=true;
        }
        return ;
    }
    int m=(s+e)>>1;
    ud(s,m,nw<<1,l,r,val);
    ud(m+1,e,nw<<1|1,l,r,val);
    st[nw]=st[nw<<1]+st[nw<<1|1];
}
L qr(int s,int e,int nw,int l,int r){
    if(l>e || r<s || s>e)   return 0;
    if(chk[nw]){
        st[nw]=(v[e]-v[s]+1)*lz[nw];
        if(s!=e){
            lz[nw<<1]=lz[nw];   chk[nw<<1]=true;
            lz[nw<<1|1]=lz[nw]; chk[nw<<1|1]=true;
        }
        chk[nw]=false;
    }
    if(l<=s && e<=r)    return st[nw];
    int m=(s+e)>>1;
    return qr(s,m,nw<<1,l,r)+qr(m+1,e,nw<<1|1,l,r);
}
int main(){
    scanf("%d",&q);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d %d %d",op+i,s+i,e+i);
        if(op[i]==0)
            scanf("%lld",val+i);
        v.push_back(++s[i]);
        v.push_back(e[i]);
    }
    v.push_back(0);
    sort(v.begin(),v.end());
    v.resize(distance(v.begin(),unique(v.begin(),v.end())));
    for(int i=1;i<v.size();i++)
        printf("%d ",v[i]);
    printf("\n");
    for(int i=1;i<v.size();i++)
        hs[v[i]]=i;
    for(int i=0;i<q;i++){
        int l=hs[s[i]],r=hs[e[i]];
        printf("[%d, %d]\n",l,r);
        if(!op[i])   ud(1,n,1,l,r,val[i]);
        else    printf("%lld\n",qr(1,n,1,l,r));
    }
    return 0;
}
