//O(n) sorting
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
vector<pair<int,int> > a;
vector<int> S,E;
int cs[1000005],ce[1000005];
int n,s,e,cnt=0,Max=-10;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&s,&e);
        cs[s]++,ce[e]++;
    }
    for(int i=0;i<=1000000;i++){
        if(cs[i])
            while(cs[i]--)  S.push_back(i);
        if(ce[i])
            while(ce[i]--)  E.push_back(i);
    }
    for(int i=0,j=0;i<S.size() && j<E.size();){
        if(i==S.size())         a.push_back(make_pair(E[j++],-1));
        else if(j==E.size())    a.push_back(make_pair(S[i++],1));
        else if(S[i]<E[j])      a.push_back(make_pair(S[i++],1));
        else                    a.push_back(make_pair(E[j++],-1));
    }
    for(int i=0;i<a.size();i++){
        cnt+=a[i].second;
        Max=(Max>=cnt)*Max+(Max<cnt)*cnt;
    }
    printf("%d\n",Max);
    return 0;
}
