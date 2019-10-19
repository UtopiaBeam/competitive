#include<stdio.h>
#include<stdlib.h>
typedef struct{
    double b,p,bp;
    int in;
}item;
item it[25010];
int cmp(const void *a,const void *b){
    item *A,*B;
    A=(item *)a,B=(item *)b;
    if(A->bp < B->bp)   return 1;
    if(A->bp > B->bp)   return -1;
    return B->in - A->in;
}
int main(){
    double b,p,sum=0.0;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lf %lf",&it[i].b,&it[i].p);
        it[i].bp=it[i].b/it[i].p,it[i].in=i;
    }
    qsort(it,n,sizeof(item),cmp);
    sum+=it[0].p+it[1].p+it[2].p;
    printf("%.0lf\n",sum);
    for(i=0;i<3;i++)
        printf("%d\n",it[i].in+1);
    return 0;
}
