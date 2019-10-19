#include<stdio.h>
#include<string.h>
int q[1000],mark[50],a[50][50];
char name[50][5];
int main(){
    char from[5],to[5];
    int m,n,p,i,j,marki,markj,front,rear,nowi;
    scanf("%d %d %d",&m,&n,&p);
    for(i=0;i<m;i++)
        scanf(" %s",name[i]);
    while(n--){
        scanf(" %s %s",from,to);
        for(i=0;i<m;i++)
            if(!strcmp(from,name[i]))   marki=i;
        for(i=0;i<m;i++)
            if(!strcmp(to,name[i]))     markj=i;
        a[marki][markj]=a[markj][marki]=1;
    }
    while(p--){
        memset(q,-1,sizeof(q));
        memset(mark,-1,sizeof(mark));
        front=0,rear=1,mark[0]=0;
        scanf("%d %s %s",&n,from,to);
        for(i=0;i<m;i++)
            if(!strcmp(from,name[i]))   marki=i;
        q[0]=marki;
        while(front<rear){
            nowi=q[front];
            for(i=0;i<m;i++){
                if(a[nowi][i]==1 && mark[i]==-1){
                    q[rear++]=i,mark[i]=mark[nowi]+1;
                    printf("%d %d\n",nowi,i);
                }
            }
            front++;
        }
        for(i=0;i<m;i++)
            printf("%d ",mark[i]);
        printf("\n");
        for(i=0;i<m;i++)
            if(!strcmp(to,name[i]))     marki=i;
        if(mark[marki]!=-1) printf("%s %s %d\n",from,to,n*mark[marki]*1128);
        else    printf("NO SHIPMENT POSSIBLE\n");
    }
    return 0;
}
