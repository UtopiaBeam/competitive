#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
int t,n,l;
int main(){
//    freopen("A-large-practice.in","r",stdin);
//    freopen("A-large-practice.out","w",stdout);
    scanf("%d",&t);
    for(int q=1;q<=t;q++){
        char aa[152][42],bb[152][42];
        long long a[152]={},b[152]={},c,d[152];
        int chk=1,mn=INT_MAX;
        scanf("%d %d ",&n,&l);
        for(int i=0;i<n;i++)    scanf(" %s",aa[i]);
        for(int i=0;i<n;i++)    scanf(" %s",bb[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<l;j++){
                a[i]*=2,a[i]+=(long long)(aa[i][j]-'0');
                b[i]*=2,b[i]+=(long long)(bb[i][j]-'0');
            }
        sort(a,a+n);    sort(b,b+n);
        for(int i=0;i<n;i++){
            c=a[0]^b[i];
            for(int j=0;j<n;j++)    d[j]=a[j]^c;
            sort(d,d+n);
            for(int j=0;j<n;j++){
                if(b[j]!=d[j])      break;
                if(j==n-1){
                    int cnt=0;
                    for(int k=0;k<l;k++)    cnt+=c%2,c/=2;
                    chk=0,mn=min(mn,cnt);
                }
            }
        }
        printf("Case #%d: ",q);
        if(chk)     printf("NOT POSSIBLE\n");
        else    printf("%d\n",mn);
    }
    return 0;
}
