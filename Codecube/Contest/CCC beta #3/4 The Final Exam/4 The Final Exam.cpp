#include<cstdio>
int n,a[10],sum=0,chk=1;
int main(){
    scanf("%d",&n);
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sum-=n;
    if(sum<0){
        printf("-1\n");     return 0;
    }
    if(sum==0){
        for(int i=0;i<5;i++)
            printf("%d ",a[i]);
        return 0;
    }
    for(int i=0;i<5;i++)
        if(a[i]==sum)   a[i]=0,sum=0,chk=0;
    if(chk) printf("-1\n");
    else for(int i=0;i<5;i++)
        printf("%d ",a[i]);
    return 0;
}
