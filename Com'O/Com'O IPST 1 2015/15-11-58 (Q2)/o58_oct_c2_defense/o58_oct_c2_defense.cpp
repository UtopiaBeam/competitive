#include<cstdio>
#include<algorithm>
using namespace std;
#define INF (int)1e9
int n,k,mn=INF,a[3002];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<(1<<n);i++){
        int b[12];
        for(int j=0;j<n;j++)
            b[j]=(i>>j)%2;
//        for(int j=0;j<n;j++)
//            printf("%d",b[j]);
//        printf("\n");
        int cnt=0,sum=0;
        for(int j=0;j<k;j++){
            cnt+=b[j];
            if(b[j])    sum+=a[j];
        }
        if(cnt<2)   continue ;
        for(int j=k;j<n;j++){
            cnt-=b[j-k];
            if(b[j])    sum+=a[j],cnt++;
            if(cnt<2)   break;
            if(j==n-1){
                if(mn>sum){
                    mn=sum;
//                    for(int l=0;l<n;l++)
//                        printf("%d",b[l]);
//                    printf(" : %d\n",sum);
                }
            }
        }
    }
    printf("%d\n",mn);
    return 0;
}
