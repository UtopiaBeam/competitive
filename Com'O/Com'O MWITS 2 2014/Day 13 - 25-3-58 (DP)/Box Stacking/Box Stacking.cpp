#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
class box{
public:
    int w,l,h,in;
};
vector <box> a;
bool cmp(box aa,box bb){
    if(aa.l!=bb.l)    return aa.l > bb.l;
    return aa.w > bb.w;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int b[4];
        box tmp;
        scanf("%d %d %d",&b[0],&b[1],&b[2]);
        sort(b,b+3);
        tmp.in=i+1;
        tmp.l=b[2],tmp.w=b[1],tmp.h=b[0];
        a.push_back(tmp);
        tmp.l=b[1],tmp.w=b[0],tmp.h=b[2];
        a.push_back(tmp);
    }
    sort(a.begin(),a.end(),cmp);
    int dp[a.size()+5],path[a.size()+5];
    for(int i=0;i<a.size();i++)
        dp[i]=a[i].h,path[i]=i;
    for(int i=1;i<a.size();i++)
        for(int j=0;j<i;j++)
            if(a[i].l<a[j].l && a[i].w<a[j].w && dp[j]+a[i].h>dp[i])
                dp[i]=dp[j]+a[i].h,path[i]=j;
    int Max=0,last;
    for(int i=0;i<a.size();i++)
        Max=max(Max,dp[i]),last=i;
    printf("%d\n",Max);
    while(1){
        printf("%d ",a[last].in);
        if(path[last]==last){
            printf("\n");   return 0;
        }
        last=path[last];
    }
}
