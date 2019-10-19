#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class bomb{
public:
    int x,y;
}a[1000005];
int n,last=0;
vector <int> ans;
bool cmp(bomb a,bomb b){
    if(a.x!=b.x)    return a.x<b.x;
    return a.y>b.y;
}
int Max=-10;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&a[i].x,&a[i].y);
    sort(a,a+n,cmp);
    for(int i=n-1;i>=0;i--)
        if(Max<=a[i].y)  Max=a[i].y,ans.push_back(i);
    for(int i=ans.size()-1;i>=0;i--)
        printf("%d %d\n",a[ans[i]].x,a[ans[i]].y);
    return 0;
}
