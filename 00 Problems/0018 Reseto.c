#include<stdio.h>
int a[1010];
int main(){
    int n,k,i,j,cnt=0;
    scanf("%d %d",&n,&k);
    for(i=2;i<=n;i++)
        if(!a[i])
            for(j=i;j<=n;j+=i)
                if(!a[j])    a[j]=1,cnt++;
                if(cnt==k){
                    printf("%d\n",j);
                    return 0;
                }
}
