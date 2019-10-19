#include<cstdio>
int n,a[102],cnt=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(1){
        int mx=0;
        for(int i=1;i<n;i++)
            if(a[mx]<=a[i])  mx=i;
        if(mx==0){
            printf("%d\n",cnt);
            return 0;
        }
        a[mx]--,a[0]++,cnt++;
    }
}
