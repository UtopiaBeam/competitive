#include<cstdio>
int n,m,t,a[500002],mn=1<<20,cnt=0;
int main(){
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        scanf("%d",&t);
        if(i%2)     a[1]++,a[t+1]--;
        else        a[n-t+1]++;
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        if(mn>a[i])     mn=a[i],cnt=1;
        else if(mn==a[i])   cnt++;
    }
//    for(int i=1;i<=n;i++)
//        printf("%d ",a[i]);
//    printf("\n");
    printf("%d %d\n",mn,cnt);
    return 0;
}
