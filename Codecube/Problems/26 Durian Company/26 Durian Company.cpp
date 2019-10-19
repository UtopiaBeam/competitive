#include<cstdio>
int a[1000005];
int n,s,e,Max=-10;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&s,&e);
        a[s]++,a[e]--;
    }
    for(int i=0;i<1000000;i++)
        a[i+1]+=a[i];
    for(int i=0;i<=1000000;i++)
        if(a[i]>Max)    Max=a[i];
    printf("%d\n",Max);
    return 0;
}
