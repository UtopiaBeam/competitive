#include<stdio.h>
#include<stdlib.h>
#define INF 1<<20
typedef struct{
    int s,e;
}pnt;
pnt b[100010];
int a[10010];
int cmp(const void *p,const void *q){
    pnt *pp=(pnt *)p,*qq=(pnt *)q;
    return pp->s - qq->s;
}
int main(){
    int k,n,m,i;
    scanf("%d %d %d",&k,&n,&m);
    for(i=2;i<=n;i++)
        a[i]=INF;
    for(i=0;i<m;i++)
        scanf("%d %d",&b[i].s,&b[i].e);
    qsort(b,m,sizeof(pnt),cmp);
    if(b[0].s>1){
        printf("1\n");
        return 0;
    }
    for(i=0;i<m;i++){
        if(b[i].s==1)   a[b[i].e]=1;
        if(a[b[i].e]>a[b[i].s]+1)    a[b[i].e]=a[b[i].s]+1;
    }
    for(i=n;i>1;i--)
        if(a[i]<=k){
            printf("%d\n",i);
            return 0;
        }
}
