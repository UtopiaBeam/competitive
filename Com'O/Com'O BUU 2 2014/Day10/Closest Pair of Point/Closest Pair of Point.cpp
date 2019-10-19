#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef struct point{
    double x,y;
}point;
point pnt[10010];
int cnt=0;
int cmp(const void *a,const void *b){
    point *A,*B;
    A=(point *)a,B=(point *)b;
    return A->x - B->x;
}
double Min=1<<20;
double conquer(int i,int j){
    double d;
    d=sqrt(pow((pnt[i].x-pnt[j].x),2)+pow((pnt[i].y-pnt[j].y),2));
    return d;
}
void divide(int i,int j){
    double dl,dr;
    int mid;
    if(i>=j)    return ;
    mid=(i+j)/2;
    divide(i,mid);  divide(mid,j);
    dl=conquer(i,mid); dr=conquer(mid,j);
    Min=min(min(Min,dl),dr);
}
int main(){
    int n,i;
    double mid;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lf %lf",&pnt[i].x,&pnt[i].y);
    qsort(pnt,n,sizeof(pnt[0]),cmp);
    divide(0,n-1);
    printf("INFINITY 0\n");
    return 0;
}
