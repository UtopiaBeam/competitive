#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int p,a;
}item;
item it[5010];
int cmp(const void *p1,const void *p2){
    item *aa,*bb;
    aa=(item *)p1,bb=(item *)p2;
    if(aa->p > bb->p)     return 1;
    return -1;
}
int main(){
    int n,m,i,sum=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
        scanf("%d %d",&it[i].p,&it[i].a);
    qsort(it,m,sizeof(item),cmp);
    for(i=0;i<m;i++){
        if(it[i].a<=n){
            sum+=it[i].p*it[i].a;
            n-=it[i].a;
        }
        else{
            sum+=it[i].p*n;
            break;
        }
    }
    printf("%d\n",sum);
    return 0;
}
