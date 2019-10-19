#include<stdio.h>
#include<string.h>
int mark[1000],q[1000],a[50][50];
char name[50][5];
int main(){
    memset(a,0,sizeof(a));
    char from[5],to[5];
    int m,n,p,i,j,str,end,front,rear,now;
    scanf("%d %d %d",&m,&n,&p);
    for(i=0;i<m;i++)
        scanf(" %s",name[i]);
    while(n--){
        scanf(" %s %s",from,to);
        for(i=0;i<m;i++)
            if(!strcmp(name[i],from)){
                str=i;     break;
            }
        for(i=0;i<m;i++)
            if(!strcmp(name[i],to)){
                end=i;     break;
            }
        a[str][end]=a[end][str]=1;
    }
    printf("  ");
    for(i=0;i<m;i++)
        printf("%d ",i);
    printf("\n");
    for(i=0;i<m;i++){
        printf("%d ",i);
        for(j=0;j<m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    while(p--){
        front=0,rear=1;
        memset(mark,-1,sizeof(mark));
        memset(q,0,sizeof(q));
        scanf("%d %s %s",&n,from,to);
        for(i=0;i<m;i++)
            if(!strcmp(name[i],from)){
                str=i;      break;
            }
        for(i=0;i<m;i++)
            if(!strcmp(name[i],to)){
                end=i;      break;
            }
        q[0]=str;   mark[str]=0;
        while(front<rear){
            now=q[front];
            for(i=0;i<m;i++)
                if(a[now][i]==1){
                    q[rear++]=i;
                    if(mark[i]==-1||mark[i]>mark[now]+1)
                        mark[i]=mark[now]+1;
                }
            front++;
        }
//        if(mark[end]!=-1)   printf("%s %s %d\n",from,to,mark[end]*n*1128);
//        else    printf("NO SHIPMENT POSSIBLE\n");
    }
    return 0;
}
