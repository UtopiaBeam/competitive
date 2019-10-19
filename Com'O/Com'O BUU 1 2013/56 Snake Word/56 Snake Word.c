#include<stdio.h>
#include<string.h>
#include<ctype.h>
int n,m,len,ans[105][2],c[30][30],chk;
char a[30][30],b[105];
void play(int i,int j,int cnt){
    if(cnt==len-1){
        int k;
        ans[cnt][0]=i,ans[cnt][1]=j;
        for(k=0;k<len;k++)
            printf("%d %d\n",ans[k][0],ans[k][1]);
        chk=0;
        return ;
    }
    else{
        ans[cnt][0]=i,ans[cnt][1]=j;
        if(i>1 && a[i-1][j]==b[cnt+1] && c[i-1][j]!=1){
            c[i-1][j]=1;    play(i-1,j,cnt+1);
            c[i-1][j]=0;
        }
        if(i<m && a[i+1][j]==b[cnt+1] && c[i+1][j]!=1){
            c[i+1][j]=1;    play(i+1,j,cnt+1);
            c[i+1][j]=0;
        }
        if(j>1 && a[i][j-1]==b[cnt+1] && c[i][j-1]!=1){
            c[i][j-1]=1;    play(i,j-1,cnt+1);
            c[i][j-1]=0;
        }
        if(j<n && a[i][j+1]==b[cnt+1] && c[i][j+1]!=1){
            c[i][j+1]=1;    play(i,j+1,cnt+1);
            c[i][j+1]=0;
        }
    }
}
int main(){
    int q,i,j;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++){
            scanf(" %c",&a[i][j]);
            a[i][j]=tolower(a[i][j]);
        }
    scanf("%d",&q);
    while(q--){
        chk=1;
        scanf(" %s",b);
        len=strlen(b);
        for(i=0;i<len;i++)
            b[i]=tolower(b[i]);
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                if(a[i][j]==b[0]){
                    c[i][j]=1;
                    play(i,j,0);
                    c[i][j]=0;
                }
        if(chk)     printf("No Matching Word\n");
    }
    return 0;
}
