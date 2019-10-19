#include<cstdio>
int t;
char a[100005];
int main(){
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        scanf(" %s",a);
        for(int i=0;a[i];i++)
            if(a[i]!='4' && a[i]!='7')   cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
