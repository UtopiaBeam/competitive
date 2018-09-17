#include<cstdio>
#define ll long long
#define F first
#define S second
using namespace std;
int a[1000002],b[1000002];
ll l[2000002],r[2000002],cnt=0;
int main(){
    int n,k,chk=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(chk){
            b[i]=b[i-1];
            if(a[i]>k)  r[++b[i]+1000000]++;
            else    r[--b[i]+1000000]++;
        }
        else if(a[i]==k){
            b[i]=0,chk=1;
            for(int j=i-1;j>=0;j--){
                b[j]=b[j+1];
                if(a[j]<k)  l[++b[j]+1000000]++;
                else    l[--b[j]+1000000]++;
            }
        }
    }
    for(int i=0;i<=2000000;i++)
        cnt+=l[i]*r[i]+(i==1000000)*(l[1000000]+r[1000000]+1);
    printf("%lld\n",cnt);
    return 0;
}
