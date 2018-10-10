#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int amnt;
    double prc;
}rice;
rice r[100010];
int cmp(const void *a,const void *b){
    rice *aa=(rice *)a,*bb=(rice *)b;
    return (aa->prc > bb->prc)? 1:-1;
}
int main(){
    int n,a,i,in=0;
    double ans;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lf %d",&r[i].prc,&r[i].amnt);
        r[i].prc/=r[i].amnt;
    }
    qsort(r,n,sizeof(rice),cmp);
    scanf("%d",&n);
    while(n--){
        ans=0.00;
        scanf("%d",&a);
        while(a){
            if(a<=r[in].amnt){
                ans+=a*r[in].prc;
                r[in].amnt-=a,a=0;
            }
            else{
                ans+=r[in].amnt*r[in].prc;
                a-=r[in++].amnt;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
