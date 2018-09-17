#include<cstdio>
char a[20][20];
int r,c,n;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    scanf("%d",&n);
    if(n==0 || n==360){
        for(int i=0;i<r;i++)
            printf("%s\n",a[i]);
    }
    else if(n==45){
        for(int k=0;k<r+c-1;k++){
            if(k<r)
                for(int i=1;i<r-k;i++)
                    printf(" ");
            else for(int i=0;i<=k-r;i++)
                printf(" ");
            for(int i=k,j=0;i>=0 && j<=k;i--,j++){
                if(i>=r || j>=c)     continue;
                printf("%c ",a[i][j]);
            }
            printf("\n");
        }
    }
    else if(n==90){
        for(int j=0;j<c;j++){
            for(int i=r-1;i>=0;i--)
                printf("%c",a[i][j]);
            printf("\n");
        }
    }
    else if(n==135){
        for(int k=0;k<r+c-1;k++){
            if(k<c)
                for(int i=1;i<c-k;i++)
                    printf(" ");
            else for(int i=0;i<=k-c;i++)
                printf(" ");
            for(int i=r-1,j=k;i>=0 && j>=0;i--,j--){
                if(i>=r || j>=c)     continue;
                printf("%c ",a[i][j]);
            }
            printf("\n");
        }
    }
    else if(n==180){
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--)
                printf("%c",a[i][j]);
            printf("\n");
        }
    }
    else if(n==225){
        for(int k=0;k<r+c-1;k++){
            if(k<r)
                for(int i=1;i<r-k;i++)
                    printf(" ");
            else for(int i=0;i<=k-r;i++)
                printf(" ");
            for(int i=r-1-k,j=c-1;i<r && j>=0;i++,j--){
                if(i<0 || j<0)     continue;
                printf("%c ",a[i][j]);
            }
            printf("\n");
        }
    }
    else if(n==270){
        for(int j=c-1;j>=0;j--){
            for(int i=0;i<r;i++)
                printf("%c",a[i][j]);
            printf("\n");
        }
    }
    else if(n==315){
        for(int k=0;k<r+c-1;k++){
            if(k<c)
                for(int i=1;i<c-k;i++)
                    printf(" ");
            else for(int i=0;i<=k-c;i++)
                printf(" ");
            for(int i=0,j=c-1-k;i<r && j<c;i++,j++){
                if(i<0 || j<0)     continue;
                printf("%c ",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
