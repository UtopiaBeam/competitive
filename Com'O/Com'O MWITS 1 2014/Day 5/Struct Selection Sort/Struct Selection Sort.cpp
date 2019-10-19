#include<stdio.h>
struct coor{
    int x,y;
}a[1010],t;
int main(){
    int n,i,j,in,minx,miny;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i].x,&a[i].y);
    for(i=0,in=i;i<n;i++){
        for(j=i,minx=1<<20,miny=1<<20;j<n;j++){
            if(minx>a[j].x)
                minx=a[j].x,in=j;
            if(minx==a[j].x && miny>a[j].y)
                miny=a[j].y,in=j;
        }
        t=a[i]; a[i]=a[in]; a[in]=t;
    }
    for(i=0;i<n;i++)
        printf("%d %d\n",a[i].x,a[i].y);
    return 0;
}
