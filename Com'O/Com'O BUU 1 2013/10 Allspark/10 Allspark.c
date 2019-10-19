#include<stdio.h>

int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
		for(j=1;j<=4*n-1;j++)
			if(i+j>2*n && j-i<2*n)
				printf("*");
			else
				printf("-");
		printf("\n");
	}
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=4*n-1;j++)
    		if(j-i>=n && j+i<=3*n)
				printf("+");
			else if(i+j<=n || j-i>=3*n)
				printf("-");
			else
				printf("*");
		printf("\n");
	}
	return 0;
}
