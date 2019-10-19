#include<stdio.h>

int main(){
    int n,m,i,j,k;
    int wheel[200][5],chk;
    int in_i,in_j,in_k;
    scanf("%d",&n);
    scanf("%d",&m);
    while(n--){
        chk=0;
        for(i=0;i<m;i++)
            scanf(" %d %d %d",&wheel[i][0],&wheel[i][1],&wheel[i][2]);
        for(i=0;i<m;i++)
            for(j=0;j<m;j++)
                for(k=0;k<m;k++)
                    if(wheel[i][0]==wheel[j][1]&&wheel[j][1]==wheel[k][2])
                            chk=1,in_i=i+1,in_j=j+1,in_k=k+1;
        if(chk)
            printf("YES %d %d %d\n",in_i,in_j,in_k);
        else
            printf("NO 0 0 0\n");
    }
    return 0;
}
