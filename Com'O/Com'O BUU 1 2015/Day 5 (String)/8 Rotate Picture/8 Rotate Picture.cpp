#include<cstdio>
char a[52][52],b[12],t[52][52],c;
int n;
int main(){
    scanf("%d ",&n);
    for(int i=0;i<n;i++)    gets(a[i]);
    scanf(" %s",b);
    for(int k=0;b[k];k++){
        if(b[k]=='H'){
            for(int i=0;i<n/2;i++)
                for(int j=0;j<n;j++)
                    c=a[i][j],a[i][j]=a[n-i-1][j],a[n-1-i][j]=c;
        }
        else if(b[k]=='V'){
            for(int i=0;i<n;i++)
                for(int j=0;j<n/2;j++)
                    c=a[i][j],a[i][j]=a[i][n-1-j],a[i][n-1-j]=c;
        }
        else if(b[k]=='L'){
            for(int aj=n-1,ti=0;aj>=0 && ti<n;aj--,ti++)
                for(int ai=0,tj=0;ai<n && tj<n;ai++,tj++){
                    t[ti][tj]=a[ai][aj];
                }
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    a[i][j]=t[i][j];
        }
        else{
            for(int aj=0,ti=0;aj<n && ti<n;aj++,ti++)
                for(int ai=n-1,tj=0;ai>=0 && tj<n;ai--,tj++){
                    t[ti][tj]=a[ai][aj];
                }
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    a[i][j]=t[i][j];
        }
    }
    for(int i=0;i<n;i++)    printf("%s\n",a[i]);
    return 0;
}
