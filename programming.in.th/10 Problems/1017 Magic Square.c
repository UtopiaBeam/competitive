#include<stdio.h>
int main(){
    int n,i,j;
    int sqr[20][20],cnt[400],sumchk,sum=0,chk=1;
    scanf("%d",&n);
    for(i=1;i<=n*n;i++)
        cnt[i]=0;
    for(i=0;i<n&&chk;i++)
        for(j=0;j<n&&chk;j++){
            scanf("%d",&sqr[i][j]);
            if(sqr[i][j]>n*n)   chk=0;
            cnt[sqr[i][j]]++;
        }
    for(i=1;i<=n*n&chk;i++)
        if(cnt[i]>1)     chk=0;
    for(i=0;i<n;i++)
        sum+=sqr[i][0];
    for(i=0;i<n&&chk;i++){
        sumchk=0;
        for(j=0;j<n;j++)
            sumchk+=sqr[j][i];
        if(sumchk!=sum)     chk=0;
    }
    for(i=0;i<n&&chk;i++){
        sumchk=0;
        for(j=0;j<n;j++)
            sumchk+=sqr[i][j];
        if(sumchk!=sum)     chk=0;
    }
    for(i=0,sumchk=0;i<n&&chk;i++)
        sumchk+=sqr[i][i];
    if(sumchk!=sum)     chk=0;
    for(i=0,sumchk=0;i<n&&chk;i++)
        sumchk+=sqr[i][n-1-i];
    if(sumchk!=sum)     chk=0;
    if(chk)     printf("Yes\n");
    else        printf("No\n");
    return 0;
}
