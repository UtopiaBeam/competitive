#include<cstdio>
int a[3],t,sum=0;
int main(){
    for(int i=0;i<3;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<3;i++){
        scanf("%d",&t);
        if(a[i]<t)      a[i]-=t,sum+=a[i];
        else    sum+=(a[i]-t)/2;
    }
    if(sum<0)   printf("No\n");
    else    printf("Yes\n");
    return 0;
}
