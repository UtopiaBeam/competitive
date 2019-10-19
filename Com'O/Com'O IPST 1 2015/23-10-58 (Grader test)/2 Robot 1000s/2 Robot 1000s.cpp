#include<stdio.h>
#include<stdlib.h>
char a[105];
int main(){
    int k,cnt[4]={0,0,0,0};
    scanf(" %s",a);
    for(int i=0;a[i];i++){
        if(a[i]=='N')   cnt[0]++;
        if(a[i]=='E')   cnt[1]++;
        if(a[i]=='S')   cnt[2]++;
        if(a[i]=='W')   cnt[3]++;
    }
    scanf("%d",&k);
    while(k){
        if((cnt[0] && cnt[0]<=cnt[2]) || (cnt[0] && !cnt[2] && (!cnt[1] || !cnt[3]))){
            if(cnt[0]>=k)
                cnt[0]-=k,k=0;
            else    k-=cnt[0],cnt[0]=0;
        }
        else if((cnt[2] && cnt[2]<cnt[0]) || (cnt[2] && !cnt[0] && (!cnt[1] || !cnt[3]))){
            if(cnt[2]>=k)
                cnt[2]-=k,k=0;
            else    k-=cnt[2],cnt[2]=0;
        }
        else if((cnt[1] && cnt[1]<=cnt[3]) || (cnt[1] && !cnt[3] && (!cnt[0] || !cnt[2]))){
            if(cnt[1]>=k)
                cnt[1]-=k,k=0;
            else    k-=cnt[1],cnt[1]=0;
        }
        else if((cnt[3] && cnt[3]<cnt[1]) || (cnt[3] && !cnt[1] && (!cnt[0] || !cnt[2]))){
            if(cnt[3]>=k)
                cnt[3]-=k,k=0;
            else    k-=cnt[3],cnt[3]=0;
        }
    }
    printf("%d\n",2*(abs(cnt[0]-cnt[2])+abs(cnt[1]-cnt[3])));
    return 0;
}

