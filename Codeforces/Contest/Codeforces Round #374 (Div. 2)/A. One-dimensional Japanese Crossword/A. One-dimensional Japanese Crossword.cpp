#include<cstdio>
#include<vector>
using namespace std;
int n,cnt=0;
char a[102];
vector<int> v;
int main(){
    scanf("%d %s",&n,a);
    for(int i=0;i<=n;i++){
        if(a[i]=='B')   cnt++;
        else if(cnt)
            v.push_back(cnt),cnt=0;
    }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)
        printf("%d ",v[i]);
    return 0;
}
