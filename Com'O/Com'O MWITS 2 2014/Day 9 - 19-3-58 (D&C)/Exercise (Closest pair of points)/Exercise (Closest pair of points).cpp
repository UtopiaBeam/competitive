#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
class pnt{
public:
    float x,y;
};
typedef vector <pnt> point;
point a;
bool cmpx(pnt a,pnt b){ return a.x<b.x;  }
bool cmpy(pnt a,pnt b){ return a.y<b.y;  }
float dis(pnt a,pnt b){
    return pow(a.x - b.x,2)+pow(a.y - b.y,2);
}
float cls_strip(point p){
    float Min=INFINITY;
    for(int i=0;i<p.size()-1;i++)
        for(int j=i+1;j<p.size() && (p[j].y-p[i].y)<Min;j++)
            Min=min(Min,dis(p[i],p[j]));
    return Min;
}
float cls(point px,point py){
    if(px.size()<=3)    return cls_strip(px);
    int mid=px.size()/2;
    point pyl,pyr;
    for(int i=0;i<py.size();i++)
        if(px[i].x<=px[mid].x)    pyl.push_back(py[i]);
        else    pyr.push_back(py[i]);
    point pxl=point(px.begin(),px.begin()+mid);
    point pxr=point(px.begin()+mid,px.end());
    float d=min(cls(pxl,pyl),cls(pxr,pyr));
    point tmp;
    for(int i=0;i<px.size();i++)
        if(abs(px[i].x-px[mid].x)<d)   tmp.push_back(px[i]);
    return min(d,cls_strip(tmp));
}
float closest(point p){
    point px=p,py=p;
    sort(px.begin(),px.end(),cmpx);     sort(py.begin(),py.end(),cmpy);
    return cls(px,py);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        pnt t;
        scanf("%f %f",&t.x,&t.y);
        a.push_back(t);
    }
    printf("%.4lf\n",closest(a));
    return 0;
}
