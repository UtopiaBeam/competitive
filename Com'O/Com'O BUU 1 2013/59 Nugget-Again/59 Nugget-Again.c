#include<stdio.h>
int a[1000010],b[10];
int main(){
    int n,q,i,j,k,m,r,s,cnt;
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++){
            scanf("%d",&b[j]);
            a[b[j]]=i;
        }
        cnt=0;
        for(j=1;j<=m;j++){
            if(a[j]==i)     cnt++;
            else{
                for(k=0;k<n;k++){
                    if(j-b[k]>=0 && a[j-b[k]]==i){
                        a[j]=i;
                        cnt++;
                        break;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
