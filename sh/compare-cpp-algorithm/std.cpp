#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define M 600005
#define INF 10000000
#define RCL(a, b) memset(a, b, sizeof(a))

int n, d, a[M], dp[M], f[M];

int my_bound(int val)
{
    int left = 1, right = n, mid, ans;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(val > f[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}
int solve()
{
    int ans = 0, k;
    for(int i=1; i<=n; i++)
    {
        dp[i] = my_bound(a[i]);
        if(dp[i] > ans)
        {
            ans = dp[i];
        }

        k = i - d;
        if(k > 0 && f[dp[k]] > a[k])
        {
            f[dp[k]] = a[k];
        }
    }

    return ans;
}
int main()
{
    while(scanf("%d%d", &n, &d) != EOF)
    {
d--;        
for(int i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
            f[i] = INF;
        }
        int ans = solve();
        printf("%d\n", ans);
    }

    return 0;
}