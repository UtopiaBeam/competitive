#include<cstdio>
int r,c,cnt=0,chk=-1;
char a[502][502];
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    for(int i=0;i<r;i++){
        cnt=0;
        for(int j=0;j<c;j++)
            cnt+=a[i][j]=='X';
        if(chk<0){
            if(cnt>0)   chk=cnt;
        }
        else if(cnt==0)     chk=0;
        else if(chk!=cnt){
            printf("NO\n");
            return 0;
        }
    }
    chk=-1;
    for(int j=0;j<c;j++){
        cnt=0;
        for(int i=0;i<r;i++)
            cnt+=a[i][j]=='X';
        if(chk<0){
            if(cnt>0)   chk=cnt;
        }
        else if(cnt==0)     chk=0;
        else if(chk!=cnt){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
