#include<cstdio>
#include<algorithm>
using namespace std;
int seq[530],size=9;
int main(){
    for(int i=1;i<=9;i++)   seq[i]=i;
    int in=1;
    while(seq[size]!=123456789){
        for(int i=seq[in]%10+1;i<=9;i++)
            seq[++size]=seq[in]*10+i;
        in++;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        if(n>size)   printf("-1\n");
        else    printf("%d\n",seq[n]);
    }
    return 0;
}
