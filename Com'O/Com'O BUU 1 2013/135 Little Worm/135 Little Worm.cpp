#include<cstdio>
int r,c,n,x,y,fi,fj,a[630][630],b[630][630],si[5]={0,-1,1,0},sj[5]={1,0,0,-1},mx=0;
char d[5]="ENSW",an='E',ch;
bool chk(int i,int j){
    return (i>=0) && (j>=0) && (i<r) && (j<c) && (a[i][j]!=-1) && (b[i][j]==0);
}
void f(int i,int j,int cnt,int di){
    b[i][j]=1;
    if(mx<cnt)    mx=cnt,x=fi,y=fj,an=ch;
    if(chk(i+si[di],j+sj[di]))  f(i+si[di],j+sj[di],cnt+1,di);
    else if(di==1 || di==2){
        if(chk(i+si[0],j+sj[0]))    f(i+si[0],j+sj[0],cnt+1,0);
        if(chk(i+si[3],j+sj[3]))    f(i+si[3],j+sj[3],cnt+1,3);
    }
    else{
        if(chk(i+si[1],j+sj[1]))    f(i+si[1],j+sj[1],cnt+1,1);
        if(chk(i+si[2],j+sj[2]))    f(i+si[2],j+sj[2],cnt+1,2);
    }
    b[i][j]=0;
}
int main(){
    scanf("%d %d %d",&r,&c,&n);
    while(n--){
        scanf("%d %d",&x,&y);
        a[x][y]=-1;
    }
    x=y=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(a[i][j]!=-1){
                if(!mx)     mx=1,x=i,y=j;
                for(int k=0;k<4;k++)
                    if(chk(i+si[k],j+sj[k]))
                        fi=i,fj=j,ch=d[k],f(i,j,1,k);
            }
    printf("%d %d %d %c\n",mx,x,y,an);
    return 0;
}
