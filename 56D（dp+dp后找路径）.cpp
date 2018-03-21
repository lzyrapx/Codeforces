#include <cstdio>
#include <cstring>

#define N 1001

using namespace std;

int n, m, dp[N][N];
char a[N], b[N];

int main()
{
    scanf("%s%s", a, b);
    n = strlen(a), m = strlen(b);
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++ i)
        dp[i][0] = i;
    for(int j = 1; j <= m; ++ j)
        dp[0][j] = j;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            dp[i][j] = N;
            if(j && dp[i][j - 1] + 1 < dp[i][j]) // INSERT
                dp[i][j] = dp[i][j - 1] + 1;
            if(i && dp[i - 1][j] + 1 < dp[i][j]) // DELETE
                dp[i][j] = dp[i - 1][j] + 1;
            if(i && j && dp[i - 1][j - 1] + 1 < dp[i][j]) // REPLACE
                dp[i][j] = dp[i - 1][j - 1] + 1;
            if(i && j && a[i - 1] == b[j - 1] && dp[i - 1][j - 1] < dp[i][j])
                dp[i][j] = dp[i - 1][j - 1];
        }
    printf("%d\n", dp[n][m]);     
	   
    while(n > 0 || m > 0) //dp后再找路径 
    {
        if(m && dp[n][m - 1] + 1 == dp[n][m])
        {
            printf("INSERT %d %c\n", n + 1, b[m - 1]);
            m --;
            continue;
        }
        if(n && dp[n - 1][m] + 1 == dp[n][m])
        {
            printf("DELETE %d\n", n);
            n --;
            continue;
        }
        if(n && m && dp[n - 1][m - 1] + 1 == dp[n][m])
        {
            printf("REPLACE %d %c\n", n, b[m - 1]);
            n --, m --;
            continue;
        }
        n --, m --;
    }
    return 0;
}