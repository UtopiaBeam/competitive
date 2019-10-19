#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<int> v;
unordered_map<int,int> hs;
int n,l[100002],ft[100002];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",l+i);
        v.push_back(l[i]);
    }
    v.push_back(1);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        hs[v[i]]=i+1;
}
