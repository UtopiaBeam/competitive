#include<stdio.h>
int x[5010],y[5010],r,c,maxx=-10,maxy=-10;
int main(){
    int n,i,j,h,k,r;
    scanf("%d %d %d",&r,&c,&n);
    while(n--){
        scanf("%d %d %d",&h,&k,&r);
        if(h>=r)
            for(i=h-r;i<=h+r && i<=5000;i++)
                x[i]++;
        else
            for(i=0;i<=h+r && i<=5000;i++)
                x[i]++;
        if(k>=r)
            for(i=k-r;i<=k+r && i<=5000;i++)
                y[i]++;
        else
            for(i=0;i<=k+r && i<=5000;i++)
                y[i]++;
    }
    for(i=0;i<=5000;i++){
        if(maxx<x[i])   maxx=x[i];
        if(maxy<y[i])   maxy=y[i];
    }
    printf("%d\n",(maxx>maxy)? maxx:maxy);
    return 0;
}
