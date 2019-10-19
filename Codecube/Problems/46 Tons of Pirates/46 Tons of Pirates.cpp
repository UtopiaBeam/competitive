#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
unordered_map<int,int> m;
vector<int> v;
int n,q,a[100002][3],ft[200002],cnt=0;
char ans[7][6]={"sleep","eat","work","eat","work","eat"};
void ud(int x,int v){
    for(;x<=cnt;x+=-x&x)  ft[x]+=v;
}
int get(int x){
    int sum=0;
    for(;x;x-=-x&x)     sum+=ft[x];
    return sum;
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=0;i<q;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
        v.push_back(a[i][1]);
        if(a[i][0]){
            scanf("%d",&a[i][2]);
            v.push_back(a[i][2]);
        }
    }
    sort(v.begin(),v.end());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
        m[*it]=++cnt;
    for(int i=0;i<q;i++)
        if(a[i][0])     ud(m[a[i][1]],1),ud(m[a[i][2]]+1,-1);
        else    printf("%s\n",ans[get(m[a[i][1]])%6]);
    return 0;
}
