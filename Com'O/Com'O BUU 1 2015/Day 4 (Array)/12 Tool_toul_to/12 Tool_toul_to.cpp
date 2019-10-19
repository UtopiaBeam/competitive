#include<cstdio>
int r,c,n,a,b,x[1002],y[1002];
int main(){
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            scanf("%d",&a);
            if(x[i]<a)  x[i]=a;
            if(y[j]<a)  y[j]=a;
        }
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&a,&b);
        if(a>r || a<1 || b>c || b<1)    printf("-1\n");
        else if(x[a]>=y[b])  printf("%d\n",x[a]);
        else    printf("%d\n",y[b]);
    }
    return 0;
}
