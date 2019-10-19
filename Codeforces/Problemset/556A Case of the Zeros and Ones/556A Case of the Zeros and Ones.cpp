#include<cstdio>
int cnt[2],n;
char a[200005];
int abs(int x){
    return x>0? x:-x;
}
int main(){
    scanf("%d %s",&n,a);
    for(int i=0;i<n;i++)
        cnt[a[i]-'0']++;
    printf("%d\n",abs(cnt[0]-cnt[1]));
    return 0;
}
