#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector <pair<int,int> > a;
int x,y,n,m,cnt=0,cnt_now=0;
int main(){
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d %d",&x,&y);
        a.push_back(make_pair(x,1)),a.push_back(make_pair(y,-1));
    }
    while(m--){
        scanf("%d",&x);
        a.push_back(make_pair(x,0));
    }
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        cnt_now+=a[i].second;
        if(!a[i].second)    cnt+=cnt_now,cnt%=2007;
    }
    printf("%d\n",cnt);
    return 0;
}
