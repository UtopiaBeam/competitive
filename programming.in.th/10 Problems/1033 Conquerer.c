#include<stdio.h>
#include<string.h>
int a[110][110],nowx[5],nowy[5],max=-10;
char ch[4010];
int main(){
    int n,k,i,j,turn;
    scanf("%d %d",&n,&k);
    a[0][0]=4,a[0][n-1]=1,a[n-1][n-1]=2,a[n-1][0]=3;
    nowx[1]=0,nowy[1]=n-1;
    nowx[2]=n-1,nowy[2]=n-1;
    nowx[3]=n-1,nowy[3]=0;
    nowx[4]=0,nowy[4]=0;
    for(i=0;i<4;i++)
        for(j=0;j<k;j++)
            scanf(" %c",&ch[i+4*j]);
    for(i=0;i<4*k;i++){
        int chk=0;
        turn=i%4+1;
        if(ch[i]=='N' && nowx[turn]>0)
            nowx[turn]--;
        if(ch[i]=='S' && nowx[turn]<n-1)
            nowx[turn]++;
        if(ch[i]=='E' && nowy[turn]<n-1)
            nowy[turn]++;
        if(ch[i]=='W' && nowy[turn]>0)
            nowy[turn]--;
        for(j=1;j<5;j++)
            if(turn!=j && nowx[j]==nowx[turn] && nowy[j]==nowy[turn]){
                chk=1;  break;
            }
        if(chk){
            if(ch[i]=='N')
                nowx[turn]++;
            if(ch[i]=='S')
                nowx[turn]--;
            if(ch[i]=='E')
                nowy[turn]--;
            if(ch[i]=='W')
                nowy[turn]++;
        }
        a[nowx[turn]][nowy[turn]]=turn;
    }
    memset(nowx,0,sizeof(nowx));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(a[i][j]==0){
                printf("No\n");
                return 0;
            }
            nowx[a[i][j]]++;
        }
    n=0;
    for(i=1;i<5;i++)
        if(max<nowx[i])     max=nowx[i],n=1;
        else if(max==nowx[i])   n++;
    printf("%d %d\n",n,max);
    for(i=1;i<5;i++)
        if(max==nowx[i])    printf("%d\n",i);
    return 0;
}
