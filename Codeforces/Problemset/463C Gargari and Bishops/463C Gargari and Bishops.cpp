#include <cstdio>
#define L long long
int n;
L a[2002][2002], hs[4002][2], mxOdd = -1, mxEven = -1;
int oddX, oddY, evenX, evenY;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            scanf("%I64d", &a[i][j]);
            hs[i-j+2000][0] += a[i][j];
            hs[i+j][1] += a[i][j];
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            L t = hs[i-j+2000][0] + hs[i+j][1] - a[i][j];
            if( (i+j) & 1 ) {
                if(mxOdd < t) {
                    mxOdd = t;
                    oddX = i+1;
                    oddY = j+1;
                }
            }
            else {
                if(mxEven < t) {
                    mxEven = t;
                    evenX = i+1;
                    evenY = j+1;
                }
            }
        }
    printf("%I64d\n", mxOdd + mxEven);
    printf("%d %d %d %d", oddX, oddY, evenX, evenY);
    return 0;
}
