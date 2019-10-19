#include<cstdio>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
struct S{
    long long x,y;
}t;
typedef vector<S> pnt;
pnt a;
int n;
bool cx(S a,S b){
    return a.x < b.x;
}
bool cy(S a,S b){
    return a.y < b.y;
}
long long sqrd(S a,S b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
long long cls_strip(pnt strip){
    long long mn=LLONG_MAX;
    for(int i=0;i<strip.size()-1;i++)
        for(int j=i+1;j<strip.size() && mn>strip[j].y-strip[i].y;j++)
            mn=min(mn,sqrd(strip[i],strip[j]));
    return mn;
}
long long cls(pnt px,pnt py){
    if(px.size()<=3)    return cls_strip(px);
    int m=px.size()/2;
    pnt pxl,pxr,pyl,pyr;
    for(int i=0;i<px.size();i++)
        if(py[i].x<=px[m].x)      pyl.push_back(py[i]);
        else    pyr.push_back(py[i]);
    pxl=pnt(px.begin(),px.begin()+m);
    pxr=pnt(px.begin()+m+1,px.end());
    long long d=min(cls(pxl,pyl),cls(pxr,pyr));
    pnt strip;
    for(int i=0;i<px.size();i++)
        if(abs(px[i].x-px[m].x)<=d)  strip.push_back(px[i]);
    return min(d,cls_strip(strip));
}
long long Cls(pnt p){
    pnt px=p,py=p;
    sort(px.begin(),px.end(),cx);
    sort(py.begin(),py.end(),cy);
    return cls(px,py);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&t.x,&t.y);
        a.push_back(t);
    }
    printf("%lld\n",Cls(a));
    return 0;
}
