#include<cstdio>
char ch[100005];
int n,c,v[100005],suml=0,sumr=0,sum=0,sl,el,sr,er,f,t,chl=0,chr=0,chk=1,mx=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %c %d",&ch[i],&v[i]);
        if(ch[i]=='L')  suml+=v[i],chl=1;
        if(ch[i]=='R')  sumr+=v[i],chr=1;
    }
    if(n==1){
        if(ch[0]=='L')      printf("R %d 1 1\n",suml);
        else    printf("L %d 1 1\n",sumr);
    }
    else if(!chl)    printf("L %d 1 %d\n",sumr,n);
    else if(!chr)    printf("R %d 1 %d\n",suml,n);
    else{
        for(int i=0;i<n;i++){
            if(ch[i]=='L')      v[i]*=-1;
            if(sum+v[i]>0){
                sum+=v[i],t=i;
                if(chk)     f=i,chk=0;
                if(mx<sum)      mx=sum,sl=f,el=t;
                else if(mx==sum && el-sl>t-f)   sl=f,el=t;
            }
            else    sum=0,chk=1;
            if(ch[i]=='L')      v[i]*=-1;
        }
        suml+=mx;
        mx=0,sum=0,chk=1;
        for(int i=0;i<n;i++){
            if(ch[i]=='R')      v[i]*=-1;
            if(sum+v[i]>0){
                sum+=v[i],t=i;
                if(chk)     f=i,chk=0;
                if(mx<sum)      mx=sum,sr=f,er=t;
                else if(mx==sum && er-sr>t-f)   sr=f,er=t;
            }
            else    sum=0,chk=1;
            if(ch[i]=='R')      v[i]*=-1;
        }
        sumr+=mx;
        if(suml>sumr)       printf("L %d %d %d\n",suml,sl+1,el+1);
        else    printf("R %d %d %d\n",sumr,sr+1,er+1);
    }
    return 0;
}
