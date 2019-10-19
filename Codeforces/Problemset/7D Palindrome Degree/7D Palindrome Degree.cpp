#include<bits/stdc++.h>
using namespace std;
char str[5000010];
int dp[5000010],chk1=0,chk2=0,p=1,M=3;
int main(){
    scanf(" %s",str);
    int sum=0;
    for(int i=0;str[i];i++){
        chk1=chk1*M+str[i],chk2+=str[i]*p,p*=M;
        if(chk1==chk2)
            dp[i+1]=dp[(i+1)>>1]+1,sum+=dp[i+1];
    }
    printf("%d\n",sum);
    return 0;
}
