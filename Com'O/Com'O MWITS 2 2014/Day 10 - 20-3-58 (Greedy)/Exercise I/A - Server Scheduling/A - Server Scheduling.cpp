//Not done
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
class ser{
public:
    int str,end,in;
}a[1005];
vector <int> ans;
bool cmp(ser p,ser q){
    return p.end<q.end;
}
int main(){
    int n,last=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int h1,m1,h2,m2;
        scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
        a[i].str=h1*60+m1,a[i].end=h2*60+m2,a[i].in=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=0;i<n;i++){

    }
    return 0;
}
