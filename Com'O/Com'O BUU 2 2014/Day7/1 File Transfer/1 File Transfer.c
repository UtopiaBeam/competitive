#include<stdio.h>
int n,a[1010][100010],chk,i,ed[1010],cnt[1010];
void play(int x,int y){
    int k;
    if(x==y){
        chk=1;  return ;
    }
    for(k=0;k<cnt[x];k++){
        if(ed[a[x][k]]!=i){
            ed[a[x][k]]=i;
            play(a[x][k],y);
        }
    }
}
int main(){
    int m,q,x,y;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d",&x,&y);
        a[x][cnt[x]++]=y;
    }
    for(i=1;i<=q;i++){
        scanf("%d %d",&x,&y);
        chk=0;
        ed[x]=i;
        play(x,y);
        if(chk)     printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
