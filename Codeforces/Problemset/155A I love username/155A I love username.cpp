#include<cstdio>
int a[1005],n,cnt=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        int chk=1;
        for(int j=0;j<i;j++){
            if(a[j]>=a[i])  break;
            if(j==i-1)  cnt++,chk=0;
        }
        for(int j=0;j<i && chk;j++){
            if(a[j]<=a[i])  break;
            if(j==i-1)  cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
