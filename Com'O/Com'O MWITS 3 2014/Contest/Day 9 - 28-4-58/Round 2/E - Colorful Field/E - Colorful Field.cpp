#include<cstdio>
#include<algorithm>
using namespace std;
class waste{
public:
    int x,y;
}a[1005];
int n,m,k,t;
bool cmp(waste a,waste b){
    if(a.x != b.x)     return a.x < b.x;
    return a.y < b.y;
}
int bs(int s,int e,int x,int y){
    if(s>e)     return -1;
    int m=(s+e+1)/2;
    if(a[m].x==x && a[m].y==y)  return m;
    if(a[m].x<=x && x<=a[m+1].x) return m;
    if(a[m].x==a[m+1].x && a[m].y<=y && y<a[m+1].y)     return m;
    if(a[m].x>x)    return bs(s,m-1,x,y);
    return bs(m+1,e,x,y);
}
int main(){
    scanf("%d %d %d %d",&n,&m,&k,&t);
    for(int i=0;i<k;i++)
        scanf("%d %d",&a[i].x,&a[i].y);
    sort(a,a+k,cmp);
    printf("\n");
    for(int i=0;i<k;i++)
        printf("%d %d\n",a[i].x,a[i].y);
    printf("\n");
    while(t--){
        int x,y,chk;
        scanf("%d %d",&x,&y);
        int in=bs(0,k-1,x,y);
        printf("in = %d\n",in);
        if(a[in].x==x && a[in].y==y)    printf("Waste\n");
        else{
            chk=(x-1)*m+(y-1);
            if(x>a[0].x || y>=a[0].y)   chk-=in+1;
            if(chk%3==0)    printf("Carrots\n");
            else if(chk%3==1)   printf("Kiwis\n");
            else    printf("Grapes\n");
        }
    }
    return 0;
}
