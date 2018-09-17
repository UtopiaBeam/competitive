#include<cstdio>
#include<algorithm>
using namespace std;
class cir{
public:
    int x,y,r;
}a[100005];
int n,cnt=0;
bool cmp(cir p,cir q){
    if(p.x!=q.x)    return p.x<q.x;
    return p.y<q.y;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].r);
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[j].x<=a[i].x-20)    break;
            if(a[j].y<=a[i].y-20)    continue;
            if((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)<(a[i].r+a[j].r)*(a[i].r+a[j].r))
                cnt++;
        }
        for(int j=i+1;j<n;j++){
            if(a[j].x>=a[i].x+20)    break;
            if(a[j].y>=a[i].y+20)    continue;
            if((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)<(a[i].r+a[j].r)*(a[i].r+a[j].r))
                cnt++;
        }
    }
    printf("%d\n",cnt/2);
    return 0;
}
