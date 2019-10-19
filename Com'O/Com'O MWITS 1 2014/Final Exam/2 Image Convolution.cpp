#include<stdio.h>
double a[1010][1010],b[1010][1010],c[1010][1010];
int main(){
	int m,n,d,i,j,k,l;
	scanf("%d %d %d",&m,&n,&d);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%lf",&a[i][j]);
	for(i=0;i<d;i++)
		for(j=0;j<d;j++)
			scanf("%lf",&b[i][j]);
	for(i=0;i<=m-d;i++)
		for(j=0;j<=n-d;j++)
			for(k=i;k<i+d;k++)
				for(l=j;l<j+d;l++)
					c[i][j]+=a[k][l]*b[k-i][l-j];
	for(i=0;i<=m-d;i++){
		for(j=0;j<=n-d;j++)
			if(c[i][j]<0)	printf("0 ");
			else if(c[i][j]>255)	printf("255 ");
			else	printf("%.0lf ",c[i][j]);
		printf("\n");
	}
	return 0;
}
