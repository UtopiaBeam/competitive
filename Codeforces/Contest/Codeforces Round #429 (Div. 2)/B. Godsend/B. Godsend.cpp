#include <cstdio>
int n, t, sum = 0;
bool isOdd = false;
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &t);
        sum = (sum + t % 2) % 2;
        if(t % 2)       isOdd = true;
    }
    if(sum == 1)                printf("First\n");
    else if(isOdd == true)      printf("First\n");
    else                        printf("Second\n");
    return 0;
}
