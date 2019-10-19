#include<cstdio>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<int> v;
unordered_map<int,int> M;
int a[100002][5],m,n,num=0,chk[400002];
long long st[400002],lz[400002];
void upd(int s,int e,int nw,int l,int r,long long v){
    if(chk[nw]){
        st[nw]=(long long)(e-s+1)*lz[nw];
    }
    if(s!=e){
        lz[2*nw+1]=lz[nw];  chk[2*nw+1]=chk[nw];
        lz[2*nw+2]=lz[nw];  chk[2*nw+2]=chk[nw];
    }
    chk[nw]=0;
    if(s>e || s>r || e<l)       return ;
    if(l<=s && e<=r){
        st[nw]=(long long)(e-s+1)*v;
        if(s!=e){
            lz[2*nw+1]=v;   chk[2*nw+1]=1;
            lz[2*nw+2]=v;   chk[2*nw+2]=1;
        }
        return ;
    }
    int m=(s+e)/2;
    upd(s,m,2*nw+1,l,r,v);  upd(m+1,e,2*nw+2,l,r,v);
    st[nw]=st[2*nw+1]+st[2*nw+2];
}
long long g_sum(int s,int e,int nw,int l,int r){
    if(chk[nw]){
        st[nw]=(long long)(e-s+1)*lz[nw];
    }
    if(s!=e){
        lz[2*nw+1]=lz[nw];  chk[2*nw+1]=chk[nw];
        lz[2*nw+2]=lz[nw];  chk[2*nw+2]=chk[nw];
    }
    chk[nw]=0;
    if(s>e || s>r || e<l)   return 0;
    if(l<=s && e<=r)    return st[nw];
    int m=(s+e)/2;
    return g_sum(s,m,2*nw+1,l,r)+g_sum(m+1,e,2*nw+2,l,r);
}
int main(){
    scanf("%d %d",&m,&n);
    v.push_back(0);     v.push_back(n-1);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
        v.push_back(a[i][1]);   v.push_back(a[i][2]-1);
        if(!a[i][0])     scanf("%d",&a[i][3]);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        if(!M[v[i]])    M[v[i]]=++num;
    for(int i=0;i<n;i++){
        if(a[i][0])     printf("%lld\n",g_sum(0,num-1,0,M[a[i][1]]-1,M[a[i][2]]-1));
        else        upd(0,num-1,0,M[a[i][1]]-1,M[a[i][2]]-1,(long long)a[i][3]);
    }
    return 0;
}
