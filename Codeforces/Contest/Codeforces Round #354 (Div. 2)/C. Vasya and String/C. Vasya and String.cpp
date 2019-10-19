//10 2
//ababbbbaba
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,dp[100002][2][2],mx=0;
char a[100002];
int main(){
    scanf("%d %d %s",&n,&m,a);
    dp[0][a[0]-'a'][0]=dp[0]['b'-a[0]][1]=1;
    for(int i=1;i<n;i++){
        dp[i][a[i]-'a'][0]=dp[i-1][a[i]-'a'][0]+1;
        dp[i]['b'-a[i]][0]=0;
        for(int k=1;k<=m;k++){
            if(i<k){
                dp[i][a[i]-'a'][k]=0;
                dp[i]['b'-a[i]][k]=dp[i-1]['b'-a[i]][k]+1;
            }
            else{
                dp[i][a[i]-'a'][k]=dp[i-1][a[i]-'a'][k]+1;
                dp[i]['b'-a[i]][k]=dp[i-1]['b'-a[i]][k-1]+1;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d : %c\n----------------\n",i,a[i]);
        for(int j=0;j<2;j++){
            printf("%c",j+'a');
            for(int k=0;k<=m;k++){
                if(i<k)           printf("#");
                else if(k)       printf(" ");
                printf(" %d = %d\n",k,dp[i][j][k]);
            }
        }
        printf("----------------\n");
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<=m;k++)
                mx=max(mx,dp[i][j][k]);
    printf("%d\n",mx);
    return 0;
}
